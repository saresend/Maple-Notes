// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var ReasonReact = require("reason-react/src/ReasonReact.js");
var RichMarkdownEditor = require("rich-markdown-editor");

var editorStyle = {
  fontFamily: "Aleo",
  overflow: "scroll"
};

function make(defaultValue, placeholder, $staropt$star, onChange, $staropt$star$1, children) {
  var readOnly = $staropt$star !== undefined ? $staropt$star : false;
  var autoFocus = $staropt$star$1 !== undefined ? $staropt$star$1 : true;
  return ReasonReact.wrapJsForReason(RichMarkdownEditor.default, {
              defaultValue: defaultValue,
              placeholder: placeholder,
              autoFocus: autoFocus,
              readOnly: readOnly,
              onChange: onChange
            }, children);
}

exports.editorStyle = editorStyle;
exports.make = make;
/* ReasonReact Not a pure module */
