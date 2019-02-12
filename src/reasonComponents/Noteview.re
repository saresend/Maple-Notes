let component = ReasonReact.statelessComponent("Noteview");

let noteStyle =
  ReactDOMRe.Style.make(
    ~fontSize="20px",
    ~fontFamily="Aleo",
    ~color="#898989",
    ~opacity="1.0",
    ~backgroundColor="rgba(0,0,0,0)",
    ~outlineWidth="0px",
    ~borderWidth="0px",
    ~marginTop="5px",
    ~marginBottom="5px",
    (),
  );
let iconStyle =
  ReactDOMRe.Style.make(
    ~width="20px",
    ~height="20px",
    ~marginRight="10px",
    (),
  );

let containerStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~alignItems="center",
    (),
  );

let make = (~note: Note.note, _children) => {
  ...component,
  render: _self => {
    <div style=containerStyle>
      <img
        style=iconStyle
        src="https://img.icons8.com/ios/50/000000/paper.png"
      />
      <button style=noteStyle> {ReasonReact.string(note.title)} </button>
    </div>;
  },
};

[@bs.deriving abstract]
type jsProps = {note: Note.note};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~note=jsProps->noteGet, [||])
  );