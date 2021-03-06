let component = ReasonReact.statelessComponent("FileTree");

type action =
  | ToggleMenuBar;

let titleStyle = ReactDOMRe.Style.make(~margin="5px", ());
let iconStyle = ReactDOMRe.Style.make(~color="#5fcc82", ~fontSize="20px", ());
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
let scrollStylePre =
  ReactDOMRe.Style.make(~overflow="auto", ~maxHeight="40vh", ());

let scrollStyle =
  ReactDOMRe.Style.unsafeAddProp(
    scrollStylePre,
    "scrollbar-color",
    "gray transparent",
  );

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
        ~backgroundColor="rgb(35, 35, 35)",
        ~height="100vh",
        (),
      );
    let optionStyle = ReactDOMRe.Style.make(~marginTop="30px", ~opacity, ());
    let fadedStyle = ReactDOMRe.Style.make(~opacity, ());

    let folderStyle =
      ReactDOMRe.Style.make(
        ~marginTop="100px",
        ~overflow="hidden",
        ~opacity,
        (),
      );
    open SynthesizedFileTreeElement;
    let topUIElements =
      Js.Array.map(
        uiElem =>
          <NoteElementRe key={uiElem.noteElement.id} dispatch info=uiElem />,
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
        <div style=fadedStyle onClick={_data => dispatch(Actions.SaveData)}>
          <i style=iconStyle className="fas fa-save hover" />
        </div>
      </div>
      <div style=optionStyle> {ReasonReact.array(topUIElements)} </div>
      <FolderviewRe dispatch style=folderStyle>
        <div style=scrollStyle> {ReasonReact.array(bottomUIElements)} </div>
      </FolderviewRe>
    </div>;
  },
};

[@bs.deriving abstract]
type jsProps = {
  opacity: string,
  width: string,
  dispatch: ReactTemplate.Actions.action => unit,
  bottomItems: array(SynthesizedFileTreeElement.synthesizedFileTreeElement),
  topItems: array(SynthesizedFileTreeElement.synthesizedFileTreeElement),
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