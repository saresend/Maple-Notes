type state = {
  notes: array(Note.note),
  isLoaded: bool,
  menuBarOpen: bool,
};

let appStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());
let editorContainerStyle = ReactDOMRe.Style.make(~padding="45px", ());

let maple = ReasonReact.reducerComponent("Maple");
let make = _children => {
  ...maple,

  initialState: () => {notes: [||], isLoaded: false, menuBarOpen: true},

  reducer: (action, state) => {
    switch (action) {
    | AddNewNote(noteID) =>
      let note: Note.note = {
        id: noteID,
        title: "New Note",
        body: "",
        timestamp: [%bs.raw {| Date.now() |}],
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
    <div style=appStyle>
      <ReactFiletree dispatch={self.send} isOpen={self.state.menuBarOpen} />
      <NoteListRe dispatch={self.send} notes={self.state.notes} />
      <div style=editorContainerStyle>
        <Editor placeholder="Write Anything..." />
      </div>
    </div>;
  },
};