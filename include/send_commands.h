/**
 * Open a SSH channel and send commands to controlled nodes
 */

#ifndef SEND_COMMANDS_H_
#define SEND_COMMANDS_H_

#include "ssh_utils.h"

int open_channel(ssh_session*, ssh_channel*);
int send_command(ssh_channel*, char*);
int read_channel(ssh_channel*);
int end_channel(ssh_channel*);

#endif // SEND_COMMANDS_H_
