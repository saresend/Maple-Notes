let component = ReasonReact.statelessComponent("NoteDescriptionViewRe");

let containerStyle =
  ReactDOMRe.Style.make(
    ~margin="5px",
    ~padding="5px",
    ~borderBottom="1px solid #dddddd",
    (),
  );

let unselectedTitleStyle =
  ReactDOMRe.Style.make(
    ~fontSize="17px",
    ~color="#999999",
    ~margin="10px",
    (),
  );

let selectedTitleStyle =
  ReactDOMRe.Style.make(
    ~fontSize="17px",
    ~color="#48d3f2",
    ~margin="10px",
    (),
  );

let iconStyle =
  ReactDOMRe.Style.make(
    ~fontSize="16px",
    ~color="#999999",
    ~marginRight="10px",
    (),
  );

let horizontalStyle =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="flex-start",
    ~alignItems="center",
    (),
  );

let spaceAroundHoriz =
  ReactDOMRe.Style.make(
    ~display="flex",
    ~flexDirection="row",
    ~justifyContent="space-between",
    ~alignItems="center",
    (),
  );

let timeStampStyle =
  ReactDOMRe.Style.make(
    ~fontSize="13px",
    ~color="#aaaaaa",
    ~margin="4px",
    (),
  );

let unhighlightedBookmark =
  ReactDOMRe.Style.make(~fontSize="15px", ~color="#aaaaaa", ());
let highlightedBookmark =
  ReactDOMRe.Style.make(~fontSize="15px", ~color="#48d3f2", ());

let make = (~dispatch, ~note: Note.note, _children) => {
  ...component,
  render: _self => {
    let dateString = [%bs.raw
      {|
      function (note) {
        var a = new Date(note[3]);
        var months = ['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sep','Oct','Nov','Dec'];
        var year = a.getFullYear();
        var month = months[a.getMonth()];
        var date = a.getDate();
        var hour = a.getHours();
        var min = a.getMinutes();
        var sec = a.getSeconds();
        var time = month + ' ' + date + ',  ' + year;
        return time;
      }
    |}
    ];
    let titleStyle =
      note.isSelected ? selectedTitleStyle : unselectedTitleStyle;
    let bookmarkStyle =
      note.isStarred ? highlightedBookmark : unhighlightedBookmark;
    <div style=containerStyle>
      <div
        style=horizontalStyle
        onClick={_data => dispatch(Actions.SelectNote(note))}>
        <i style=iconStyle className="far fa-file-alt" />
        <input
          style=titleStyle
          value={note.title}
          onChange={_data => {
            let noteTitle: string = [%bs.raw {| _data.target.value |}];
            let newNote: Note.note = {...note, title: noteTitle};
            dispatch(Actions.EditNote(newNote));
          }}
        />
      </div>
      <div style=spaceAroundHoriz>
        <p style=timeStampStyle> {ReasonReact.string(dateString(note))} </p>
        <i
          style=bookmarkStyle
          className="fas fa-bookmark hover"
          onClick={_data => {
            let newNote = {...note, isStarred: !note.isStarred};
            dispatch(Actions.EditNote(newNote));
          }}
        />
      </div>
    </div>;
  },
};