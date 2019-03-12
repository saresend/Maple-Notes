import React from 'react';
import { ContextMenu, MenuItem, ContextMenuTrigger } from "react-contextmenu";

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

  handleClick(e, data) {
    console.log('Something was clicked');
  }

  render() {
    return (
      <div>
        <ContextMenuTrigger id="some_unique_identifier">
          {this.props.children}
        </ContextMenuTrigger>
        <ContextMenu id="some_unique_identifier" style={menuContainerStyle}>
          <span style={titleMenuTextStyle}> Options </span>
          <MenuItem style={menuItemStyle} data={{ foo: 'bar' }} onClick={this.handleClick}>
            <div style={horizContainerStyle} className="contextMenuHover">
              <p style={menuTextStyle}>Rename Folder</p>
              <i style={iconStyle} class="fas fa-pencil-alt" />
            </div>

          </MenuItem>
          <MenuItem style={menuItemStyle} data={{ foo: 'bar' }} onClick={this.handleClick}>
            <div style={horizContainerStyle} className="contextMenuHover">
              <p className="contextMenuHover" style={menuTextStyle}>Delete Folder</p>
              <i style={iconStyle} class="fas fa-trash-alt" />
            </div>
          </MenuItem>
        </ContextMenu>
      </div>

    )
  }
}