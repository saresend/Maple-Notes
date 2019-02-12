// This file isn't used directly by JS; it's used to myBanner.re, which is then
// used by the ReasonReact component GreetingRe.

import React from 'react';
var Noteview = require('../reasonComponents/Noteview.bs').jsComponent;

/*
[@bs.deriving abstract]
type jsProps = {
  title: string,
  folderItems: array(DirItem.dirItem),
};
*/
const iconStyle = {
    width: "25px",
    height: "25px",
    marginRight: "10px",
}

const barStyle = {
    padding: "0px",
    display: "flex",
    flexDirection: "row",
    alignItems: "center",
}

const titleStyle = {
    margin: "6px",
    fontSize: "20px",
    color: "#73a6ad",
}
export default class Folderview extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            folded: false,
        }
    }
    render() {
        if (!this.props.folderItems) {
            return null;
        }
        const components = this.props.folderItems.map((element) => {
            console.log(element);
            if (element.len == 3) {
                /* Its a note */
                return (<Noteview note={element} />);
            }
            else {
                /* Its a folder */
                return (
                    <div style={{ paddingLeft: "20px" }}>
                        <Folderview title={element[0]} folderItems={element[1]} />
                    </div>
                );
            }
        });

        const icon = this.state.folded ?
            "https://img.icons8.com/ios/50/000000/sort-right.png" :
            "https://img.icons8.com/ios/50/000000/sort-down.png";

        return (
            <div>
                <div style={barStyle}
                    onClick={() => { this.setState({ folded: !this.state.folded }) }}>
                    <img src={icon} style={iconStyle} />
                    <p style={titleStyle}> {this.props.title} </p>
                </div>
                {!this.state.folded && components}
            </div>
        );
    }
}