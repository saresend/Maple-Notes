[@bs.module "../reactComponents/FileTreeReact.react.js"]
external reactFileTree: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {isOpen: bool};

let make = (~isOpen, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=reactFileTree,
    ~props=jsProps(~isOpen),
    children,
  );