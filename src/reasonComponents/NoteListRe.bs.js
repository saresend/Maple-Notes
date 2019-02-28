// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var NoteDescriptionViewRe$ReactTemplate = require("./NoteDescriptionViewRe.bs.js");

var component = ReasonReact.statelessComponent("NoteListRe");

var containerStyle = {
  backgroundColor: "#ffffff",
  height: "100vh",
  width: "300px"
};

var horizontalContainer = {
  display: "flex",
  padding: "20px",
  alignItems: "center",
  flexDirection: "row",
  justifyContent: "space-between"
};

var searchBarStyle = {
  backgroundColor: "#ffffff",
  borderWidth: "0px",
  color: "black",
  fontFamily: "Aleo",
  fontSize: "20px",
  outline: "0px"
};

function make(dispatch, notes, _children) {
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
              var uuidGen = (
        function () {
          const uuidv4 = require('uuid/v4');
          return uuidv4();
        });
              var noteUi = notes.map((function (note) {
                      return ReasonReact.element(undefined, undefined, NoteDescriptionViewRe$ReactTemplate.make(dispatch, note, /* array */[]));
                    }));
              return React.createElement("div", {
                          style: containerStyle
                        }, React.createElement("div", {
                              style: horizontalContainer
                            }, React.createElement("input", {
                                  style: searchBarStyle,
                                  placeholder: "Search",
                                  onChange: (function (data) {
                                      console.log(data);
                                      return /* () */0;
                                    })
                                }), React.createElement("i", {
                                  className: "far fa-edit hover",
                                  onClick: (function (_data) {
                                      var uuid = Curry._1(uuidGen, /* () */0);
                                      return Curry._1(dispatch, /* AddNewNote */Block.__(3, [uuid]));
                                    })
                                })), noteUi);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.containerStyle = containerStyle;
exports.horizontalContainer = horizontalContainer;
exports.searchBarStyle = searchBarStyle;
exports.make = make;
/* component Not a pure module */
