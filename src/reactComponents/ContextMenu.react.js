import React from 'react';
import { ContextMenu, MenuItem, ContextMenuTrigger } from "react-contextmenu";
import { sendDeleteFolderMessage, sendRenameFolderMessage, sendRenameNoteMessage } from "../utils.bs";

const onClick = ({ event, props }) => console.log(event, props);

const menuItemStyle = {
  "fontFamily": "Aleo",
  "margin": "0px",
}

const menuContainerStyle = {
  "backgroundColor": "#ffffff",
  "padding": "15px",
  "borderWidth": "1px",
  "borderColor": "gray",
  "borderStyle": "solid",
  "borderRadius": "4px",
}

const menuTextStyle = {
  "padding": "5px",
  "marginTop": "5px",
  "marginBottom": "5px",
  "marginRight": "40px",
  "fontSize": "17px",
}

const titleMenuTextStyle = {
  "marginLeft": "5px",
  "marginTop": "10px",
  "fontFamily": "Aleo",
  "color": "#aaaaaa",
}

const horizContainerStyle = {
  "display": "flex",
  "flexDirection": "row",
  "justifyContent": "space-between",
  "alignItems": "center",
}

const iconStyle = {
  "fontSize": "17px",
}

export default class ContextMenuReact extends React.Component {

  constructor(props) {
    super(props);
    this.deleteFolder = this.deleteFolder.bind(this);
    this.renameFolder = this.renameFolder.bind(this);
  }

  deleteFolder() {
    if (this.props.suffix === "Folder") {
      sendDeleteFolderMessage(this.props.dispatch, this.props.menuId);
    }
    else {

    }

  }

  renameFolder() {
    console.log(this.props.suffix);
    if (this.props.suffix === "Folder") {
      sendRenameFolderMessage(this.props.dispatch, this.props.menuId);
    }
    else {
      sendRenameNoteMessage(this.props.dispatch, this.props.menuId);
    }
  }

  render() {
    return (
      <div>
        <ContextMenuTrigger id={this.props.menuId}>
          {this.props.children}
        </ContextMenuTrigger>
        <ContextMenu id={this.props.menuId} style={menuContainerStyle}>
          <span style={titleMenuTextStyle}> Options </span>
          <MenuItem style={menuItemStyle} onClick={this.renameFolder}>
            <div style={horizContainerStyle}
              className="contextMenuHover">
              <p style={menuTextStyle}>Rename {this.props.suffix}</p>
              <i style={iconStyle} className="fas fa-pencil-alt" />
            </div>
          </MenuItem>
          <MenuItem style={menuItemStyle} onClick={this.deleteFolder}>
            <div style={horizContainerStyle} className="contextMenuHover">
              <p className="contextMenuHover" style={menuTextStyle}>Delete {this.props.suffix}</p>
              <i style={iconStyle} className="fas fa-trash-alt" />
            </div>
          </MenuItem>
        </ContextMenu>
      </div >

    )
  }
}