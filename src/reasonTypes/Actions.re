type action =
  | SaveData
  | NewSerializedState(Js.Json.t)
  | SignInUserSuccessfully(string)
  | SignInUserFailed(string)
  | UpdateBottomBarItem(NoteUIElement.noteUIElement)
  | SetEditableBottomBarItem(string)
  | DeleteBottomBarItem(string)
  | AddNewBottomBarItem
  | UpdateSearchFunction(string)
  | SelectNote(Note.note)
  | TypeCurrentNote(string)
  | EditNote(Note.note)
  | AddNewNote(string)
  | SetEditableNote(string)
  | SelectMenuBarItem(NoteUIElement.noteUIElement)
  | ToggleMenuBar;