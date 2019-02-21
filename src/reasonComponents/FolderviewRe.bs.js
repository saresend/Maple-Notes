// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("FolderView");

var titleStyle = {
  color: "#cccccc",
  fontSize: "20px"
};

var scrollStyle = {
  height: "50vh",
  overflowY: "hidden"
};

var iconStyle = {
  color: "#cccccc",
  fontSize: "20px"
};

var titleBarStyle = {
  display: "flex",
  alignItems: "center",
  flexDirection: "row",
  justifyContent: "space-between"
};

function make(style, children) {
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
              return React.createElement("div", {
                          style: style
                        }, React.createElement("div", {
                              style: titleBarStyle
                            }, React.createElement("p", {
                                  style: titleStyle
                                }, "My Storage"), React.createElement("i", {
                                  className: "fas fa-plus hover",
                                  style: iconStyle
                                })), ReactDOMRe.createElementVariadic("div", {
                              style: scrollStyle
                            }, children));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.titleStyle = titleStyle;
exports.scrollStyle = scrollStyle;
exports.iconStyle = iconStyle;
exports.titleBarStyle = titleBarStyle;
exports.make = make;
/* component Not a pure module */
