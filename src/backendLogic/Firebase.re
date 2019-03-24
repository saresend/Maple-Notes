[@bs.module] external firebase: 'a = "firebase/app";

let loginWithDispatcher: (string, string, Actions.action => unit) => unit = [%bs.raw
  {|
  function(email, password) {
    var firebase = require("firebase/app");
    require("firebase/auth");
    firebase.auth().createUserWithEmailAndPassword(email, password).catch((error) => {

    });

  }

|}
];