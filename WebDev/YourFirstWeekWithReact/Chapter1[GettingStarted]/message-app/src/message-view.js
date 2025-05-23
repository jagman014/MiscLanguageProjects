import React from "react";
import PropTypes from 'prop-types';

const MessageView = ({message}) => {
    const {from, status, content} = message;

    return (
        <div className="message">
            <div className="field">
                <span className="label">From: </span>
                <span className="value">{from}</span>
            </div>
            <div className="field">
                <span className="label">Status: </span>
                <span className="value">{status}</span>
            </div>
            <div className="field content">
                <span className="label">Message: </span>
                <span className="value">{content}</span>
            </div>
        </div>
    );
};

MessageView.propTypes = {
    message: PropTypes.object.isRequired
}

export default MessageView;
