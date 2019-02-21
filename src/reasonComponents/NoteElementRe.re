let component = ReasonReact.statelessComponent("NoteElementRe");

let textStyle =
  ReactDOMRe.Style.make(
    ~color="#aaaaaa",
    ~margin="7px",
    ~marginLeft="15px",
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
open AnimationOptions;
let make = (~info: NoteUIElement.noteUIElement, _children) => {
  ...component,
  render: _self => {
    let fromObj: animationOptions = {pub width = 10; pub opacity = 1.0};

    let toObj: animationOptions = {pub width = 100; pub opacity = 0.5};

    let icon =
      switch (info.noteType) {
      | Folder => <i style=iconStyle className="far fa-folder" />
      | NoteBook => <i style=iconStyle className="far fa-file-alt" />
      | Starred => <i style=iconStyle className="far fa-bookmark" />
      | Trash => <i style=iconStyle className="far fa-trash-alt" />
      };
    <div className="hover" style=containerStyle>
      <div style=iconContainerStyle>
        icon
        <p style=textStyle> {ReasonReact.string(info.title)} </p>
      </div>
      <p style=countStyle>
        {ReasonReact.string(Js.Int.toString(info.numNotes))}
      </p>
    </div>;
  },
};