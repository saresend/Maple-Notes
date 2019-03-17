// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ContextMenuRe$ReactTemplate = require("../reasonBindings/ContextMenuRe.bs.js");

var component = ReasonReact.statelessComponent("NoteElementRe");

var unselectedTextStyle = {
  color: "#aaaaaa",
  margin: "7px",
  marginLeft: "15px"
};

var selectedTextStyle = {
  color: "#279af1",
  margin: "7px",
  marginLeft: "15px",
  opacity: "0.5"
};

var countStyle = {
  color: "#48d3f2",
  margin: "7px",
  marginRight: "0px",
  opacity: "1.0"
};

var containerStyle = {
  display: "flex",
  flexDirection: "row",
  justifyContent: "space-between"
};

var iconContainerStyle = {
  display: "flex",
  alignItems: "center",
  flexDirection: "row"
};

var iconStyle = {
  color: "#aaaaaa",
  fontSize: "18px"
};

var editableTextStyle = {
  color: "#ffffff",
  margin: "7px",
  marginLeft: "15px",
  opacity: "1"
};

function make(dispatch, info, _children) {
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
              var match = info[/* noteElement */0][/* isSelected */4];
              var textStyle = match ? selectedTextStyle : unselectedTextStyle;
              var match$1 = info[/* noteElement */0][/* noteType */3];
              var icon;
              if (typeof match$1 === "number") {
                switch (match$1) {
                  case 0 : 
                      icon = React.createElement("i", {
                            className: "far fa-file-alt",
                            style: iconStyle
                          });
                      break;
                  case 1 : 
                      icon = React.createElement("i", {
                            className: "far fa-trash-alt",
                            style: iconStyle
                          });
                      break;
                  case 2 : 
                      icon = React.createElement("i", {
                            className: "far fa-bookmark",
                            style: iconStyle
                          });
                      break;
                  
                }
              } else {
                var folderIconStyle = {
                  color: match$1[0],
                  fontSize: "18px"
                };
                icon = React.createElement("i", {
                      className: "far fa-folder",
                      style: folderIconStyle
                    });
              }
              var match$2 = info[/* noteElement */0][/* noteType */3];
              var isFolder = typeof match$2 === "number" ? false : true;
              var nameElement = info[/* noteElement */0][/* isEditable */2] ? React.createElement("input", {
                      ref: (function (input) {
                          if (input == null) {
                            return /* () */0;
                          } else {
                            return ( input.focus()
              );
                          }
                        }),
                      defaultValue: info[/* noteElement */0][/* title */1],
                      style: editableTextStyle,
                      onBlur: (function (_event) {
                          var init = info[/* noteElement */0];
                          return Curry._1(dispatch, /* UpdateBottomBarItem */Block.__(1, [/* record */[
                                          /* id */init[/* id */0],
                                          /* title */init[/* title */1],
                                          /* isEditable */false,
                                          /* noteType */init[/* noteType */3],
                                          /* isSelected */init[/* isSelected */4],
                                          /* filterFunction */init[/* filterFunction */5]
                                        ]]));
                        }),
                      onChange: (function ($$event) {
                          var textValue = $$event.target.value;
                          var init = info[/* noteElement */0];
                          return Curry._1(dispatch, /* UpdateBottomBarItem */Block.__(1, [/* record */[
                                          /* id */init[/* id */0],
                                          /* title */textValue,
                                          /* isEditable */init[/* isEditable */2],
                                          /* noteType */init[/* noteType */3],
                                          /* isSelected */init[/* isSelected */4],
                                          /* filterFunction */init[/* filterFunction */5]
                                        ]]));
                        })
                    }) : React.createElement("p", {
                      style: textStyle
                    }, info[/* noteElement */0][/* title */1]);
              var internalItem = React.createElement("div", {
                    className: "hover",
                    style: containerStyle,
                    onClick: (function (_data) {
                        return Curry._1(dispatch, /* SelectMenuBarItem */Block.__(10, [info[/* noteElement */0]]));
                      })
                  }, React.createElement("div", {
                        style: iconContainerStyle
                      }, icon, nameElement), React.createElement("p", {
                        style: countStyle
                      }, info[/* numNotes */1].toString()));
              if (isFolder) {
                return ReasonReact.element(undefined, undefined, ContextMenuRe$ReactTemplate.make(dispatch, info[/* noteElement */0][/* id */0], "Folder", /* array */[internalItem]));
              } else {
                return internalItem;
              }
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.unselectedTextStyle = unselectedTextStyle;
exports.selectedTextStyle = selectedTextStyle;
exports.countStyle = countStyle;
exports.containerStyle = containerStyle;
exports.iconContainerStyle = iconContainerStyle;
exports.iconStyle = iconStyle;
exports.editableTextStyle = editableTextStyle;
exports.make = make;
/* component Not a pure module */
