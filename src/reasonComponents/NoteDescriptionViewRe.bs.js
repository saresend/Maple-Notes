// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("NoteDescriptionViewRe");

var containerStyle = {
  borderBottom: "1px solid #dddddd",
  margin: "5px",
  padding: "5px"
};

var unselectedTitleStyle = {
  color: "#999999",
  fontSize: "17px",
  margin: "10px"
};

var selectedTitleStyle = {
  color: "#48d3f2",
  fontSize: "17px",
  margin: "10px"
};

var iconStyle = {
  color: "#999999",
  fontSize: "16px",
  marginRight: "10px"
};

var horizontalStyle = {
  display: "flex",
  alignItems: "center",
  flexDirection: "row",
  justifyContent: "flex-start"
};

var spaceAroundHoriz = {
  display: "flex",
  alignItems: "center",
  flexDirection: "row",
  justifyContent: "space-between"
};

var timeStampStyle = {
  color: "#aaaaaa",
  fontSize: "13px",
  margin: "4px"
};

var unhighlightedBookmark = {
  color: "#aaaaaa",
  fontSize: "15px",
  margin: "5px"
};

var highlightedBookmark = {
  color: "#48d3f2",
  fontSize: "15px",
  margin: "5px"
};

function make(dispatch, note, _children) {
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
              var dateString = (
      function (note) {
        var a = new Date(note[3]);
        var months = ['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'];
        var year = a.getFullYear();
        var month = months[a.getMonth()];
        var date = a.getDate();
        var hour = a.getHours();
        var min = a.getMinutes();
        var sec = a.getSeconds();
        var time = month + ' ' + date + ',  ' + year;
        return time;
      }
    );
              var match = note[/* isSelected */5];
              var titleStyle = match ? selectedTitleStyle : unselectedTitleStyle;
              var match$1 = note[/* isStarred */4];
              var bookmarkStyle = match$1 ? highlightedBookmark : unhighlightedBookmark;
              var match$2 = note[/* isTrash */6];
              var trashStyle = match$2 ? highlightedBookmark : unhighlightedBookmark;
              return React.createElement("div", {
                          style: containerStyle
                        }, React.createElement("div", {
                              style: horizontalStyle,
                              onClick: (function (_data) {
                                  return Curry._1(dispatch, /* SelectNote */Block.__(4, [note]));
                                })
                            }, React.createElement("i", {
                                  className: "far fa-file-alt",
                                  style: iconStyle
                                }), React.createElement("input", {
                                  style: titleStyle,
                                  value: note[/* title */1],
                                  onChange: (function (_data) {
                                      var noteTitle = ( _data.target.value );
                                      var newNote_000 = /* noteID */note[/* noteID */0];
                                      var newNote_002 = /* body */note[/* body */2];
                                      var newNote_003 = /* timestamp */note[/* timestamp */3];
                                      var newNote_004 = /* isStarred */note[/* isStarred */4];
                                      var newNote_005 = /* isSelected */note[/* isSelected */5];
                                      var newNote_006 = /* isTrash */note[/* isTrash */6];
                                      var newNote_007 = /* folderID */note[/* folderID */7];
                                      var newNote = /* record */[
                                        newNote_000,
                                        /* title */noteTitle,
                                        newNote_002,
                                        newNote_003,
                                        newNote_004,
                                        newNote_005,
                                        newNote_006,
                                        newNote_007
                                      ];
                                      return Curry._1(dispatch, /* EditNote */Block.__(6, [newNote]));
                                    })
                                })), React.createElement("div", {
                              style: spaceAroundHoriz
                            }, React.createElement("p", {
                                  style: timeStampStyle
                                }, Curry._1(dateString, note)), React.createElement("div", {
                                  style: horizontalStyle
                                }, React.createElement("i", {
                                      className: "fas fa-bookmark hover",
                                      style: bookmarkStyle,
                                      onClick: (function (_data) {
                                          var newNote_000 = /* noteID */note[/* noteID */0];
                                          var newNote_001 = /* title */note[/* title */1];
                                          var newNote_002 = /* body */note[/* body */2];
                                          var newNote_003 = /* timestamp */note[/* timestamp */3];
                                          var newNote_004 = /* isStarred */!note[/* isStarred */4];
                                          var newNote_005 = /* isSelected */note[/* isSelected */5];
                                          var newNote_006 = /* isTrash */note[/* isTrash */6];
                                          var newNote_007 = /* folderID */note[/* folderID */7];
                                          var newNote = /* record */[
                                            newNote_000,
                                            newNote_001,
                                            newNote_002,
                                            newNote_003,
                                            newNote_004,
                                            newNote_005,
                                            newNote_006,
                                            newNote_007
                                          ];
                                          return Curry._1(dispatch, /* EditNote */Block.__(6, [newNote]));
                                        })
                                    }), React.createElement("i", {
                                      className: "fas fa-trash hover",
                                      style: trashStyle,
                                      onClick: (function (_data) {
                                          var newNote_000 = /* noteID */note[/* noteID */0];
                                          var newNote_001 = /* title */note[/* title */1];
                                          var newNote_002 = /* body */note[/* body */2];
                                          var newNote_003 = /* timestamp */note[/* timestamp */3];
                                          var newNote_004 = /* isStarred */note[/* isStarred */4];
                                          var newNote_005 = /* isSelected */note[/* isSelected */5];
                                          var newNote_006 = /* isTrash */!note[/* isTrash */6];
                                          var newNote_007 = /* folderID */note[/* folderID */7];
                                          var newNote = /* record */[
                                            newNote_000,
                                            newNote_001,
                                            newNote_002,
                                            newNote_003,
                                            newNote_004,
                                            newNote_005,
                                            newNote_006,
                                            newNote_007
                                          ];
                                          return Curry._1(dispatch, /* EditNote */Block.__(6, [newNote]));
                                        })
                                    }))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.containerStyle = containerStyle;
exports.unselectedTitleStyle = unselectedTitleStyle;
exports.selectedTitleStyle = selectedTitleStyle;
exports.iconStyle = iconStyle;
exports.horizontalStyle = horizontalStyle;
exports.spaceAroundHoriz = spaceAroundHoriz;
exports.timeStampStyle = timeStampStyle;
exports.unhighlightedBookmark = unhighlightedBookmark;
exports.highlightedBookmark = highlightedBookmark;
exports.make = make;
/* component Not a pure module */
