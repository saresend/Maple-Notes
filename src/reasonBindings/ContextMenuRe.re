[@bs.module "../reactComponents/ContextMenu.react"]
external contextMenuReact: ReasonReact.reactClass = "default";
[@bs.deriving abstract]
type jsProps = {
  menuId: string,
  dispatch: Actions.action => unit,
};
let make = (~dispatch, ~menuId, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=contextMenuReact,
    ~props=jsProps(~menuId, ~dispatch),
    children,
  );
};