let component = ReasonReact.statelessComponent("FolderView");

let titleStyle =
  ReactDOMRe.Style.make(~color="#cccccc", ~fontSize="20px", ());

let scrollStyle =
  ReactDOMRe.Style.make(~overflowY="hidden", ~height="50vh", ());
let iconStyle = ReactDOMRe.Style.make(~fontSize="20px", ~color="#cccccc", ());

let titleBarStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~alignItems="center",
    ~justifyContent="space-between",
    (),
  );

open Actions;
let make = (~dispatch, ~style, children) => {
  ...component,
  render: _self => {
    <div style>
      <div style=titleBarStyle>
        <p style=titleStyle> {ReasonReact.string("My Storage")} </p>
        <i
          onClick={_data => dispatch(AddNewBottomBarItem)}
          style=iconStyle
          className="fas fa-plus hover"
        />
      </div>
      <div style=scrollStyle> ...children </div>
    </div>;
  },
};