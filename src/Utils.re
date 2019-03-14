[@bs.val] external random: unit => float = "Math.random";
[@bs.val] external floor: float => int = "Math.float";
let genRandomValue = (min: int, max: int) => {
  let diff = max - min;
  let randValue = random() *. float_of_int(diff) +. float_of_int(min);
  int_of_float(randValue);
};

let generateColor = () => {
  let colorSet = [|
    "#f2a541",
    "#f3ca40",
    "#36f1cd",
    "#13c4a3",
    "#80ced7",
    "#9e1946",
    "#6df287",
    "#4ce0d2",
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

let sendRenameNoteMessage = (dispatchFunc, messageId) => {
  dispatchFunc(Actions.SetEditableNote(messageId));
};