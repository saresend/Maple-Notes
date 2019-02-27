[@bs.deriving abstract]
type jsProps = {
  isOpen: bool,
  dispatch: Actions.action => unit,
  topItems: array(NoteUIElement.noteUIElement),
  bottomItems: array(NoteUIElement.noteUIElement),
};

[@bs.module "../reactComponents/FileTreeReact.react.js"]
external reactFileTree: ReasonReact.reactClass = "default";

let make = (~dispatch, ~isOpen, ~topItems, ~bottomItems, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=reactFileTree,
    ~props=jsProps(~isOpen, ~dispatch, ~topItems, ~bottomItems),
    children,
  );