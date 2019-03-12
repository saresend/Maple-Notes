[@bs.module "../reactComponents/ContextMenu.react"]
external contextMenuReact: ReasonReact.reactClass = "default";

let make = children => {
  ReasonReact.wrapJsForReason(
    ~reactClass=contextMenuReact,
    ~props=Js.Obj.empty(),
    children,
  );
};