import React from 'react';
import { ContextMenu, MenuItem, ContextMenuTrigger } from "react-contextmenu";

const onClick = ({ event, props }) => console.log(event, props);

export default class ContextMenuReact extends React.Component {

  handleClick(e) {
    console.log('Something was clicked');
  }

  render() {
    return (
      <div>
        <ContextMenuTrigger id="some_unique_identifier">
          {this.props.children}
        </ContextMenuTrigger>
        <ContextMenu id="some_unique_identifier" style={{ "backgroundColor": "#ffffff" }}>
          <MenuItem data={{ foo: 'bar' }} onClick={this.handleClick}>
            ContextMenu Item 1
        </MenuItem>
          <MenuItem data={{ foo: 'bar' }} onClick={this.handleClick}>
            ContextMenu Item 2
        </MenuItem>
          <MenuItem divider />
          <MenuItem data={{ foo: 'bar' }} onClick={this.handleClick}>
            ContextMenu Item 3
        </MenuItem>
        </ContextMenu>
      </div>

    )
  }
}