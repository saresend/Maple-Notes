type elementType =
  | Folder(string)
  | NoteBook
  | Trash
  | Starred;

type noteUIElement = {
  id: string,
  title: string,
  isEditable: bool,
  numNotes: int,
  noteType: elementType,
  isSelected: bool,
  filterFunction: (noteUIElement, Note.note) => bool,
};