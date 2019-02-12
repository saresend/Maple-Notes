type state = {
  notes: array(DirItem.dirItem),
  current: Note.note,
  isLoaded: bool,
};

type action =
  | SelectNote(Note.note);

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
  },

  reducer: (action, state) => {
    switch (action) {
    | SelectNote(note) => ReasonReact.Update({...state, current: note})
    };
  },

  render: self => {
    <div style=appStyle>
      <FileTree files={self.state.notes} />
      <div style=editorContainerStyle>
        <Editor placeholder="Write Anything..." />
      </div>
    </div>;
  },
};