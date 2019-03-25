// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Utils$ReactTemplate = require("./Utils.bs.js");
var Editor$ReactTemplate = require("./Editor.bs.js");
var NoteListRe$ReactTemplate = require("./reasonComponents/NoteListRe.bs.js");
var SigninPage$ReactTemplate = require("./signinComponents/SigninPage.bs.js");
var ReactFiletree$ReactTemplate = require("./reasonBindings/ReactFiletree.bs.js");

var appStyle = {
  display: "flex",
  flexDirection: "row"
};

var editorContainerStyle = {
  padding: "45px"
};

var maple = ReasonReact.reducerComponent("Maple");

var uuidGen = (
    function (val) {
          const uuidv4 = require('uuid/v4');
          return uuidv4();
    });

var initialTopItems = /* array */[
  /* record */[
    /* id */Curry._1(uuidGen, 10),
    /* title */"All Notes",
    /* isEditable */false,
    /* noteType : NoteBook */0,
    /* isSelected */true,
    /* filterFunction */(function (_element, note) {
        return !note[/* isTrash */7];
      })
  ],
  /* record */[
    /* id */Curry._1(uuidGen, 10),
    /* title */"Starred Notes",
    /* isEditable */false,
    /* noteType : Starred */2,
    /* isSelected */false,
    /* filterFunction */(function (_element, note) {
        return note[/* isStarred */4];
      })
  ],
  /* record */[
    /* id */Curry._1(uuidGen, 10),
    /* title */"Trash",
    /* isEditable */false,
    /* noteType : Trash */1,
    /* isSelected */false,
    /* filterFunction */(function (_element, note) {
        return note[/* isTrash */7];
      })
  ]
];

function augmentMenuItems(notes, fileTreeElements) {
  return fileTreeElements.map((function (ftElement) {
                var filteredNotes = notes.filter((function (note) {
                        return Curry._2(ftElement[/* filterFunction */5], ftElement, note);
                      }));
                var noteLength = filteredNotes.length;
                return /* record */[
                        /* noteElement */ftElement,
                        /* numNotes */noteLength
                      ];
              }));
}

var initialBottomItems = /* array */[];

function make(_children) {
  return /* record */[
          /* debugName */maple[/* debugName */0],
          /* reactClassInternal */maple[/* reactClassInternal */1],
          /* handedOffState */maple[/* handedOffState */2],
          /* willReceiveProps */maple[/* willReceiveProps */3],
          /* didMount */maple[/* didMount */4],
          /* didUpdate */maple[/* didUpdate */5],
          /* willUnmount */maple[/* willUnmount */6],
          /* willUpdate */maple[/* willUpdate */7],
          /* shouldUpdate */maple[/* shouldUpdate */8],
          /* render */(function (self) {
              var updateFunction = function (_value) {
                var bodyText = ( _value() );
                return Curry._1(self[/* send */3], /* TypeCurrentNote */Block.__(7, [bodyText]));
              };
              var match = self[/* state */1][/* currentNote */1];
              var editorView;
              if (match !== undefined) {
                var note = match;
                editorView = React.createElement("div", {
                      style: editorContainerStyle
                    }, ReasonReact.element(note[/* noteID */0], undefined, Editor$ReactTemplate.make(note[/* body */2], "Write Anything...", undefined, updateFunction, true, /* array */[])));
              } else {
                editorView = React.createElement("div", undefined);
              }
              var partial_arg = Curry._1(self[/* state */1][/* currentFilterElement */6][/* filterFunction */5], self[/* state */1][/* currentFilterElement */6]);
              var filteredNotes = self[/* state */1][/* notes */0].filter(Curry.__1(partial_arg));
              var partial_arg$1 = self[/* state */1][/* searchFilter */7];
              var searchFilteredNotes = filteredNotes.filter(Curry.__1(partial_arg$1));
              var noteApplication = React.createElement("div", {
                    style: appStyle
                  }, ReasonReact.element(undefined, undefined, ReactFiletree$ReactTemplate.make(self[/* send */3], self[/* state */1][/* menuBarOpen */5], augmentMenuItems(self[/* state */1][/* notes */0], self[/* state */1][/* topMenuItems */8]), augmentMenuItems(self[/* state */1][/* notes */0], self[/* state */1][/* bottomMenuItems */9]), /* array */[])), ReasonReact.element(undefined, undefined, NoteListRe$ReactTemplate.make(self[/* send */3], searchFilteredNotes, /* array */[])), editorView);
              var signinPage = ReasonReact.element(undefined, undefined, SigninPage$ReactTemplate.make(self[/* send */3], self[/* state */1][/* failureReason */4], /* array */[]));
              var match$1 = self[/* state */1][/* isUserSignedIn */3];
              if (match$1) {
                return noteApplication;
              } else {
                return signinPage;
              }
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* notes : array */[],
                      /* currentNote */undefined,
                      /* isLoaded */false,
                      /* isUserSignedIn */false,
                      /* failureReason */undefined,
                      /* menuBarOpen */true,
                      /* currentFilterElement */Caml_array.caml_array_get(initialTopItems, 0),
                      /* searchFilter */(function (_note) {
                          return true;
                        }),
                      /* topMenuItems */initialTopItems,
                      /* bottomMenuItems */initialBottomItems
                    ];
            }),
          /* retainedProps */maple[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                if (action === 0) {
                  var newBottomItem_000 = /* id */Curry._1(uuidGen, 10);
                  var newBottomItem_003 = /* noteType : Folder */[Utils$ReactTemplate.generateColor(/* () */0)];
                  var newBottomItem_005 = function (element, note) {
                    return note[/* folderID */8] === element[/* id */0];
                  };
                  var newBottomItem = /* record */[
                    newBottomItem_000,
                    /* title */"New Folder",
                    /* isEditable */false,
                    newBottomItem_003,
                    /* isSelected */false,
                    newBottomItem_005
                  ];
                  var newBottomItems = state[/* bottomMenuItems */9].concat(/* array */[newBottomItem]);
                  return /* Update */Block.__(0, [/* record */[
                              /* notes */state[/* notes */0],
                              /* currentNote */state[/* currentNote */1],
                              /* isLoaded */state[/* isLoaded */2],
                              /* isUserSignedIn */state[/* isUserSignedIn */3],
                              /* failureReason */state[/* failureReason */4],
                              /* menuBarOpen */state[/* menuBarOpen */5],
                              /* currentFilterElement */state[/* currentFilterElement */6],
                              /* searchFilter */state[/* searchFilter */7],
                              /* topMenuItems */state[/* topMenuItems */8],
                              /* bottomMenuItems */newBottomItems
                            ]]);
                } else {
                  return /* Update */Block.__(0, [/* record */[
                              /* notes */state[/* notes */0],
                              /* currentNote */state[/* currentNote */1],
                              /* isLoaded */state[/* isLoaded */2],
                              /* isUserSignedIn */state[/* isUserSignedIn */3],
                              /* failureReason */state[/* failureReason */4],
                              /* menuBarOpen */!state[/* menuBarOpen */5],
                              /* currentFilterElement */state[/* currentFilterElement */6],
                              /* searchFilter */state[/* searchFilter */7],
                              /* topMenuItems */state[/* topMenuItems */8],
                              /* bottomMenuItems */state[/* bottomMenuItems */9]
                            ]]);
                }
              } else {
                switch (action.tag | 0) {
                  case 0 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0],
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */true,
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */state[/* bottomMenuItems */9]
                                ]]);
                  case 1 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0],
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */action[0],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */state[/* bottomMenuItems */9]
                                ]]);
                  case 2 : 
                      var newMenuItem = action[0];
                      var updatedMenuItems = state[/* bottomMenuItems */9].map((function (menuItem) {
                              if (menuItem[/* id */0] === newMenuItem[/* id */0]) {
                                return newMenuItem;
                              } else {
                                return menuItem;
                              }
                            }));
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0],
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */updatedMenuItems
                                ]]);
                  case 3 : 
                      var menuItemId = action[0];
                      var newBottomItems$1 = state[/* bottomMenuItems */9].map((function (menuItem) {
                              if (menuItem[/* id */0] === menuItemId) {
                                return /* record */[
                                        /* id */menuItem[/* id */0],
                                        /* title */menuItem[/* title */1],
                                        /* isEditable */true,
                                        /* noteType */menuItem[/* noteType */3],
                                        /* isSelected */menuItem[/* isSelected */4],
                                        /* filterFunction */menuItem[/* filterFunction */5]
                                      ];
                              } else {
                                return menuItem;
                              }
                            }));
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0],
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */newBottomItems$1
                                ]]);
                  case 4 : 
                      var menuItemId$1 = action[0];
                      var newBottomItems$2 = state[/* bottomMenuItems */9].filter((function (bottomBarItem) {
                              return bottomBarItem[/* id */0] !== menuItemId$1;
                            }));
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0],
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */newBottomItems$2
                                ]]);
                  case 5 : 
                      var searchString = action[0];
                      if (searchString === "") {
                        return /* Update */Block.__(0, [/* record */[
                                    /* notes */state[/* notes */0],
                                    /* currentNote */state[/* currentNote */1],
                                    /* isLoaded */state[/* isLoaded */2],
                                    /* isUserSignedIn */state[/* isUserSignedIn */3],
                                    /* failureReason */state[/* failureReason */4],
                                    /* menuBarOpen */state[/* menuBarOpen */5],
                                    /* currentFilterElement */state[/* currentFilterElement */6],
                                    /* searchFilter */(function (_note) {
                                        return true;
                                      }),
                                    /* topMenuItems */state[/* topMenuItems */8],
                                    /* bottomMenuItems */state[/* bottomMenuItems */9]
                                  ]]);
                      } else {
                        return /* Update */Block.__(0, [/* record */[
                                    /* notes */state[/* notes */0],
                                    /* currentNote */state[/* currentNote */1],
                                    /* isLoaded */state[/* isLoaded */2],
                                    /* isUserSignedIn */state[/* isUserSignedIn */3],
                                    /* failureReason */state[/* failureReason */4],
                                    /* menuBarOpen */state[/* menuBarOpen */5],
                                    /* currentFilterElement */state[/* currentFilterElement */6],
                                    /* searchFilter */(function (note) {
                                        var regex = new RegExp(searchString);
                                        var result = regex.exec(note[/* body */2]);
                                        var bodySearch = result !== null;
                                        var result$1 = regex.exec(note[/* title */1]);
                                        var titleSearch = result$1 !== null;
                                        if (bodySearch) {
                                          return true;
                                        } else {
                                          return titleSearch;
                                        }
                                      }),
                                    /* topMenuItems */state[/* topMenuItems */8],
                                    /* bottomMenuItems */state[/* bottomMenuItems */9]
                                  ]]);
                      }
                  case 6 : 
                      var note = action[0];
                      var notes = state[/* notes */0].map((function (oldNote) {
                              if (oldNote[/* noteID */0] === note[/* noteID */0]) {
                                return /* record */[
                                        /* noteID */note[/* noteID */0],
                                        /* title */note[/* title */1],
                                        /* body */note[/* body */2],
                                        /* timestamp */note[/* timestamp */3],
                                        /* isStarred */note[/* isStarred */4],
                                        /* isSelected */true,
                                        /* isEditable */note[/* isEditable */6],
                                        /* isTrash */note[/* isTrash */7],
                                        /* folderID */note[/* folderID */8]
                                      ];
                              } else {
                                var match = state[/* currentNote */1];
                                if (match !== undefined) {
                                  var currNote = match;
                                  if (currNote[/* noteID */0] === oldNote[/* noteID */0]) {
                                    return /* record */[
                                            /* noteID */currNote[/* noteID */0],
                                            /* title */currNote[/* title */1],
                                            /* body */currNote[/* body */2],
                                            /* timestamp */currNote[/* timestamp */3],
                                            /* isStarred */currNote[/* isStarred */4],
                                            /* isSelected */false,
                                            /* isEditable */currNote[/* isEditable */6],
                                            /* isTrash */currNote[/* isTrash */7],
                                            /* folderID */currNote[/* folderID */8]
                                          ];
                                  } else {
                                    return /* record */[
                                            /* noteID */oldNote[/* noteID */0],
                                            /* title */oldNote[/* title */1],
                                            /* body */oldNote[/* body */2],
                                            /* timestamp */oldNote[/* timestamp */3],
                                            /* isStarred */oldNote[/* isStarred */4],
                                            /* isSelected */false,
                                            /* isEditable */oldNote[/* isEditable */6],
                                            /* isTrash */oldNote[/* isTrash */7],
                                            /* folderID */oldNote[/* folderID */8]
                                          ];
                                  }
                                } else {
                                  return /* record */[
                                          /* noteID */oldNote[/* noteID */0],
                                          /* title */oldNote[/* title */1],
                                          /* body */oldNote[/* body */2],
                                          /* timestamp */oldNote[/* timestamp */3],
                                          /* isStarred */oldNote[/* isStarred */4],
                                          /* isSelected */false,
                                          /* isEditable */oldNote[/* isEditable */6],
                                          /* isTrash */oldNote[/* isTrash */7],
                                          /* folderID */oldNote[/* folderID */8]
                                        ];
                                }
                              }
                            }));
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */notes,
                                  /* currentNote */note,
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */state[/* bottomMenuItems */9]
                                ]]);
                  case 7 : 
                      var match = state[/* currentNote */1];
                      if (match !== undefined) {
                        var currNote = match;
                        var newNote_000 = /* noteID */currNote[/* noteID */0];
                        var newNote_001 = /* title */currNote[/* title */1];
                        var newNote_002 = /* body */action[0];
                        var newNote_003 = /* timestamp */currNote[/* timestamp */3];
                        var newNote_004 = /* isStarred */currNote[/* isStarred */4];
                        var newNote_005 = /* isSelected */currNote[/* isSelected */5];
                        var newNote_006 = /* isEditable */currNote[/* isEditable */6];
                        var newNote_007 = /* isTrash */currNote[/* isTrash */7];
                        var newNote_008 = /* folderID */currNote[/* folderID */8];
                        var newNote = /* record */[
                          newNote_000,
                          newNote_001,
                          newNote_002,
                          newNote_003,
                          newNote_004,
                          newNote_005,
                          newNote_006,
                          newNote_007,
                          newNote_008
                        ];
                        return /* Update */Block.__(0, [/* record */[
                                    /* notes */state[/* notes */0],
                                    /* currentNote */newNote,
                                    /* isLoaded */state[/* isLoaded */2],
                                    /* isUserSignedIn */state[/* isUserSignedIn */3],
                                    /* failureReason */state[/* failureReason */4],
                                    /* menuBarOpen */state[/* menuBarOpen */5],
                                    /* currentFilterElement */state[/* currentFilterElement */6],
                                    /* searchFilter */state[/* searchFilter */7],
                                    /* topMenuItems */state[/* topMenuItems */8],
                                    /* bottomMenuItems */state[/* bottomMenuItems */9]
                                  ]]);
                      } else {
                        return /* Update */Block.__(0, [/* record */[
                                    /* notes */state[/* notes */0],
                                    /* currentNote */undefined,
                                    /* isLoaded */state[/* isLoaded */2],
                                    /* isUserSignedIn */state[/* isUserSignedIn */3],
                                    /* failureReason */state[/* failureReason */4],
                                    /* menuBarOpen */state[/* menuBarOpen */5],
                                    /* currentFilterElement */state[/* currentFilterElement */6],
                                    /* searchFilter */state[/* searchFilter */7],
                                    /* topMenuItems */state[/* topMenuItems */8],
                                    /* bottomMenuItems */state[/* bottomMenuItems */9]
                                  ]]);
                      }
                  case 8 : 
                      var note$1 = action[0];
                      var notes$1 = state[/* notes */0].map((function (oldNote) {
                              if (oldNote[/* noteID */0] === note$1[/* noteID */0]) {
                                return note$1;
                              } else {
                                return oldNote;
                              }
                            }));
                      var match$1 = state[/* currentNote */1];
                      if (match$1 !== undefined) {
                        var match$2 = match$1[/* noteID */0] === note$1[/* noteID */0];
                        if (match$2) {
                          return /* Update */Block.__(0, [/* record */[
                                      /* notes */notes$1,
                                      /* currentNote */note$1,
                                      /* isLoaded */state[/* isLoaded */2],
                                      /* isUserSignedIn */state[/* isUserSignedIn */3],
                                      /* failureReason */state[/* failureReason */4],
                                      /* menuBarOpen */state[/* menuBarOpen */5],
                                      /* currentFilterElement */state[/* currentFilterElement */6],
                                      /* searchFilter */state[/* searchFilter */7],
                                      /* topMenuItems */state[/* topMenuItems */8],
                                      /* bottomMenuItems */state[/* bottomMenuItems */9]
                                    ]]);
                        } else {
                          return /* Update */Block.__(0, [/* record */[
                                      /* notes */notes$1,
                                      /* currentNote */state[/* currentNote */1],
                                      /* isLoaded */state[/* isLoaded */2],
                                      /* isUserSignedIn */state[/* isUserSignedIn */3],
                                      /* failureReason */state[/* failureReason */4],
                                      /* menuBarOpen */state[/* menuBarOpen */5],
                                      /* currentFilterElement */state[/* currentFilterElement */6],
                                      /* searchFilter */state[/* searchFilter */7],
                                      /* topMenuItems */state[/* topMenuItems */8],
                                      /* bottomMenuItems */state[/* bottomMenuItems */9]
                                    ]]);
                        }
                      } else {
                        return /* Update */Block.__(0, [/* record */[
                                    /* notes */notes$1,
                                    /* currentNote */state[/* currentNote */1],
                                    /* isLoaded */state[/* isLoaded */2],
                                    /* isUserSignedIn */state[/* isUserSignedIn */3],
                                    /* failureReason */state[/* failureReason */4],
                                    /* menuBarOpen */state[/* menuBarOpen */5],
                                    /* currentFilterElement */state[/* currentFilterElement */6],
                                    /* searchFilter */state[/* searchFilter */7],
                                    /* topMenuItems */state[/* topMenuItems */8],
                                    /* bottomMenuItems */state[/* bottomMenuItems */9]
                                  ]]);
                      }
                  case 9 : 
                      var noteID2 = Curry._1(uuidGen, 20);
                      var note_003 = /* timestamp */( Date.now() );
                      var note_008 = /* folderID */state[/* currentFilterElement */6][/* id */0];
                      var note$2 = /* record */[
                        /* noteID */noteID2,
                        /* title */"New Note",
                        /* body */"",
                        note_003,
                        /* isStarred */false,
                        /* isSelected */false,
                        /* isEditable */false,
                        /* isTrash */false,
                        note_008
                      ];
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0].concat(/* array */[note$2]),
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */state[/* bottomMenuItems */9]
                                ]]);
                  case 10 : 
                      var noteId = action[0];
                      var newNotes = state[/* notes */0].map((function (note) {
                              if (note[/* noteID */0] === noteId) {
                                return /* record */[
                                        /* noteID */note[/* noteID */0],
                                        /* title */note[/* title */1],
                                        /* body */note[/* body */2],
                                        /* timestamp */note[/* timestamp */3],
                                        /* isStarred */note[/* isStarred */4],
                                        /* isSelected */note[/* isSelected */5],
                                        /* isEditable */true,
                                        /* isTrash */note[/* isTrash */7],
                                        /* folderID */note[/* folderID */8]
                                      ];
                              } else {
                                return note;
                              }
                            }));
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */newNotes,
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */state[/* currentFilterElement */6],
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */state[/* topMenuItems */8],
                                  /* bottomMenuItems */state[/* bottomMenuItems */9]
                                ]]);
                  case 11 : 
                      var element = action[0];
                      var newTopMenuItems = state[/* topMenuItems */8].map((function (oldElement) {
                              if (oldElement[/* id */0] === element[/* id */0]) {
                                return /* record */[
                                        /* id */element[/* id */0],
                                        /* title */element[/* title */1],
                                        /* isEditable */element[/* isEditable */2],
                                        /* noteType */element[/* noteType */3],
                                        /* isSelected */true,
                                        /* filterFunction */element[/* filterFunction */5]
                                      ];
                              } else {
                                return /* record */[
                                        /* id */oldElement[/* id */0],
                                        /* title */oldElement[/* title */1],
                                        /* isEditable */oldElement[/* isEditable */2],
                                        /* noteType */oldElement[/* noteType */3],
                                        /* isSelected */false,
                                        /* filterFunction */oldElement[/* filterFunction */5]
                                      ];
                              }
                            }));
                      var newBottomMenuItems = state[/* bottomMenuItems */9].map((function (oldElement) {
                              if (oldElement[/* id */0] === element[/* id */0]) {
                                return /* record */[
                                        /* id */element[/* id */0],
                                        /* title */element[/* title */1],
                                        /* isEditable */element[/* isEditable */2],
                                        /* noteType */element[/* noteType */3],
                                        /* isSelected */true,
                                        /* filterFunction */element[/* filterFunction */5]
                                      ];
                              } else {
                                return /* record */[
                                        /* id */oldElement[/* id */0],
                                        /* title */oldElement[/* title */1],
                                        /* isEditable */oldElement[/* isEditable */2],
                                        /* noteType */oldElement[/* noteType */3],
                                        /* isSelected */false,
                                        /* filterFunction */oldElement[/* filterFunction */5]
                                      ];
                              }
                            }));
                      return /* Update */Block.__(0, [/* record */[
                                  /* notes */state[/* notes */0],
                                  /* currentNote */state[/* currentNote */1],
                                  /* isLoaded */state[/* isLoaded */2],
                                  /* isUserSignedIn */state[/* isUserSignedIn */3],
                                  /* failureReason */state[/* failureReason */4],
                                  /* menuBarOpen */state[/* menuBarOpen */5],
                                  /* currentFilterElement */element,
                                  /* searchFilter */state[/* searchFilter */7],
                                  /* topMenuItems */newTopMenuItems,
                                  /* bottomMenuItems */newBottomMenuItems
                                ]]);
                  
                }
              }
            }),
          /* jsElementWrapped */maple[/* jsElementWrapped */13]
        ];
}

exports.appStyle = appStyle;
exports.editorContainerStyle = editorContainerStyle;
exports.maple = maple;
exports.uuidGen = uuidGen;
exports.initialTopItems = initialTopItems;
exports.augmentMenuItems = augmentMenuItems;
exports.initialBottomItems = initialBottomItems;
exports.make = make;
/* maple Not a pure module */
