import React from 'react';
import { Spring } from 'react-spring/renderprops';
import FileTreeRe from '../FileTree.bs';

export default class Folderview extends React.Component {

    render() {

        const toWidth = this.props.isOpen ? 250 : 40;
        const fromWidth = this.props.isOpen ? 40 : 250;
        const toOpacity = this.props.isOpen ? 1 : 0;
        const fromOpacity = this.props.isOpen ? 0 : 1;
        return (
            <Spring
                to={{ width: toWidth, opacity: toOpacity }}
                from={{ width: fromWidth, opacity: fromOpacity }}
            >
                {(props) => <FileTreeRe width={props.width + "px"} opacity={props.opacity + ""} />}
            </Spring>

        );


    }
}