let component = ReasonReact.statelessComponent("FileTree");

let fileTreeStyle =
  ReactDOMRe.Style.make(
    ~width="230px",
    ~marginRight="20px",
    ~padding="20px",
    ~backgroundColor="#1e2326",
    ~borderRight="solid #898989 1px",
    ~height="100vh",
    (),
  );

let titleStyle = ReactDOMRe.Style.make(~margin="5px", ());
let iconStyle = ReactDOMRe.Style.make(~color="#48d3f2", ~fontSize="20px", ());
let iconContainerStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="space-between",
    (),
  );

let topNoteStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="column",
    ~marginTop="30px",
    (),
  );

let folderStyle =
  ReactDOMRe.Style.make(~marginTop="100px", ~overflow="hidden", ());

open NoteUIElement;

let make = (~width: string, ~opacity: string, _children) => {
  ...component,
  render: _self => {
    let allNotes = {title: "All Notes", numNotes: 10, noteType: NoteBook};
    let starredNotes = {
      title: "Starred Notes",
      numNotes: 2,
      noteType: Starred,
    };
    let trashNotes = {title: "Trash", numNotes: 3, noteType: Trash};
    let fileTreeStyle =
      ReactDOMRe.Style.make(
        ~width,
        ~marginRight="20px",
        ~padding="20px",
        ~backgroundColor="#1e2326",
        ~borderRight="solid #898989 1px",
        ~height="100vh",
        (),
      );
    let fadedIconStyle =
      ReactDOMRe.Style.make(~color="#48d3f2", ~fontSize="20px", ~opacity, ());
    let optionStyle = ReactDOMRe.Style.make(~marginTop="30px", ~opacity, ());

    <div style=fileTreeStyle>
      <div style=iconContainerStyle>
        <i style=iconStyle className="fas fa-bars hover" />
        <i style=fadedIconStyle className="fas fa-ellipsis-h hover" />
      </div>
      <div style=optionStyle>
        <NoteElementRe info=allNotes />
        <NoteElementRe info=starredNotes />
        <NoteElementRe info=trashNotes />
      </div>
      <FolderviewRe style=folderStyle>
        <NoteElementRe info=allNotes />
        <NoteElementRe info=starredNotes />
        <NoteElementRe info=trashNotes />
      </FolderviewRe>
    </div>;
  },
};

[@bs.deriving abstract]
type jsProps = {
  opacity: string,
  width: string,
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~width=jsProps->widthGet, ~opacity=jsProps->opacityGet, [||])
  );