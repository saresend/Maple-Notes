type state = {
  notes: array(Note.note),
  currentNote: option(Note.note),
  isLoaded: bool,
  menuBarOpen: bool,
  currentFilterElement: NoteUIElement.noteUIElement,
  searchFilter: Note.note => bool,
  topMenuItems: array(NoteUIElement.noteUIElement),
  bottomMenuItems: array(NoteUIElement.noteUIElement),
};

let appStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());
let editorContainerStyle = ReactDOMRe.Style.make(~padding="45px", ());
open Note;
let maple = ReasonReact.reducerComponent("Maple");
let uuidGen: int => string = [%bs.raw
  {|
    function (val) {
          const uuidv4 = require('uuid/v4');
          return uuidv4();
    }|}
];
let initialTopItems: array(NoteUIElement.noteUIElement) = [|
  {
    id: uuidGen(10),
    title: "All Notes",
    numNotes: 10,
    noteType: NoteBook,
    isSelected: true,
    filterFunction: (_element, note) => !note.isTrash,
  },
  {
    id: uuidGen(10),
    title: "Starred Notes",
    numNotes: 2,
    noteType: Starred,
    isSelected: false,
    filterFunction: (_element, note) => note.isStarred,
  },
  {
    id: uuidGen(10),
    title: "Trash",
    numNotes: 3,
    noteType: Trash,
    isSelected: false,
    filterFunction: (_element, note) => note.isTrash,
  },
|];

let initialBottomItems: array(NoteUIElement.noteUIElement) = [||];
open Actions;
let make = _children => {
  ...maple,

  initialState: () => {
    notes: [||],
    isLoaded: false,
    menuBarOpen: true,
    currentNote: None,
    currentFilterElement: initialTopItems[0],
    searchFilter: _note => true,
    topMenuItems: initialTopItems,
    bottomMenuItems: initialBottomItems,
  },

  reducer: (action, state) => {
    switch (action) {
    | DeleteBottomBarItem(menuItemId) =>
      let newBottomItems =
        Js.Array.filter(
          (bottomBarItem: NoteUIElement.noteUIElement) =>
            bottomBarItem.id != menuItemId,
          state.bottomMenuItems,
        );
      ReasonReact.Update({...state, bottomMenuItems: newBottomItems});
    | UpdateSearchFunction(searchString) =>
      if (searchString == "") {
        ReasonReact.Update({...state, searchFilter: _note => true});
      } else {
        ReasonReact.Update({
          ...state,
          searchFilter: _note => {
            true;
                // note.body.contains(searchString) || note.title.contains(searchString);
          },
        });
      }
    | AddNewBottomBarItem =>
      let newBottomItem: NoteUIElement.noteUIElement = {
        id: uuidGen(10),
        title: "New Folder",
        numNotes: 0,
        noteType: Folder(Utils.generateColor()),
        isSelected: false,
        filterFunction: (element, note) => note.folderID == element.id,
      };
      let newBottomItems =
        Js.Array.concat([|newBottomItem|], state.bottomMenuItems);
      ReasonReact.Update({...state, bottomMenuItems: newBottomItems});
    | TypeCurrentNote(inside) =>
      switch (state.currentNote) {
      | Some(currNote) =>
        let newNote = {...currNote, body: inside};
        ReasonReact.Update({...state, currentNote: Some(newNote)});
      | None => ReasonReact.Update({...state, currentNote: None})
      }
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
              switch (state.currentNote) {
              | Some(currNote) =>
                if (currNote.noteID == oldNote.noteID) {
                  {...currNote, isSelected: false};
                } else {
                  {...oldNote, isSelected: false};
                }
              | None => {...oldNote, isSelected: false}
              };
            },
          state.notes,
        );
      ReasonReact.Update({...state, notes, currentNote: Some(note)});
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
      ReasonReact.Update({...state, notes, currentNote: Some(note)});
    | AddNewNote(_noteID) =>
      let noteID2 = uuidGen(20);
      let note: Note.note = {
        noteID: noteID2,
        title: "New Note",
        body: "",
        timestamp: [%bs.raw {| Date.now() |}],
        isStarred: false,
        isSelected: false,
        isTrash: false,
        folderID: state.currentFilterElement.id,
      };
      ReasonReact.Update({
        ...state,
        notes: Js.Array.concat([|note|], state.notes),
      });
    | ToggleMenuBar =>
      ReasonReact.Update({...state, menuBarOpen: !state.menuBarOpen})
    };
  },

  render: self => {
    let updateFunction = _value => {
      let bodyText = [%bs.raw {| _value() |}];
      self.send(TypeCurrentNote(bodyText));
    };
    let editorView =
      switch (self.state.currentNote) {
      | Some(note) =>
        <div style=editorContainerStyle>
          <Editor
            key={note.noteID}
            onChange=updateFunction
            defaultValue={note.body}
            autoFocus=true
            placeholder="Write Anything..."
          />
        </div>
      | None => <div />
      };
    let filteredNotes =
      Js.Array.filter(
        self.state.currentFilterElement.filterFunction(
          self.state.currentFilterElement,
        ),
        self.state.notes,
      );
    let searchFilteredNotes =
      Js.Array.filter(self.state.searchFilter, filteredNotes);
    <div style=appStyle>
      <ReactFiletree
        topItems={self.state.topMenuItems}
        bottomItems={self.state.bottomMenuItems}
        dispatch={self.send}
        isOpen={self.state.menuBarOpen}
      />
      <NoteListRe dispatch={self.send} notes=searchFilteredNotes />
      editorView
    </div>;
  },
};