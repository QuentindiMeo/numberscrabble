/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** setup2 number scrabble
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/numberscrabble.h"

static char *free2(char *s1)
{
    free(s1);
    return (NULL);
}

static char *get_name2(data **game)
{
    char *entry = NULL;
    size_t buff = 0;

    for (int ret_v = 1; ret_v == 1;) {
        my_putstr("Enter Player 2's name: ");
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (free2(entry));
        free((*game)->name2);
        (*game)->name2 = my_cut_str(entry, 0, my_strlen(entry) - 2);
        if (my_str_isblank((*game)->name2) ||
            my_str_isequal((*game)->name1, (*game)->name2)) {
            my_putstr("Error: invalid name\n");
            ret_v = 1;
        }
    }
    free(entry);
    return ("-");
}

static char *get_name1(data **game)
{
    char *entry = NULL;
    size_t buff = 0;

    for (int ret_v = 1; ret_v == 1;) {
        my_putstr("Enter Player 1's name: ");
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (free2(entry));
        free((*game)->name1);
        (*game)->name1 = my_cut_str(entry, 0, my_strlen(entry) - 2);
        if (my_str_isblank((*game)->name1)) {
            my_putstr("Error: invalid name\n");
            ret_v = 1;
        }
    }
    free(entry);
    return ("-");
}

char *get_names(data **game)
{
    if (get_name1(game) == NULL)
        return ("n");
    if (get_name2(game) == NULL)
        return ("n");
    return ("-");
}
