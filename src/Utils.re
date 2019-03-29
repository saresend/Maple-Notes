[@bs.val] external random: unit => float = "Math.random";
[@bs.val] external floor: float => int = "Math.float";
let genRandomValue = (min: int, max: int) => {
  let diff = max - min;
  let randValue = random() *. float_of_int(diff) +. float_of_int(min);
  int_of_float(randValue);
};

let generateColor = () => {
  let colorSet = [|
    "#5fcc82",
    "#24d8b4",
    "#4f30cc",
    "#e71d36",
    "#53b3cb",
    "#f15946",
    "#7999e0",
    "#a9efa5",
    "#ff8ea1",
  |];
  let index = genRandomValue(0, Js.Array.length(colorSet));
  colorSet[index];
};

// This only exists because react doesn't know about Reason enum types, so
// we wrap the function call in a reason function that gets exposed to react
// instead.
let sendDeleteFolderMessage = (dispatchFunc, messageId) => {
  dispatchFunc(Actions.DeleteBottomBarItem(messageId));
};

let sendDeleteNoteMessage = (dispatchFunc, messageId) => {
  dispatchFunc(Actions.DeleteNote(messageId));
};

let sendRenameFolderMessage = (dispatchFunc, messageId) => {
  dispatchFunc(Actions.SetEditableBottomBarItem(messageId));
};

let sendRenameNoteMessage = (dispatchFunc, messageId) => {
  dispatchFunc(Actions.SetEditableNote(messageId));
};