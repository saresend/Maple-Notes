import React from 'react';
import { Spring } from 'react-spring/renderprops';
import FileTreeRe from '../FileTree.bs';

export default class Folderview extends React.Component {

    render() {

        const toWidth = this.props.isOpen ? 250 : 20;
        const fromWidth = this.props.isOpen ? 20 : 250;
        const toOpacity = this.props.isOpen ? 1 : 0;
        const fromOpacity = this.props.isOpen ? 0 : 1;
        return (
            <Spring
                to={{ width: toWidth, opacity: toOpacity }}
                from={{ width: fromWidth, opacity: fromOpacity }}
            >
                {(props) => <FileTreeRe dispatch={this.props.dispatch} width={props.width + "px"} opacity={props.opacity + ""} />}
            </Spring>

        );


    }
}