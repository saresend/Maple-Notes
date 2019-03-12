import React from 'react';
import { ContextMenu, MenuItem, ContextMenuTrigger } from "react-contextmenu";

const onClick = ({ event, props }) => console.log(event, props);

const menuItemStyle = {
  "fontFamily": "Aleo",
  "margin": "0px",
}

const menuContainerStyle = {
  "backgroundColor": "#ffffff",
  "padding": "0px",
  "borderWidth": "1px",
  "borderColor": "gray",
  "borderStyle": "solid",
  "borderRadius": "10px",
}

const menuTextStyle = {
  "padding": "5px",
  "marginTop": "5px",
  "marginBottom": "5px",
  "marginRight": "40px",
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
          <MenuItem style={menuItemStyle} data={{ foo: 'bar' }} onClick={this.handleClick}>
            <p className="contextMenuHover" style={menuTextStyle}>Rename</p>
          </MenuItem>
          <MenuItem style={menuItemStyle} data={{ foo: 'bar' }} onClick={this.handleClick}>
            <p className="contextMenuHover" style={menuTextStyle}>Delete</p>
          </MenuItem>
        </ContextMenu>
      </div>

    )
  }
}