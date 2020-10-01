/**
 * Helper functions for bruteforcing passwords
 */

#ifndef BRUTEFORCE_PASSWORDS_H_
#define BRUTEFORCE_PASSWORDS_H_

#include <stdbool.h>
#include "ssh_utils.h"

char* generate_hashcat_keyspace(size_t size, bool toggle_nums, bool toggle_upper_chars,
                                bool toggle_lower_chars, bool toggle_special_chars);
char** distribute_keyspace_per_node(size_t number_of_nodes, char* keyspace);
int perform_bruteforce_on_nodes(char** array_of_keyspaces);

#endif // BRUTEFORCE_PASaSWORDS_H_
