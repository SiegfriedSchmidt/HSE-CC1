#include <stdio.h>
#include <string.h>

const int MAX_WORDS = 60;
const int MAX_WORD_CHARS = 20;
const int MAX_CHARS = MAX_WORDS * MAX_WORD_CHARS;

int main(void) {
    char original_string[MAX_CHARS];
    fgets(original_string, MAX_CHARS, stdin);
    original_string[strlen(original_string) - 2] = '\0';

    char string[MAX_CHARS];
    strcpy(string, original_string);

    char *rest = string;
    char *tok;

    int n_words = 0;
    char words[MAX_WORDS][MAX_WORD_CHARS];

    while ((tok = strtok_r(rest, " ", &rest))) {
        char word[MAX_WORD_CHARS];

        for (int i = 0;; ++i, ++tok) {
            word[i] = *tok;
            if (*tok == '\0') break;
        }

        unsigned int len = strlen(word);

        // if (word[len - 1] == '.') {
        //     word[len - 1] = '\0';
        //     --len;
        // }

        if (len % 2 == 0) {
            for (int i = 0; i <= len; ++i) {
                words[n_words][i] = word[i];
            }
        } else {
            for (int i = 0; i <= len; ++i) {
                if (i == len / 2) continue;
                if (i > len / 2) {
                    words[n_words][i - 1] = word[i];
                } else {
                    words[n_words][i] = word[i];
                }
            }
        }

        ++n_words;
    }

    for (int i = 0; i < n_words; ++i) {
        if (strcmp(words[i], words[n_words - 1]) != 0)
            printf("%s\n", words[i]);
    }

    printf("%s", original_string);

    return 0;
}

/*
Lorem ipsum dolor sit labrum labrum labrum amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua  Ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat  Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur  Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum.
*/
