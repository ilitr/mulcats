/**
 * Helper functions for dealing with Wordlists
 */

#ifndef WORDLIST_SERVICE_H_
#define WORDLIST_SERVICE_H_

#include <unistd.h>
#include <sys/stat.h>
#include <math.h>
#include <stdio.h>

#include "ssh_utils.h"

int start_scp_session(ssh_session* session);
int split_wordlist(char* filepath, int number_of_splits);
int send_wordlist(ssh_session, char* filename);
int delete_wordlist(ssh_session, char* filename);
int end_scp_session(ssh_session* session);


#endif // __WORDLIST_SERVICE_H_
