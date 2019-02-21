type elementType =
  | Folder
  | NoteBook
  | Trash
  | Starred;

type noteUIElement = {
  title: string,
  numNotes: int,
  noteType: elementType,
};