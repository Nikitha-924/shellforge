#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <readline/history.h>
#include <readline/readline.h>

#include "history.h"
#include "lexer.h"
#include "token.h"

int main(void)
{
    // Display a welcome banner when the shell starts
    printf("=====================================\n");
    printf("      Shellforge\n");
    printf(" A Unix Style Shell written in C\n");
    printf("=====================================\n");

    // Initializing History
    using_history();

    char *line;

    while (1)
    {
        line = readline("shellforge$ ");

        if (line == NULL)
        {
            printf("\nGoodbye!\n");
            break;
        }

        if (strlen(line) == 0)
        {
            free(line);
            continue;
        }

        // History command
        if (strcmp(line, "history") == 0)
        {
            print_history();
            free(line);
            continue;
        }

        // Add input line to history
        add_history(line);

        printf("YOU ENTERED : %s\n", line);

        // Exit command
        if (strcmp(line, "exit") == 0)
        {
            free(line);
            printf("Exiting...\n");
            break;
        }

        // Lexical analysis
        token_list_t list;

        lexer(line, &list);

        // Display tokens
        token_print(&list);

        free(line);
    }

    return 0;
}
