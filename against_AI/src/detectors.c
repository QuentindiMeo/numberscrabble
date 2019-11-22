/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble detectors
*/

#include "../include/my.h"
#include "../include/numberscrabble.h"

static int win_by(char n1, char n2, char n3)
{
    my_putchar(n1);
    my_putstr(" + ");
    my_putchar(n2);
    my_putstr(" + ");
    my_putchar(n3);
    my_putstr(" = 15\n");
    return (TRUE);
}

static int someone_won(char *p, int id)
{
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '7') && my_c_isinstr(p, '6'))
        return (id ? win_by('2', '7', '6') : TRUE);
    if (my_c_isinstr(p, '9') && my_c_isinstr(p, '5') && my_c_isinstr(p, '1'))
        return (id ? win_by('9', '5', '1') : TRUE);
    if (my_c_isinstr(p, '4') && my_c_isinstr(p, '3') && my_c_isinstr(p, '8'))
        return (id ? win_by('4', '3', '8') : TRUE);
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '9') && my_c_isinstr(p, '4'))
        return (id ? win_by('2', '9', '4') : TRUE);
    if (my_c_isinstr(p, '7') && my_c_isinstr(p, '5') && my_c_isinstr(p, '3'))
        return (id ? win_by('7', '5', '3') : TRUE);
    if (my_c_isinstr(p, '6') && my_c_isinstr(p, '1') && my_c_isinstr(p, '8'))
        return (id ? win_by('6', '1', '8') : TRUE);
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '5') && my_c_isinstr(p, '8'))
        return (id ? win_by('2', '5', '8') : TRUE);
    if (my_c_isinstr(p, '6') && my_c_isinstr(p, '5') && my_c_isinstr(p, '4'))
        return (id ? win_by('6', '5', '4') : TRUE);
    return (FALSE);
}

int is_win(data *game, int id)
{
    if (someone_won(game->player1, id) ||
        someone_won(game->player2, id))
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

    if (save == USER)
        id = AI;
    if (save == AI)
        id = USER;
    return (id);
}
