// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("SigninPage");

var horizontalStyle = {
  display: "flex",
  flexDirection: "row"
};

var leftBarStyle = {
  backgroundColor: "#ff9d84",
  display: "flex",
  height: "100vh",
  width: "40vw",
  alignItems: "center",
  flexDirection: "row",
  justifyContent: "flex-end"
};

var rightBarStyle = {
  backgroundColor: "#ffffff",
  display: "flex",
  height: "100vh",
  width: "60vw",
  alignItems: "center",
  flexDirection: "row",
  justifyContent: "flex-start"
};

var leftLoginBlockStyle = {
  backgroundColor: "#ff9d84",
  display: "flex",
  height: "80vh",
  verticalAlign: "super",
  width: "30vw",
  boxShadow: "0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19)",
  alignItems: "center",
  flexDirection: "column",
  justifyContent: "center"
};

var logoTitleStyle = {
  color: "#ffffff",
  fontSize: "30px",
  margin: "5px"
};

var logoStyle = {
  color: "#ffffff",
  fontSize: "50px"
};

var rightLoginBlockStyle = {
  backgroundColor: "#ffffff",
  display: "flex",
  height: "80vh",
  verticalAlign: "super",
  width: "50vw",
  boxShadow: "0 4px 8px 0 rgba(0, 0, 0, 0.2), 0 6px 20px 0 rgba(0, 0, 0, 0.19)",
  alignItems: "center",
  flexDirection: "column",
  justifyContent: "center"
};

var signinTitleStyle = {
  color: "#939393",
  fontSize: "30px",
  marginBottom: "5px"
};

var inputStyle = {
  borderBottom: "1px solid gray",
  display: "block",
  fontSize: "17px",
  marginTop: "20px",
  width: "200px"
};

var buttonStyle = {
  backgroundColor: "#1ae5b6",
  border: "0px",
  color: "#ffffff",
  fontFamily: "Aleo",
  fontSize: "17px",
  marginTop: "20px",
  outline: "0px",
  padding: "8px",
  width: "200px",
  borderRadius: "3px"
};

function make(dispatch, _children) {
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
                          style: horizontalStyle
                        }, React.createElement("div", {
                              style: leftBarStyle
                            }, React.createElement("div", {
                                  style: leftLoginBlockStyle
                                }, React.createElement("i", {
                                      className: "fab fa-pagelines",
                                      style: logoStyle
                                    }), React.createElement("p", {
                                      style: logoTitleStyle
                                    }, "Maple"))), React.createElement("div", {
                              style: rightBarStyle
                            }, React.createElement("div", {
                                  style: rightLoginBlockStyle
                                }, React.createElement("p", {
                                      style: signinTitleStyle
                                    }, "Sign In"), React.createElement("input", {
                                      style: inputStyle,
                                      placeholder: "Email"
                                    }), React.createElement("input", {
                                      style: inputStyle,
                                      placeholder: "Password"
                                    }), React.createElement("button", {
                                      className: "hover",
                                      style: buttonStyle,
                                      onClick: (function (_data) {
                                          return Curry._1(dispatch, /* SignInUserSuccessfully */Block.__(0, ["asdfasdf"]));
                                        })
                                    }, "Log In"), React.createElement("button", {
                                      className: "hover",
                                      style: buttonStyle,
                                      onClick: (function (_data) {
                                          return Curry._1(dispatch, /* SignInUserSuccessfully */Block.__(0, ["asdfasdf"]));
                                        })
                                    }, "Sign Up"))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.horizontalStyle = horizontalStyle;
exports.leftBarStyle = leftBarStyle;
exports.rightBarStyle = rightBarStyle;
exports.leftLoginBlockStyle = leftLoginBlockStyle;
exports.logoTitleStyle = logoTitleStyle;
exports.logoStyle = logoStyle;
exports.rightLoginBlockStyle = rightLoginBlockStyle;
exports.signinTitleStyle = signinTitleStyle;
exports.inputStyle = inputStyle;
exports.buttonStyle = buttonStyle;
exports.make = make;
/* component Not a pure module */
