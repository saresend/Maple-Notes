type state = {
  notes: array(Note.note),
  isLoaded: bool,
  menuBarOpen: bool,
  currentFilterElement: NoteUIElement.noteUIElement,
  topMenuItems: array(NoteUIElement.noteUIElement),
  bottomMenuItems: array(NoteUIElement.noteUIElement),
};

let appStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());
let editorContainerStyle = ReactDOMRe.Style.make(~padding="45px", ());
open Note;
let maple = ReasonReact.reducerComponent("Maple");
let uuidGen: unit => string = [%bs.raw
  {|
        function () {
          const uuidv4 = require('uuid/v4');
          return uuidv4();
        }|}
];
let initialTopItems: array(NoteUIElement.noteUIElement) = [|
  {
    id: uuidGen(),
    title: "All Notes",
    numNotes: 10,
    noteType: NoteBook,
    isSelected: true,
    filterFunction: (_element, _note) => true,
  },
  {
    id: uuidGen(),
    title: "Starred Notes",
    numNotes: 2,
    noteType: Starred,
    isSelected: false,
    filterFunction: (_element, note) => note.isStarred,
  },
  {
    id: uuidGen(),
    title: "Trash",
    numNotes: 3,
    noteType: Trash,
    isSelected: false,
    filterFunction: (_element, note) => note.isTrash,
  },
|];

let initialBottomItems: array(NoteUIElement.noteUIElement) = [|
  {
    id: uuidGen(),
    title: "Algorithms",
    numNotes: 10,
    noteType: Folder("#ffc857"),
    isSelected: false,
    filterFunction: (element, note) => note.folderID == element.id,
  },
  {
    id: uuidGen(),
    title: "Discrete Mathematics",
    numNotes: 2,
    noteType: Folder("#97efe9"),
    isSelected: false,
    filterFunction: (element, note) => note.folderID == element.id,
  },
  {
    id: uuidGen(),
    title: "Software Engineering",
    numNotes: 3,
    noteType: Folder("#6a0f49"),
    isSelected: false,
    filterFunction: (element, note) => note.folderID == element.id,
  },
|];
open Actions;
let make = _children => {
  ...maple,

  initialState: () => {
    notes: [||],
    isLoaded: false,
    menuBarOpen: true,
    currentFilterElement: initialTopItems[0],
    topMenuItems: initialTopItems,
    bottomMenuItems: initialBottomItems,
  },

  reducer: (action, state) => {
    switch (action) {
    | SelectMenuBarItem((element: NoteUIElement.noteUIElement)) =>
      let newTopMenuItems =
        Js.Array.map(
          (oldElement: NoteUIElement.noteUIElement) =>
            if (oldElement.id == element.id) {
              {...element, isSelected: true};
            } else {
              {...oldElement, isSelected: false};
            },
          state.topMenuItems,
        );
      let newBottomMenuItems =
        Js.Array.map(
          (oldElement: NoteUIElement.noteUIElement) =>
            if (oldElement.id == element.id) {
              {...element, isSelected: true};
            } else {
              {...oldElement, isSelected: false};
            },
          state.bottomMenuItems,
        );
      ReasonReact.Update({
        ...state,
        currentFilterElement: element,
        topMenuItems: newTopMenuItems,
        bottomMenuItems: newBottomMenuItems,
      });
    | SelectNote((note: Note.note)) =>
      let notes =
        Js.Array.map(
          (oldNote): Note.note =>
            if (oldNote.noteID == note.noteID) {
              {...note, isSelected: true};
            } else {
              {...oldNote, isSelected: false};
            },
          state.notes,
        );
      ReasonReact.Update({...state, notes});
    | EditNote((note: Note.note)) =>
      let notes =
        Js.Array.map(
          (oldNote): Note.note =>
            if (oldNote.noteID == note.noteID) {
              note;
            } else {
              oldNote;
            },
          state.notes,
        );
      ReasonReact.Update({...state, notes});
    | AddNewNote(noteID) =>
      let note: Note.note = {
        noteID,
        title: "New Note",
        body: "",
        timestamp: [%bs.raw {| Date.now() |}],
        isStarred: false,
        isSelected: false,
        isTrash: false,
        folderID: state.currentFilterElement.id,
      };
      Js.log(state.notes);
      ReasonReact.Update({
        ...state,
        notes: Js.Array.concat([|note|], state.notes),
      });
    | ToggleMenuBar =>
      ReasonReact.Update({...state, menuBarOpen: !state.menuBarOpen})
    };
  },

  render: self => {
    let filteredNotes =
      Js.Array.filter(
        self.state.currentFilterElement.filterFunction(
          self.state.currentFilterElement,
        ),
        self.state.notes,
      );
    <div style=appStyle>
      <ReactFiletree
        topItems={self.state.topMenuItems}
        bottomItems={self.state.bottomMenuItems}
        dispatch={self.send}
        isOpen={self.state.menuBarOpen}
      />
      <NoteListRe dispatch={self.send} notes=filteredNotes />
      <div style=editorContainerStyle>
        <Editor placeholder="Write Anything..." />
      </div>
    </div>;
  },
};