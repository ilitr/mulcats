#include "send_commands.h"

/**
 * Open a channel to the SSH Session.
 * @param[in] noways SSH Session to create a channel to.
 * @param[in] channel SSH Channel that will connect to the SSH Session.
 */
int open_channel(ssh_session* noways, ssh_channel* channel) {
    int rc;

    *channel = ssh_channel_new(*noways);
    if(*channel == NULL)
        return SSH_ERROR;

    rc = ssh_channel_open_session(*channel);
    if(rc != SSH_OK) {
        ssh_channel_free(*channel);
        return rc;
    }

    return 0;
}

/**
 * Send command to the SSH Channel.
 * @param[in] channel Channel to send command to.
 * @param[in] command Command to send to the SSH Channel.
 */
int send_command(ssh_channel* channel, char* command) {
    int rc;
   
    rc = ssh_channel_request_exec(*channel, command);
    if(rc != SSH_OK) {
        ssh_channel_close(*channel);
        ssh_channel_free(*channel);
        return rc;
    }

    return 0;
}

/**
 * Read output of a command from SSH Channel.
 * @param[in] channel Channel to read output of SSH Command from.
 */
int read_channel(ssh_channel* channel) {
    char buffer[1024];
    unsigned long nbytes;

    nbytes = ssh_channel_read(*channel, buffer, sizeof(buffer), 0);
    while(nbytes > 0) {
        if(fwrite(buffer, 1, nbytes, stdout) != nbytes) {
            ssh_channel_close(*channel);
            ssh_channel_free(*channel);
            return SSH_ERROR;
        }
        nbytes = ssh_channel_read(*channel, buffer, sizeof(buffer), 0);
    }

    if (nbytes < 0) {
        ssh_channel_close(*channel);
        ssh_channel_free(*channel);
        return SSH_ERROR;
    }

    return 0;
}

/**
 * Close the SSH Channel.
 * @param[in] channel SSH channel to be closed.
 */
int end_channel(ssh_channel* channel) {
    ssh_channel_send_eof(*channel);
    ssh_channel_close(*channel);
    ssh_channel_free(*channel);

    return SSH_OK;
}
