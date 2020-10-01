#include "bruteforce_passwords.h"

char* generate_hashcat_keyspace(size_t size, bool toggle_nums, bool toggle_upper_chars,
                                bool toggle_lower_chars, bool toggle_special_chars) {
    static char hashcat_masks[1000] = "";

    if(!toggle_nums && !toggle_lower_chars && !toggle_upper_chars && !toggle_special_chars) {
        printf("Select one parameter minimum.\n");
        exit(EXIT_FAILURE);
    }

    if(size == 0)
        printf("Size should be greater than 0.");

    if(toggle_nums)
        for(size_t i = 0; i < size; i++)
            strcat(hashcat_masks, "?d");

    if(toggle_upper_chars)
        for(size_t i = 0; i < size; i++)
            strcat(hashcat_masks, "?u");

    if(toggle_lower_chars)
        for(size_t i = 0; i < size; i++)
            strcat(hashcat_masks, "?l");

    if(toggle_special_chars)
        for(size_t i = 0; i < size; i++)
            strcat(hashcat_masks, "?s");

    return hashcat_masks;
}
