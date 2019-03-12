let component = ReasonReact.statelessComponent("NoteElementRe");

let unselectedTextStyle =
  ReactDOMRe.Style.make(
    ~color="#aaaaaa",
    ~margin="7px",
    ~marginLeft="15px",
    (),
  );

let selectedTextStyle =
  ReactDOMRe.Style.make(
    ~color="#279af1",
    ~margin="7px",
    ~marginLeft="15px",
    ~opacity="0.5",
    (),
  );

let countStyle =
  ReactDOMRe.Style.make(
    ~color="#48d3f2",
    ~margin="7px",
    ~marginRight="0px",
    ~opacity="1.0",
    (),
  );
let containerStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="space-between",
    (),
  );
let iconContainerStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~alignItems="center",
    (),
  );

let iconStyle = ReactDOMRe.Style.make(~fontSize="18px", ~color="#aaaaaa", ());
open Actions;
let make = (~dispatch, ~info: NoteUIElement.noteUIElement, _children) => {
  ...component,
  render: _self => {
    let textStyle = info.isSelected ? selectedTextStyle : unselectedTextStyle;

    let icon =
      switch (info.noteType) {
      | Folder(color) =>
        let folderIconStyle =
          ReactDOMRe.Style.make(~fontSize="18px", ~color, ());
        <i style=folderIconStyle className="far fa-folder" />;
      | NoteBook => <i style=iconStyle className="far fa-file-alt" />
      | Starred => <i style=iconStyle className="far fa-bookmark" />
      | Trash => <i style=iconStyle className="far fa-trash-alt" />
      };
    let isFolder =
      switch (info.noteType) {
      | Folder(color_) => true
      | _ => false
      };
    let internalItem =
      <div
        className="hover"
        onClick={_data => dispatch(SelectMenuBarItem(info))}
        style=containerStyle>
        <div style=iconContainerStyle>
          icon
          <p style=textStyle> {ReasonReact.string(info.title)} </p>
        </div>
        <p style=countStyle>
          {ReasonReact.string(Js.Int.toString(info.numNotes))}
        </p>
      </div>;
    if (isFolder) {
      <ContextMenuRe menuId={info.id}> internalItem </ContextMenuRe>;
    } else {
      internalItem;
    };
  },
};