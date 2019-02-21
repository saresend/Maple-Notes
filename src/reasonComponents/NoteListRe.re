let component = ReasonReact.statelessComponent("NoteListRe");

let containerStyle =
  ReactDOMRe.Style.make(
    ~height="100vh",
    ~width="300px",
    ~backgroundColor="#fbfbfb",
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
    ~backgroundColor="#fbfbfb",
    (),
  );

let make = (~notes, children) => {
  ...component,
  render: _self => {
    <div style=containerStyle>
      <div style=horizontalContainer>
        <input
          onChange={data => Js.log(data)}
          style=searchBarStyle
          placeholder="Search"
        />
        <i className="far fa-edit hover" />
      </div>
      <NoteDescriptionViewRe note=false />
      <NoteDescriptionViewRe note=false />
      <NoteDescriptionViewRe note=false />
      <NoteDescriptionViewRe note=false />
    </div>;
  },
};