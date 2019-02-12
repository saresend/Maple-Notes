[@bs.module "../reactComponents/Folderview.react.js"]
external folderView: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {
  title: string,
  folderItems: array(DirItem.dirItem),
};

let make = (~title: string, ~folderItems: array(DirItem.dirItem), children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=folderView,
    ~props=jsProps(~title, ~folderItems),
    children,
  );