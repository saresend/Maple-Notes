[@bs.module "../reactComponents/FileTreeReact.react.js"]
external reactFileTree: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {
  isOpen: bool,
  dispatch: Actions.action => unit,
};

let make = (~dispatch, ~isOpen, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=reactFileTree,
    ~props=jsProps(~isOpen, ~dispatch),
    children,
  );