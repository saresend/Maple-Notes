type state = {
  email: string,
  password: string,
  didSubmit: bool,
};

type action =
  | EmailChange(string)
  | PasswordChange(string)
  | HitSubmit;

let component = ReasonReact.reducerComponent("SigninPage");

let produceID = (~app) => {
  let authObj = Firebase.App.auth(app);
  let currUser = Firebase.Auth.currentUser(authObj);

  switch (Js.Nullable.toOption(currUser)) {
  | Some(user) => Firebase.Auth.User.uid(user)
  | None => ""
  };
};

let dispatchDataLoadRequest = (~app, ~dispatch) => {
  let db = Firebase.App.database(app);
  Firebase.Database.Reference.once(
    Firebase.Database.ref(db, ~path=produceID(~app), ()),
    ~eventType="value",
    (),
  )
  |> Js.Promise.then_(data =>
       {
         Firebase.Database.DataSnapshot.val_(data);
       }
       |> (
         serializedState =>
           {
             dispatch(Actions.NewSerializedState(serializedState));
           }
           |> Js.Promise.resolve
       )
     )
  |> ignore;
  dispatch(Actions.SignInUserSuccessfully("asdfas"));
};

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

let errorStyle =
  ReactDOMRe.Style.make(~color="#868686", ~textAlign="center", ());

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

let make = (~app, ~dispatch, ~failureReason, _children) => {
  ...component,

  initialState: () => {email: "", password: "", didSubmit: false},

  reducer: (action, state) =>
    switch (action) {
    | HitSubmit => ReasonReact.Update({...state, didSubmit: true})
    | EmailChange((newEmail: string)) =>
      ReasonReact.Update({...state, email: newEmail})
    | PasswordChange((newPassword: string)) =>
      ReasonReact.Update({...state, password: newPassword})
    },

  render: self => {
    let errorUI =
      switch (failureReason) {
      | Some(message) =>
        <p style=errorStyle> {ReasonReact.string(message)} </p>
      | None => <div />
      };
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
          <input
            style=inputStyle
            onChange={_data => {
              let email: string = [%bs.raw {| _data.target.value |}];
              self.send(EmailChange(email));
            }}
            placeholder="Email"
          />
          <input
            style=inputStyle
            onChange={_data => {
              let password: string = [%bs.raw {| _data.target.value |}];
              self.send(PasswordChange(password));
            }}
            type_="password"
            placeholder="Password"
          />
          <button
            style=buttonStyle
            onClick={_data => {
              let authObj = Firebase.App.auth(app);
              let fbPromise =
                Firebase.Auth.signInWithEmailAndPassword(
                  authObj,
                  ~email=self.state.email,
                  ~password=self.state.password,
                );

              fbPromise
              |> Js.Promise.then_(_value =>
                   dispatchDataLoadRequest(~dispatch, ~app)
                   |> Js.Promise.resolve
                 )
              |> Js.Promise.catch(_err =>
                   {let message = [%bs.raw {|_err.message|}]
                    dispatch(Actions.SignInUserFailed(message))}
                   |> Js.Promise.resolve
                 )
              |> ignore;
            }}
            className="hover">
            {ReasonReact.string("Log In")}
          </button>
          <button
            className="hover"
            onClick={_data => {
              let authObj = Firebase.App.auth(app);
              let fbPromise =
                Firebase.Auth.createUserAndRetrieveDataWithEmailAndPassword(
                  authObj,
                  ~email=self.state.email,
                  ~password=self.state.password,
                );

              fbPromise
              |> Js.Promise.then_(_value =>
                   dispatchDataLoadRequest(~dispatch, ~app)
                   |> Js.Promise.resolve
                 )
              |> Js.Promise.catch(_err =>
                   {let message = [%bs.raw {|_err.message|}]
                    dispatch(Actions.SignInUserFailed(message))}
                   |> Js.Promise.resolve
                 )
              |> ignore;
            }}
            style=buttonStyle>
            {ReasonReact.string("Sign Up")}
          </button>
          errorUI
        </div>
      </div>
    </div>;
  },
};