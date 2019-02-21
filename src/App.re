type state = {
  notes: array(DirItem.dirItem),
  current: Note.note,
  isLoaded: bool,
  menuBarOpen: bool,
};

let appStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());
let editorContainerStyle = ReactDOMRe.Style.make(~padding="45px", ());

let sampleData = [|
  DirItem.Note({
    id: "sadasdf",
    title: "Sample Note 1",
    body: "# Hello World",
  }),
  DirItem.Folder(
    "Sample Folder",
    [|
      DirItem.Note({id: "asdf", title: "Sample Note", body: "# Hi There"}),
      DirItem.Folder("Another Sample Folder", [||]),
    |],
  ),
|];

let maple = ReasonReact.reducerComponent("Maple");
let make = _children => {
  ...maple,

  initialState: () => {
    notes: sampleData,
    current: {
      id: "asdf",
      title: "asdf",
      body: "asdf",
    },
    isLoaded: false,
    menuBarOpen: true,
  },

  reducer: (action, state) => {
    switch (action) {
    | ToggleMenuBar =>
      ReasonReact.Update({...state, menuBarOpen: !state.menuBarOpen})
    };
  },

  render: self => {
    <div style=appStyle>
      <ReactFiletree dispatch={self.send} isOpen={self.state.menuBarOpen} />
      <NoteListRe notes=false />
      <div style=editorContainerStyle>
        <Editor placeholder="Write Anything..." />
      </div>
    </div>;
  },
};