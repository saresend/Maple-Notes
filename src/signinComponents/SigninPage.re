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
    ~display="flex",
    ~flexDirection="column",
    ~justifyContent="center",
    ~verticalAlign="super",
    ~alignItems="center",
    (),
  );

let signinTitleStyle =
  ReactDOMRe.Style.make(
    ~fontSize="30px",
    ~color="#939393",
    ~marginBottom="5px",
    (),
  );

let inputStyle =
  ReactDOMRe.Style.make(
    ~marginTop="20px",
    ~fontSize="17px",
    ~display="block",
    ~borderBottom="1px solid gray",
    ~width="200px",
    (),
  );
let buttonStyle =
  ReactDOMRe.Style.make(
    ~marginTop="20px",
    ~fontSize="17px",
    ~width="200px",
    ~color="#ffffff",
    ~outline="0px",
    ~border="0px",
    ~padding="8px",
    ~borderRadius="3px",
    ~backgroundColor="#1ae5b6",
    ~fontFamily="Aleo",
    (),
  );
let make = (~dispatch, _children) => {
  ...component,
  render: _self =>
    <div style=horizontalStyle>
      <div style=leftBarStyle>
        <div style=leftLoginBlockStyle>
          <i style=logoStyle className="fab fa-pagelines" />
          <p style=logoTitleStyle> {ReasonReact.string("Maple")} </p>
        </div>
      </div>
      <div style=rightBarStyle>
        <div style=rightLoginBlockStyle>
          <p style=signinTitleStyle> {ReasonReact.string("Sign In")} </p>
          <input style=inputStyle placeholder="Email" />
          <input style=inputStyle placeholder="Password" />
          <button
            style=buttonStyle
            className="hover"
            onClick={_data =>
              dispatch(Actions.SignInUserSuccessfully("asdfasdf"))
            }>
            {ReasonReact.string("Log In")}
          </button>
          <button
            className="hover"
            onClick={_data =>
              dispatch(Actions.SignInUserSuccessfully("asdfasdf"))
            }
            style=buttonStyle>
            {ReasonReact.string("Sign Up")}
          </button>
        </div>
      </div>
    </div>,
};