type action =
  | AddNewBottomBarItem
  | UpdateSearchFunction(string)
  | SelectNote(Note.note)
  | TypeCurrentNote(string)
  | EditNote(Note.note)
  | AddNewNote(string)
  | SelectMenuBarItem(NoteUIElement.noteUIElement)
  | ToggleMenuBar;