type dirItem =
  | Folder(string, array(dirItem))
  | Note(Note.note);