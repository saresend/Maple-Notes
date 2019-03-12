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

type action =
  | ToggleMenuBar;

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

let make =
    (
      ~dispatch,
      ~topItems,
      ~bottomItems,
      ~width: string,
      ~opacity: string,
      _children,
    ) => {
  ...component,
  render: _self => {
    let fileTreeStyle =
      ReactDOMRe.Style.make(
        ~width,
        ~marginRight="0px",
        ~padding="20px",
        ~backgroundColor="#1e2326",
        ~borderRight="solid #898989 1px",
        ~height="100vh",
        (),
      );
    let fadedIconStyle =
      ReactDOMRe.Style.make(~color="#48d3f2", ~fontSize="20px", ~opacity, ());
    let optionStyle = ReactDOMRe.Style.make(~marginTop="30px", ~opacity, ());

    let folderStyle =
      ReactDOMRe.Style.make(
        ~marginTop="100px",
        ~overflow="hidden",
        ~opacity,
        (),
      );

    let topUIElements =
      Js.Array.map(
        uiElem => <NoteElementRe dispatch info=uiElem />,
        topItems,
      );
    let bottomUIElements =
      Js.Array.map(
        uiElem => <NoteElementRe dispatch info=uiElem />,
        bottomItems,
      );

    <div style=fileTreeStyle>
      <div style=iconContainerStyle>
        <i
          style=iconStyle
          onClick={_data => dispatch(ToggleMenuBar)}
          className="fas fa-bars hover"
        />
        <i style=fadedIconStyle className="fas fa-ellipsis-h hover" />
      </div>
      <div style=optionStyle> {ReasonReact.array(topUIElements)} </div>
      <FolderviewRe dispatch style=folderStyle>
        {ReasonReact.array(bottomUIElements)}
      </FolderviewRe>
    </div>;
  },
};

[@bs.deriving abstract]
type jsProps = {
  opacity: string,
  width: string,
  dispatch: ReactTemplate.Actions.action => unit,
  bottomItems: array(NoteUIElement.noteUIElement),
  topItems: array(NoteUIElement.noteUIElement),
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~width=jsProps->widthGet,
      ~opacity=jsProps->opacityGet,
      ~dispatch=jsProps->dispatchGet,
      ~topItems=jsProps->topItemsGet,
      ~bottomItems=jsProps->bottomItemsGet,
      [||],
    )
  );