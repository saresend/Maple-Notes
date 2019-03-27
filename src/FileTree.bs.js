// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
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

var scrollStylePre = {
  maxHeight: "40vh",
  overflow: "auto"
};

var scrollStyle = ReactDOMRe.Style[/* unsafeAddProp */1](scrollStylePre, "scrollbar-color", "gray transparent");

function make(dispatch, topItems, bottomItems, width, opacity, _children) {
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
              var fileTreeStyle = {
                backgroundColor: "#1e2326",
                borderRight: "solid #898989 1px",
                height: "100vh",
                marginRight: "0px",
                padding: "20px",
                width: width
              };
              var optionStyle = {
                marginTop: "30px",
                opacity: opacity
              };
              var fadedStyle = {
                opacity: opacity
              };
              var folderStyle = {
                marginTop: "100px",
                overflow: "hidden",
                opacity: opacity
              };
              var topUIElements = topItems.map((function (uiElem) {
                      return ReasonReact.element(uiElem[/* noteElement */0][/* id */0], undefined, NoteElementRe$ReactTemplate.make(dispatch, uiElem, /* array */[]));
                    }));
              var bottomUIElements = bottomItems.map((function (uiElem) {
                      return ReasonReact.element(undefined, undefined, NoteElementRe$ReactTemplate.make(dispatch, uiElem, /* array */[]));
                    }));
              return React.createElement("div", {
                          style: fileTreeStyle
                        }, React.createElement("div", {
                              style: iconContainerStyle
                            }, React.createElement("i", {
                                  className: "fas fa-bars hover",
                                  style: iconStyle,
                                  onClick: (function (_data) {
                                      return Curry._1(dispatch, /* ToggleMenuBar */2);
                                    })
                                }), React.createElement("div", {
                                  style: fadedStyle,
                                  onClick: (function (_data) {
                                      return Curry._1(dispatch, /* SaveData */0);
                                    })
                                }, React.createElement("i", {
                                      className: "fas fa-save hover",
                                      style: iconStyle
                                    }))), React.createElement("div", {
                              style: optionStyle
                            }, topUIElements), ReasonReact.element(undefined, undefined, FolderviewRe$ReactTemplate.make(dispatch, folderStyle, /* array */[React.createElement("div", {
                                        style: scrollStyle
                                      }, bottomUIElements)])));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.dispatch, jsProps.topItems, jsProps.bottomItems, jsProps.width, jsProps.opacity, /* array */[]);
      }));

exports.component = component;
exports.fileTreeStyle = fileTreeStyle;
exports.titleStyle = titleStyle;
exports.iconStyle = iconStyle;
exports.iconContainerStyle = iconContainerStyle;
exports.topNoteStyle = topNoteStyle;
exports.folderStyle = folderStyle;
exports.scrollStylePre = scrollStylePre;
exports.scrollStyle = scrollStyle;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */
