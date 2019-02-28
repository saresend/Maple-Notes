[@bs.module "rich-markdown-editor"]
external mapleEditor: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {
  defaultValue: option(string),
  placeholder: string,
  autoFocus: bool,
  readOnly: bool,
  onChange: (unit => string) => unit,
};

let editorStyle = ReactDOMRe.Style.make(~fontFamily="Open Sans", ());

let make =
    (
      ~defaultValue=?,
      ~placeholder,
      ~readOnly=false,
      ~onChange,
      ~autoFocus=true,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=mapleEditor,
    ~props=
      jsProps(~defaultValue, ~onChange, ~placeholder, ~autoFocus, ~readOnly),
    children,
  );