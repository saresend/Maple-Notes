let component = ReasonReact.statelessComponent("NoteDescriptionViewRe");

let containerStyle =
  ReactDOMRe.Style.make(
    ~margin="5px",
    ~padding="5px",
    ~borderBottom="1px solid #dddddd",
    (),
  );

let titleStyle =
  ReactDOMRe.Style.make(
    ~fontSize="17px",
    ~color="#999999",
    ~margin="10px",
    (),
  );

let iconStyle =
  ReactDOMRe.Style.make(
    ~fontSize="16px",
    ~color="#999999",
    ~marginRight="10px",
    (),
  );

let horizontalStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="flex-start",
    ~alignItems="center",
    (),
  );

let timeStampStyle =
  ReactDOMRe.Style.make(
    ~fontSize="13px",
    ~color="#aaaaaa",
    ~margin="4px",
    (),
  );

let make = (~note, children) => {
  ...component,
  render: _self => {
    <div style=containerStyle>
      <div style=horizontalStyle>
        <i style=iconStyle className="far fa-file-alt" />
        <p style=titleStyle> {ReasonReact.string("Sample Title")} </p>
      </div>
      <p style=timeStampStyle> {ReasonReact.string("Jun 10th, 2019")} </p>
    </div>;
  },
};