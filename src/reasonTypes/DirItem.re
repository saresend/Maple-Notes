type dirItem =
  | TopLevel(array(dirItem))
  | Folder(string, array(dirItem))
  | Note(Note.mapleNote);