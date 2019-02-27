type action =
  | SelectNote(Note.note)
  | EditNote(Note.note)
  | AddNewNote(string)
  | SelectMenuBarItem(NoteUIElement.noteUIElement)
  | ToggleMenuBar;