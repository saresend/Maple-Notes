var firebase = require("firebase/app");
require("firebase/auth");


// Should return a promise
function mapleLogin(email, password) {
  var loginPromise = new Promise((resolve, reject) => {
    firebase.auth().signInWithEmailAndPassword(email, password).then((result) => {
      resolve("Success");
    }).catch((error) => {
      // Handle Errors here.
      const errorCode = error.code;
      const errorMessage = error.message;
      reject(errorMessage);
    });
  });
}


function mapleSignup(email, password) {
  var loginPromise = new Promise((resolve, reject) => {
    firebase.auth().createUserWithEmailAndPassword(email, password).then((result) => {
      resolve("Success");
    }).catch((error) => {
      // Handle Errors here.
      const errorCode = error.code;
      const errorMessage = error.message;
      reject(errorMessage);
    });
  });
}