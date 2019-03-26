module Error = {
  type t('e) = Js.t('e);
};

module Database = {
  type t;
  module rec Reference: {
    type t;
    [@bs.get] external key: t => Js.nullable(string) = "";
    [@bs.get] external parent: t => Js.nullable(t) = "";
    [@bs.get] external root: t => t = "";
    [@bs.send] external child: (t, ~path: string) => t = "";
    [@bs.send]
    external once:
      (
        t,
        ~eventType: string,
        ~successCallback: DataSnapshot.t => unit=?,
        unit
      ) =>
      Js.Promise.t(DataSnapshot.t) =
      "";
    type cb = DataSnapshot.t => unit;
    [@bs.send]
    external on:
      (
        t,
        ~eventType: string,
        ~callback: DataSnapshot.t => unit,
        ~cancelCallback: Error.t('e) => unit=?,
        unit
      ) =>
      cb =
      "";
    [@bs.send]
    external off:
      (t, ~eventType: string, ~callback: DataSnapshot.t => unit=?, unit) =>
      unit =
      "";
    [@bs.send]
    external set:
      (
        t,
        ~value: 'a,
        ~onComplete: Js.nullable(Error.t('e)) => unit=?,
        unit
      ) =>
      Js.Promise.t(unit) =
      "";
    [@bs.send]
    external update:
      (
        t,
        ~value: 'a,
        ~onComplete: Js.nullable(Error.t('e)) => unit=?,
        unit
      ) =>
      Js.Promise.t(unit) =
      "";
    [@bs.send]
    external push:
      (
        t,
        ~value: 'a=?,
        ~onComplete: Js.nullable(Error.t('e)) => unit=?,
        unit
      ) =>
      t =
      "";
  } = Reference
  and DataSnapshot: {
    type t;
    [@bs.get] external key: t => Js.null(string) = "";
    [@bs.get] external ref: t => Reference.t = "";
    [@bs.send] external child: (t, ~path: string) => t = "";
    [@bs.send] external exists: t => bool = "";
    [@bs.send] external exportVal: t => Js.Json.t = "exportVal";
    [@bs.send] external foreach: (t, t => bool) => bool = "forEach";
    /*external getPriority*/
    [@bs.send] external hasChild: (t, ~path: string) => bool = "hasChild";
    [@bs.send] external hasChildren: t => bool = "hasChildren";
    [@bs.send] external numChildren: t => int = "numChildren";
    [@bs.send] external toJson: t => Js.Json.t = "toJSON";
    [@bs.send] external val_: t => Js.Json.t = "val";
  } = DataSnapshot;
  module OnDisconnect = {
    type t;
    [@bs.send]
    external cancel:
      (t, ~onComplete: Js.nullable(Error.t('e)) => unit=?) =>
      Js.Promise.t(unit) =
      "";
    [@bs.send]
    external remove:
      (t, ~onComplete: Js.nullable(Error.t('e)) => unit=?) =>
      Js.Promise.t(unit) =
      "";
    [@bs.send]
    external set:
      (t, Js.Json.t, ~onComplete: Js.nullable(Error.t('e)) => unit=?) =>
      Js.Promise.t(unit) =
      "";
    /*external setWithPriority*/
    [@bs.send]
    external update:
      (t, Js.Json.t, ~onComplete: Js.nullable(Error.t('e)) => unit=?) =>
      Js.Promise.t(unit) =
      "";
  };
  module ThenableReference = {
    type t;
  };
  module Query = {
    type t;
  };
  /*external app : t => App.t = "" [@@bs.get];*/
  [@bs.send] external goOffline: t => unit = "goOffline";
  [@bs.send] external goOnline: t => unit = "goOnline";
  [@bs.send] external ref: (t, ~path: string=?, unit) => Reference.t = "";
  [@bs.scope ("database", "ServerValue")] [@bs.val] [@bs.module "firebase"]
  external serverTimestamp: Js.null(string) = "TIMESTAMP";
  [@bs.send]
  external refFromUrl: (t, ~url: string) => Reference.t = "refFromURL";
};

module Storage = {
  type t;
  module UploadTask = {
    type t;
  };
  module Reference = {
    type t;
    [@bs.get] external bucket: t => string = "";
    [@bs.get] external fullPath: t => string = "";
    [@bs.get] external name: t => string = "";
    [@bs.get] external parent: t => option(t) = "";
    [@bs.get] external root: t => t = "";
    /*external storage : t => Storage.t = "" [@@bs.get];*/
    [@bs.send] external path: (t, ~path: string) => t = "";
    [@bs.send]
    external put:
      (t, ~data: Js.Array.t(int), ~metadata: Js.t('a)=?, unit) =>
      Js.Promise.t(UploadTask.t) =
      "";
    [@bs.send] external delete: t => Js.Promise.t(unit) = "";
    [@bs.send] external getDownloadURL: t => Js.Promise.t(string) = "";
  };
  [@bs.send] external ref: (t, ~path: string=?, unit) => Reference.t = "";
};

module Auth = {
  type t;
  module User = {
    type t;
    type profile = {
      .
      "displayName": Js.nullable(string),
      "photoURL": Js.nullable(string),
    };
    [@bs.get] external displayName: t => string = "displayName";
    [@bs.get] external email: t => Js.nullable(string) = "email";
    [@bs.get] external emailVerified: t => bool = "emailVerified";
    [@bs.get] external isAnonymous: t => bool = "isAnonymous";
    [@bs.get] external phoneNumber: t => Js.nullable(string) = "phoneNumber";
    [@bs.get] external photoUrl: t => Js.nullable(string) = "photoURL";
    [@bs.get] external uid: t => string = "uid";
    [@bs.send]
    external updateProfile: (t, ~profile: profile) => Js.Promise.t(unit) =
      "updateProfile";
    [@bs.send]
    external getIdToken: t => Js.Promise.t(Js.nullable(string)) = "";
  };
  module Error = {
    type t;
  };
  module AuthCredential = {
    type t;
  };
  module AdditionalUserInfo = {
    type t;
  };
  module UserCredential = {
    type t;
    [@bs.get] external user: t => Js.nullable(User.t) = "user";
    [@bs.get]
    external credential: t => Js.nullable(AuthCredential.t) = "credential";
    [@bs.get]
    external operationType: t => Js.nullable(string) = "operationType";
    [@bs.get]
    external additionalUserInfo: t => Js.nullable(AdditionalUserInfo.t) =
      "additionalUserInfo";
  };
  [@bs.get] external currentUser: t => Js.nullable(User.t) = "currentUser";
  [@bs.send]
  external createUserAndRetrieveDataWithEmailAndPassword:
    (t, ~email: string, ~password: string) => Js.Promise.t(UserCredential.t) =
    "createUserWithEmailAndPassword";
  [@bs.send]
  external signinUserAndRetrieveDataWithEmailAndPassword:
    (t, ~email: string, ~password: string) => Js.Promise.t(UserCredential.t) =
    "signInWithEmailAndPassword";
  [@bs.send]
  external signInWithEmailAndPassword:
    (t, ~email: string, ~password: string) => Js.Promise.t(UserCredential.t) =
    "signInAndRetrieveDataWithEmailAndPassword";
  [@bs.send]
  external onAuthStateChanged:
    (
      t,
      ~nextOrObserver: Js.Null.t(User.t) => unit,
      ~error: Error.t => unit=?,
      ~completed: unit => unit=?
    ) =>
    unit =
    "onAuthStateChanged";
  [@bs.send]
  external signInAnonymously: (t, unit) => Js.Promise.t(User.t) =
    "signInAnonymously";
  [@bs.send]
  external signInWithCredential:
    (t, ~credential: AuthCredential.t) => Js.Promise.t(User.t) =
    "signInWithCredential";
  [@bs.send]
  external signInWithCustomToken: (t, ~token: string) => Js.Promise.t(User.t) =
    "signInWithCustomToken";
  [@bs.send] external signOut: t => Js.Promise.t(unit) = "signOut";
};

module App = {
  type t;
  [@bs.send] external auth: t => Auth.t = "";
  [@bs.send] external database: t => Database.t = "";
  /*external delete*/
  /*external messaging*/
  [@bs.send] external storage: t => Storage.t = "";
  [@bs.get] external options: t => Js.t('a) = "";
};

type options = {
  .
  "apiKey": string,
  "authDomain": string,
  "databaseURL": string,
  "storageBucket": string,
  "messagingSenderId": string,
};

[@bs.module "firebase"]
external initializeApp: (~options: options) => App.t = "initializeApp";