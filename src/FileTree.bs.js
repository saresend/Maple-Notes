// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var FolderviewRe$ReactTemplate = require("./reasonComponents/FolderviewRe.bs.js");
var NoteElementRe$ReactTemplate = require("./reasonComponents/NoteElementRe.bs.js");

var component = ReasonReact.statelessComponent("FileTree");

var fileTreeStyle = {
  backgroundColor: "#1e2326",
  borderRight: "solid #898989 1px",
  height: "100vh",
  marginRight: "20px",
  padding: "20px",
  width: "230px"
};

var titleStyle = {
  margin: "5px"
};

var iconStyle = {
  color: "#48d3f2",
  fontSize: "20px"
};

var iconContainerStyle = {
  display: "flex",
  flexDirection: "row",
  justifyContent: "space-between"
};

var topNoteStyle = {
  display: "flex",
  marginTop: "30px",
  flexDirection: "column"
};

var folderStyle = {
  marginTop: "100px",
  overflow: "hidden"
};

function make(width, opacity, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              var allNotes = /* record */[
                /* title */"All Notes",
                /* numNotes */10,
                /* noteType : NoteBook */1
              ];
              var starredNotes = /* record */[
                /* title */"Starred Notes",
                /* numNotes */2,
                /* noteType : Starred */3
              ];
              var trashNotes = /* record */[
                /* title */"Trash",
                /* numNotes */3,
                /* noteType : Trash */2
              ];
              var fileTreeStyle = {
                backgroundColor: "#1e2326",
                borderRight: "solid #898989 1px",
                height: "100vh",
                marginRight: "20px",
                padding: "20px",
                width: width
              };
              var fadedIconStyle = {
                color: "#48d3f2",
                fontSize: "20px",
                opacity: opacity
              };
              var optionStyle = {
                marginTop: "30px",
                opacity: opacity
              };
              return React.createElement("div", {
                          style: fileTreeStyle
                        }, React.createElement("div", {
                              style: iconContainerStyle
                            }, React.createElement("i", {
                                  className: "fas fa-bars hover",
                                  style: iconStyle
                                }), React.createElement("i", {
                                  className: "fas fa-ellipsis-h hover",
                                  style: fadedIconStyle
                                })), React.createElement("div", {
                              style: optionStyle
                            }, ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(allNotes, /* array */[])), ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(starredNotes, /* array */[])), ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(trashNotes, /* array */[]))), ReasonReact.element(undefined, undefined, FolderviewRe$ReactTemplate.make(folderStyle, /* array */[
                                  ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(allNotes, /* array */[])),
                                  ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(starredNotes, /* array */[])),
                                  ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(trashNotes, /* array */[]))
                                ])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.width, jsProps.opacity, /* array */[]);
      }));

exports.component = component;
exports.fileTreeStyle = fileTreeStyle;
exports.titleStyle = titleStyle;
exports.iconStyle = iconStyle;
exports.iconContainerStyle = iconContainerStyle;
exports.topNoteStyle = topNoteStyle;
exports.folderStyle = folderStyle;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
