[@bs.module "../reactComponents/ContextMenu.react"]
external contextMenuReact: ReasonReact.reactClass = "default";
[@bs.deriving abstract]
type jsProps = {menuId: string};
let make = (~menuId, children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=contextMenuReact,
    ~props=jsProps(~menuId),
    children,
  );
};