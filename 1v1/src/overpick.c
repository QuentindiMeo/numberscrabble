/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble overpicking detector
*/

#include "../include/my.h"
#include "../include/numberscrabble.h"

int check_played_nb(data *game)
{
    char c = itoc(game->played_n);

    if (!my_c_isinstr(game->board, c))
        return (FAILURE);
    return (SUCCESS);
}
