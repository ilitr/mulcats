#include "wordlist_service.h"

int start_scp_session(ssh_session* session) {
    ssh_scp scp;
    int rc;

    scp = ssh_scp_new(*session, SSH_SCP_WRITE | SSH_SCP_RECURSIVE, ".");
    if(scp == NULL){
        fprintf(stderr, "ERROR allocating scp session: %s\n",
                ssh_get_error(*session));
    }

    rc = ssh_scp_init(scp);
    if (rc != SSH_OK) {
        fprintf(stderr, "Error initializing scp session: %s\n",
                ssh_get_error(*session));
        ssh_scp_free(scp);
        return rc;
    }

    return 0;
}

int split_wordlist(char* filepath, int number_of_splits) {
    char* split_path = "/usr/bin/split";
    struct stat st;

    lstat(filepath, &st);
    int wordlist_size = st.st_size;

    int split_each_to_size = (int)(ceil((float)wordlist_size/(float)number_of_splits));
    int length_for_snprintf = snprintf(NULL, 0, "%d", split_each_to_size);
    char* str_split_each_to_size = malloc(length_for_snprintf + 1);
    snprintf(str_split_each_to_size, length_for_snprintf + 1, "%d", split_each_to_size);

    execl(split_path, "-C", str_split_each_to_size ,"--numeric-suffixes", "filepath", "noways_split");

    return 0;
}
