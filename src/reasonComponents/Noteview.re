let component = ReasonReact.statelessComponent("Noteview");

let make = (~note, _children) => {
  ...component,
  render: _self => <p> {ReasonReact.string("This is a note")} </p>,
};