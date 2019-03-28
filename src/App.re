type state = {
  notes: array(Note.note),
  currentNote: option(Note.note),
  isLoaded: bool,
  isUserSignedIn: bool,
  failureReason: option(string),
  menuBarOpen: bool,
  email: string,
  currentFilterElement: NoteUIElement.noteUIElement,
  searchFilter: Note.note => bool,
  topMenuItems: array(NoteUIElement.noteUIElement),
  bottomMenuItems: array(NoteUIElement.noteUIElement),
};
open Firebase;
let app = {
  let config: options = {
    "apiKey": "AIzaSyC-s0dwO0vw1QU7st911o8iBw9VVlIZ1uY",
    "authDomain": "maple-notes.firebaseapp.com",
    "databaseURL": "https://maple-notes.firebaseio.com",
    "storageBucket": "maple-notes.appspot.com",
    "messagingSenderId": "169600693604",
  };
  Firebase.initializeApp(config);
};

let produceID = () => {
  let authObj = Firebase.App.auth(app);
  let currUser = Firebase.Auth.currentUser(authObj);

  switch (Js.Nullable.toOption(currUser)) {
  | Some(user) => Firebase.Auth.User.uid(user)
  | None => ""
  };
};

[@bs.deriving abstract]
type serializedState = {
  notes: array(Note.note),
  isLoaded: bool,
  isUserSignedIn: bool,
  menuBarOpen: bool,
  email: string,
  mutable bottomMenuItems: array(NoteUIElement.noteUIElement),
};

let serializeState: state => string =
  state => {
    let partialResult =
      serializedState(
        ~notes=state.notes,
        ~isLoaded=state.isLoaded,
        ~isUserSignedIn=state.isUserSignedIn,
        ~menuBarOpen=state.menuBarOpen,
        ~email=state.email,
        ~bottomMenuItems=state.bottomMenuItems,
      );
    Js.log(partialResult);
    let trueResult: string = [%bs.raw {| JSON.stringify(partialResult) |}];
    trueResult;
  };
let deserializeState = _stateString => {
  let objOptJs: Js.nullable(serializedState) = [%bs.raw
    {|JSON.parse(_stateString)|}
  ];
  let objOption = Js.Nullable.toOption(objOptJs);
  Js.log(objOption);
  switch (objOption) {
  | Some(obj) =>
    let bottomBarItemsWithFilter =
      Js.Array.map(
        nullFilterItem => {
          open NoteUIElement;
          open Note;
          let filterFunc = (element, note) => note.folderID == element.id;
          {...nullFilterItem, filterFunction: filterFunc};
        },
        obj->bottomMenuItemsGet,
      );
    obj->bottomMenuItemsSet(bottomBarItemsWithFilter);
    Some(obj);
  | None => None
  };
};

let consolidateCurrentNote = state => {
  open Note;
  let newNotes =
    Js.Array.map(
      (oldNote): Note.note =>
        switch (state.currentNote) {
        | Some(currNote) =>
          if (oldNote.noteID == currNote.noteID) {
            {...currNote, isSelected: false};
          } else {
            oldNote;
          }
        | None => oldNote
        },
      state.notes,
    );
  {...state, notes: newNotes};
};

let saveData = (state, app) => {
  let database = Firebase.App.database(app);
  let dataPath = produceID();
  let savedState = consolidateCurrentNote(state);
  let dataValue = serializeState(savedState);
  Firebase.Database.Reference.set(
    Firebase.Database.ref(database, ~path=dataPath, ()),
    ~value=dataValue,
    (),
  )
  |> ignore;
};
let appStyle =
  ReactDOMRe.Style.make(~display="flex", ~flexDirection="row", ());
let editorContainerStyle = ReactDOMRe.Style.make(~padding="45px", ());
open Note;
let maple = ReasonReact.reducerComponent("Maple");
let uuidGen: int => string = [%bs.raw
  {|
    function (val) {
          const uuidv4 = require('uuid/v4');
          return uuidv4();
    }|}
];
let initialTopItems: array(NoteUIElement.noteUIElement) = [|
  {
    id: uuidGen(10),
    title: "All Notes",
    isEditable: false,
    noteType: NoteBook,
    isSelected: true,
    filterFunction: (_element, note) => !note.isTrash,
  },
  {
    id: uuidGen(10),
    title: "Starred Notes",
    isEditable: false,
    noteType: Starred,
    isSelected: false,
    filterFunction: (_element, note) => note.isStarred,
  },
  {
    id: uuidGen(10),
    title: "Trash",
    noteType: Trash,
    isEditable: false,
    isSelected: false,
    filterFunction: (_element, note) => note.isTrash,
  },
|];
open SynthesizedFileTreeElement;

let augmentMenuItems:
  (array(Note.note), array(NoteUIElement.noteUIElement)) =>
  array(SynthesizedFileTreeElement.synthesizedFileTreeElement) =
  (
    notes: array(Note.note),
    fileTreeElements: array(NoteUIElement.noteUIElement),
  ) => {
    Js.Array.map(
      (ftElement: NoteUIElement.noteUIElement) => {
        let filteredNotes =
          Js.Array.filter(
            (note: Note.note) => ftElement.filterFunction(ftElement, note),
            notes,
          );
        let noteLength = Js.Array.length(filteredNotes);
        {noteElement: ftElement, numNotes: noteLength};
      },
      fileTreeElements,
    );
  };

let initialBottomItems: array(NoteUIElement.noteUIElement) = [||];
open Actions;
let make = _children => {
  ...maple,

  initialState: () => {
    notes: [||],
    isLoaded: false,
    menuBarOpen: true,
    currentNote: None,
    isUserSignedIn: false,
    failureReason: None,
    email: "",
    currentFilterElement: initialTopItems[0],
    searchFilter: _note => true,
    topMenuItems: initialTopItems,
    bottomMenuItems: initialBottomItems,
  },

  reducer: (action, state) => {
    switch (action) {
    | SaveData =>
      saveData(state, app);
      ReasonReact.Update({...state, isUserSignedIn: true});
    | NewSerializedState(newState) =>
      let obj: option(serializedState) = deserializeState(newState);
      switch (obj) {
      | Some(remoteStateObj) =>
        let newNotes: array(Note.note) = remoteStateObj->notesGet;
        let isLoaded = remoteStateObj->isLoadedGet;
        let isUserSignedIn = remoteStateObj->isUserSignedInGet;
        let menuBarOpen = remoteStateObj->menuBarOpenGet;
        let bottomMenuItems = remoteStateObj->bottomMenuItemsGet;

        ReasonReact.Update({
          ...state,
          notes: newNotes,
          isLoaded,
          isUserSignedIn,
          menuBarOpen,
          bottomMenuItems,
        });
      | None => ReasonReact.Update({...state, isUserSignedIn: true})
      };

    | SignInUserFailed(reason) =>
      ReasonReact.Update({...state, failureReason: Some(reason)})
    | SignInUserSuccessfully(email) =>
      ReasonReact.Update({...state, isUserSignedIn: true, email})
    | SetEditableNote(noteId) =>
      let newNotes =
        Js.Array.map(
          (note: Note.note) =>
            if (note.noteID == noteId) {
              {...note, isEditable: true};
            } else {
              note;
            },
          state.notes,
        );
      ReasonReact.Update({...state, notes: newNotes});
    | UpdateBottomBarItem(newMenuItem) =>
      let updatedMenuItems =
        Js.Array.map(
          (menuItem: NoteUIElement.noteUIElement) =>
            if (menuItem.id == newMenuItem.id) {
              newMenuItem;
            } else {
              menuItem;
            },
          state.bottomMenuItems,
        );
      ReasonReact.Update({...state, bottomMenuItems: updatedMenuItems});
    | SetEditableBottomBarItem(menuItemId) =>
      let newBottomItems =
        Js.Array.map(
          (menuItem: NoteUIElement.noteUIElement) =>
            if (menuItem.id == menuItemId) {
              {...menuItem, isEditable: true};
            } else {
              menuItem;
            },
          state.bottomMenuItems,
        );
      ReasonReact.Update({...state, bottomMenuItems: newBottomItems});
    | DeleteBottomBarItem(menuItemId) =>
      let newBottomItems =
        Js.Array.filter(
          (bottomBarItem: NoteUIElement.noteUIElement) =>
            bottomBarItem.id != menuItemId,
          state.bottomMenuItems,
        );
      ReasonReact.Update({...state, bottomMenuItems: newBottomItems});
    | UpdateSearchFunction(searchString) =>
      if (searchString == "") {
        ReasonReact.Update({...state, searchFilter: _note => true});
      } else {
        ReasonReact.Update({
          ...state,
          searchFilter: note => {
            let regex = Js.Re.fromString(searchString);
            let result = Js.Re.exec(note.body, regex);
            let bodySearch =
              switch (result) {
              | Some(_) => true
              | None => false
              };

            let result = Js.Re.exec(note.title, regex);
            let titleSearch =
              switch (result) {
              | Some(_) => true
              | None => false
              };

            bodySearch || titleSearch;
          },
        });
      }
    | AddNewBottomBarItem =>
      let newBottomItem: NoteUIElement.noteUIElement = {
        id: uuidGen(10),
        title: "New Folder",
        isEditable: false,
        noteType: Folder(Utils.generateColor()),
        isSelected: false,
        filterFunction: (element, note) => note.folderID == element.id,
      };
      let newBottomItems =
        Js.Array.concat([|newBottomItem|], state.bottomMenuItems);

      ReasonReact.Update({...state, bottomMenuItems: newBottomItems});
    | TypeCurrentNote(inside) =>
      switch (state.currentNote) {
      | Some(currNote) =>
        let newNote = {...currNote, body: inside};
        ReasonReact.Update({...state, currentNote: Some(newNote)});
      | None => ReasonReact.Update({...state, currentNote: None})
      }
    | SelectMenuBarItem((element: NoteUIElement.noteUIElement)) =>
      let newTopMenuItems =
        Js.Array.map(
          (oldElement: NoteUIElement.noteUIElement) =>
            if (oldElement.id == element.id) {
              {...element, isSelected: true};
            } else {
              {...oldElement, isSelected: false};
            },
          state.topMenuItems,
        );
      let newBottomMenuItems =
        Js.Array.map(
          (oldElement: NoteUIElement.noteUIElement) =>
            if (oldElement.id == element.id) {
              {...element, isSelected: true};
            } else {
              {...oldElement, isSelected: false};
            },
          state.bottomMenuItems,
        );
      ReasonReact.Update({
        ...state,
        currentFilterElement: element,
        topMenuItems: newTopMenuItems,
        currentNote: None,
        bottomMenuItems: newBottomMenuItems,
      });
    | SelectNote((note: Note.note)) =>
      let notes =
        Js.Array.map(
          (oldNote): Note.note =>
            if (oldNote.noteID == note.noteID) {
              {...note, isSelected: true};
            } else {
              switch (state.currentNote) {
              | Some(currNote) =>
                if (currNote.noteID == oldNote.noteID) {
                  {...currNote, isSelected: false};
                } else {
                  {...oldNote, isSelected: false};
                }
              | None => {...oldNote, isSelected: false}
              };
            },
          state.notes,
        );
      ReasonReact.Update({...state, notes, currentNote: Some(note)});
    | EditNote((note: Note.note)) =>
      let notes =
        Js.Array.map(
          (oldNote): Note.note =>
            if (oldNote.noteID == note.noteID) {
              note;
            } else {
              oldNote;
            },
          state.notes,
        );
      switch (state.currentNote) {
      | Some(currNote) =>
        currNote.noteID == note.noteID ?
          ReasonReact.Update({...state, notes, currentNote: Some(note)}) :
          ReasonReact.Update({...state, notes})

      | None => ReasonReact.Update({...state, notes})
      };

    | AddNewNote(_noteID) =>
      let noteID2 = uuidGen(20);
      let note: Note.note = {
        noteID: noteID2,
        title: "New Note",
        body: "",
        timestamp: [%bs.raw {| Date.now() |}],
        isEditable: false,
        isStarred: false,
        isSelected: false,
        isTrash: false,
        folderID: state.currentFilterElement.id,
      };

      ReasonReact.Update({
        ...state,
        notes: Js.Array.concat([|note|], state.notes),
      });
    | ToggleMenuBar =>
      ReasonReact.Update({...state, menuBarOpen: !state.menuBarOpen})
    };
  },

  render: self => {
    let updateFunction = _value => {
      let bodyText = [%bs.raw {| _value() |}];
      self.send(TypeCurrentNote(bodyText));
    };
    let editorView =
      switch (self.state.currentNote) {
      | Some(note) =>
        <div style=editorContainerStyle>
          <Editor
            key={note.noteID}
            onChange=updateFunction
            defaultValue={note.body}
            autoFocus=true
            placeholder="Write Anything..."
          />
        </div>
      | None => <div />
      };
    let filteredNotes =
      Js.Array.filter(
        self.state.currentFilterElement.filterFunction(
          self.state.currentFilterElement,
        ),
        self.state.notes,
      );
    let searchFilteredNotes =
      Js.Array.filter(self.state.searchFilter, filteredNotes);
    let noteApplication =
      <div style=appStyle>
        <ReactFiletree
          topItems={augmentMenuItems(
            self.state.notes,
            self.state.topMenuItems,
          )}
          bottomItems={augmentMenuItems(
            self.state.notes,
            self.state.bottomMenuItems,
          )}
          dispatch={self.send}
          isOpen={self.state.menuBarOpen}
        />
        <NoteListRe dispatch={self.send} notes=searchFilteredNotes />
        editorView
      </div>;
    let signinPage =
      <SigninPage
        app
        failureReason={self.state.failureReason}
        dispatch={self.send}
      />;
    self.state.isUserSignedIn ? noteApplication : signinPage;
  },
};