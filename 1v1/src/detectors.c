/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble detectors
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

static int someone_won(char *p)
{
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '7') && my_c_isinstr(p, '6'))
        return (TRUE);
    if (my_c_isinstr(p, '9') && my_c_isinstr(p, '5') && my_c_isinstr(p, '1'))
        return (TRUE);
    if (my_c_isinstr(p, '4') && my_c_isinstr(p, '3') && my_c_isinstr(p, '8'))
        return (TRUE);
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '9') && my_c_isinstr(p, '4'))
        return (TRUE);
    if (my_c_isinstr(p, '7') && my_c_isinstr(p, '5') && my_c_isinstr(p, '3'))
        return (TRUE);
    if (my_c_isinstr(p, '6') && my_c_isinstr(p, '1') && my_c_isinstr(p, '8'))
        return (TRUE);
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '5') && my_c_isinstr(p, '8'))
        return (TRUE);
    if (my_c_isinstr(p, '6') && my_c_isinstr(p, '5') && my_c_isinstr(p, '4'))
        return (TRUE);
    return (FALSE);
}

int is_win(data *game)
{
    if (someone_won(game->player1) ||
        someone_won(game->player2))
        return (TRUE);
    return (FALSE);
}

int is_there_any_nb_left(data *game)
{
    for (uint i = 0; game->board[i]; i++)
        if (game->board[i] != '-')
            return (YES);
    return (NO);
}

int switch_turn(int id)
{
    int save = id;

    if (save == PLAYER1)
        id = PLAYER2;
    if (save == PLAYER2)
        id = PLAYER1;
    return (id);
}
