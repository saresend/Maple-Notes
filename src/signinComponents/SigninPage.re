let component = ReasonReact.statelessComponent("SigninPage");

let containerStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~justifyContent="center",
    ~alignItems="center",
    ~height="100vh",
    ~width="100vw",
    (),
  );

let innerSigninCardStyle =
  ReactDOMRe.Style.make(~boxShadow="5px 5px 5px #bbbbbb", ());

let make = _children => {
  ...component,
  render: _self =>
    <div style=containerStyle>
      <div style=innerSigninCardStyle>
        <p> {ReasonReact.string("Signin Page")} </p>
      </div>
    </div>,
};