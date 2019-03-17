let component = ReasonReact.statelessComponent("SigninPage");

let horizontalStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());

let leftBarStyle =
  ReactDOMRe.Style.make(
    ~width="40vw",
    ~height="100vh",
    ~backgroundColor="#ff9d84",
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="flex-end",
    ~alignItems="center",
    (),
  );

let rightBarStyle =
  ReactDOMRe.Style.make(
    ~width="60vw",
    ~height="100vh",
    ~backgroundColor="#ffffff",
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="flex-start",
    ~alignItems="center",
    (),
  );

let leftLoginBlockStyle =
  ReactDOMRe.Style.make(
    ~boxShadow=
      "0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19)",
    ~height="80vh",
    ~width="30vw",
    ~backgroundColor="#ff9d84",
    ~verticalAlign="super",
    ~display="flex",
    ~flexDirection="column",
    ~alignItems="center",
    ~justifyContent="center",
    (),
  );

let logoTitleStyle =
  ReactDOMRe.Style.make(
    ~color="#ffffff",
    ~fontSize="30px",
    ~margin="5px",
    (),
  );

let logoStyle = ReactDOMRe.Style.make(~color="#ffffff", ~fontSize="50px", ());

let rightLoginBlockStyle =
  ReactDOMRe.Style.make(
    ~boxShadow=
      "0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19)",
    ~height="80vh",
    ~width="50vw",
    ~backgroundColor="#ffffff",
    ~verticalAlign="super",
    (),
  );

let make = _children => {
  ...component,
  render: _self =>
    <div style=horizontalStyle>
      <div style=leftBarStyle>
        <div style=leftLoginBlockStyle>
          <i style=logoStyle className="fab fa-pagelines" />
          <p style=logoTitleStyle> {ReasonReact.string("Maple")} </p>
        </div>
      </div>
      <div style=rightBarStyle> <div style=rightLoginBlockStyle /> </div>
    </div>,
};