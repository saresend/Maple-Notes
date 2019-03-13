[@bs.module "../reactComponents/ContextMenu.react"]
external contextMenuReact: ReasonReact.reactClass = "default";
[@bs.deriving abstract]
type jsProps = {
  menuId: string,
  dispatch: Actions.action => unit,
  suffix: string,
};
let make = (~dispatch, ~menuId, ~suffix, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=contextMenuReact,
    ~props=jsProps(~menuId, ~dispatch, ~suffix),
    children,
  );
};