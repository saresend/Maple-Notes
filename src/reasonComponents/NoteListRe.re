let component = ReasonReact.statelessComponent("NoteListRe");

let containerStyle =
  ReactDOMRe.Style.make(
    ~height="100vh",
    ~width="300px",
    ~backgroundColor="#ffffff",
    (),
  );

let horizontalContainer =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="space-between",
    ~alignItems="center",
    ~padding="20px",
    (),
  );
let searchBarStyle =
  ReactDOMRe.Style.make(
    ~fontSize="20px",
    ~fontFamily="Aleo",
    ~color="black",
    ~outline="0px",
    ~borderWidth="0px",
    ~backgroundColor="#ffffff",
    (),
  );

let scrollStylePre =
  ReactDOMRe.Style.make(~overflow="auto", ~maxHeight="90vh", ());

let scrollStyle =
  ReactDOMRe.Style.unsafeAddProp(
    scrollStylePre,
    "scrollbar-color",
    "#aaaaaa transparent",
  );

let make = (~dispatch, ~notes: array(Note.note), _children) => {
  ...component,
  render: _self => {
    let uuidGen: unit => string = [%bs.raw
      {|
        function () {
          const uuidv4 = require('uuid/v4');
          return uuidv4();
        }|}
    ];
    open Note;
    let noteUi =
      Js.Array.map(
        note => <NoteDescriptionViewRe key={note.noteID} note dispatch />,
        notes,
      );
    <div style=containerStyle>
      <div style=horizontalContainer>
        <input
          onChange={_data => {
            let searchString: string = [%bs.raw {| _data.target.value |}];
            dispatch(Actions.UpdateSearchFunction(searchString));
          }}
          style=searchBarStyle
          placeholder="Search"
        />
        <i
          className="far fa-edit hover"
          onClick={_data => {
            let uuid = uuidGen();
            dispatch(Actions.AddNewNote(uuid));
          }}
        />
      </div>
      <div style=scrollStyle> {ReasonReact.array(noteUi)} </div>
    </div>;
  },
};