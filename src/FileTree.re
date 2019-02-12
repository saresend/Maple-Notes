let component = ReasonReact.statelessComponent("FileTree");

let fileTreeStyle =
  ReactDOMRe.Style.make(
    ~minWidth="20vw",
    ~marginRight="20px",
    ~padding="20px",
    ~borderRight="solid #898989 1px",
    ~minHeight="100vh",
    (),
  );

let titleStyle = ReactDOMRe.Style.make(~margin="5px", ());

let make = (~files: array(DirItem.dirItem), _children) => {
  ...component,
  render: _self => {
    let components =
      Js.Array.map(
        item =>
          switch (item) {
          | DirItem.Folder(title, folderItems) =>
            <FolderviewRe title folderItems />
          | DirItem.Note(note) => <Noteview note />
          },
        files,
      );
    <div style=fileTreeStyle>
      <p style=titleStyle> {ReasonReact.string("Notes")} </p>
      <hr />
      {ReasonReact.array(components)}
    </div>;
  },
};