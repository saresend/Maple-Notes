type state = {
  notes: DirItem.dirItem,
  current: Note.mapleNote,
  isLoaded: bool,
};

type action =
  | UpdateDirectory(DirItem.dirItem)
  | LoadedNotes(DirItem.dirItem)
  | SelectNote(Note.mapleNote);

let appStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());
let editorContainerStyle = ReactDOMRe.Style.make(~padding="20px", ());

let maple = ReasonReact.reducerComponent("Maple");
let make = _children => {
  ...maple,

  initialState: () => {
    notes: TopLevel([||]),
    current: {
      id: "asdf",
      title: "asdf",
      body: "asdf",
    },
    isLoaded: false,
  },

  reducer: (action, state) => {
    switch (action) {
    | SelectNote(note) => ReasonReact.Update({...state, current: note})
    | LoadedNotes(dir) => ReasonReact.Update({...state, notes: dir})
    | UpdateDirectory(dir) => ReasonReact.Update({...state, notes: dir})
    };
  },

  render: _self => {
    <div style=appStyle>
      <FileTree />
      <div style=editorContainerStyle>
        <Editor placeholder="Write Anything..." />
      </div>
    </div>;
  },
};