let component = ReasonReact.statelessComponent("NoteElementRe");

let unselectedTextStyle =
  ReactDOMRe.Style.make(
    ~color="#EEDBD5",
    ~margin="7px",
    ~marginLeft="15px",
    (),
  );

let selectedTextStyle =
  ReactDOMRe.Style.make(
    ~color="#5fcc82",
    ~margin="7px",
    ~marginLeft="15px",
    ~opacity="1.0",
    (),
  );

let countStyle =
  ReactDOMRe.Style.make(
    ~color="#5fcc82",
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

let editableTextStyle =
  ReactDOMRe.Style.make(
    ~color="#ffffff",
    ~margin="7px",
    ~marginLeft="15px",
    ~opacity="1",
    (),
  );
open Actions;
let make =
    (
      ~dispatch,
      ~info: SynthesizedFileTreeElement.synthesizedFileTreeElement,
      _children,
    ) => {
  ...component,
  render: _self => {
    let textStyle =
      info.noteElement.isSelected ? selectedTextStyle : unselectedTextStyle;

    let icon =
      switch (info.noteElement.noteType) {
      | Folder(color) =>
        let folderIconStyle =
          ReactDOMRe.Style.make(~fontSize="18px", ~color, ());
        <i style=folderIconStyle className="far fa-folder" />;
      | NoteBook => <i style=iconStyle className="far fa-file-alt" />
      | Starred => <i style=iconStyle className="far fa-bookmark" />
      | Trash => <i style=iconStyle className="far fa-trash-alt" />
      };
    let isFolder =
      switch (info.noteElement.noteType) {
      | Folder(_) => true
      | _ => false
      };
    let nameElement =
      if (info.noteElement.isEditable) {
        <input
          defaultValue={info.noteElement.title}
          style=editableTextStyle
          ref={input => {
            let potentialInput = Js.Nullable.toOption(input);
            switch (potentialInput) {
            | Some(_nonNullInput) =>
              %bs.raw
              {| input.focus()
              |}
            | None => ()
            };
          }}
          onChange={event => {
            let textValue = event->ReactEvent.Form.target##value;
            dispatch(
              Actions.UpdateBottomBarItem({
                ...info.noteElement,
                title: textValue,
              }),
            );
          }}
          onBlur={_event =>
            dispatch(
              Actions.UpdateBottomBarItem({
                ...info.noteElement,
                isEditable: false,
              }),
            )
          }
        />;
      } else {
        <p style=textStyle> {ReasonReact.string(info.noteElement.title)} </p>;
      };
    let internalItem =
      <div
        className="hover"
        onClick={_data => dispatch(SelectMenuBarItem(info.noteElement))}
        style=containerStyle>
        <div style=iconContainerStyle> icon nameElement </div>
        <p style=countStyle>
          {ReasonReact.string(Js.Int.toString(info.numNotes))}
        </p>
      </div>;
    if (isFolder) {
      <ContextMenuRe dispatch suffix="Folder" menuId={info.noteElement.id}>
        internalItem
      </ContextMenuRe>;
    } else {
      internalItem;
    };
  },
};