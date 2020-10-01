/**
 * Helper functions for making SSH connections
 */

#ifndef SSH_UTILS_H_
#define SSH_UTILS_H_

#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int create_connection(ssh_session*, char*);
int authenticate_server_connection(ssh_session);
int end_connection(ssh_session*);

#endif // __SSH_UTILS_H_
