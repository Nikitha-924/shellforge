#ifndef TOKEN_H
#define TOKEN_H

typedef enum
{
    TOKEN_WORD,
    TOKEN_INPUT,
    TOKEN_OUTPUT,
    TOKEN_PIPE
} token_type_t;

typedef struct
{
    token_type_t type;
    char *value;
} token_t;

typedef struct
{
    token_t *tokens;
    int count;
    int capacity;
} token_list_t;

void token_add(token_list_t *list, token_type_t type, const char *value);

#endif
