/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble ai denying player
*/

#include "../../include/my.h"
#include "../../include/numberscrabble.h"

void choose_diamond(data **g)
{
    if ((*g)->board[6] != EMP) {
        (*g)->played_n = 7;
        return;
    }
    if ((*g)->board[8] != EMP) {
        (*g)->played_n = 9;
        return;
    }
    if ((*g)->board[0] != EMP) {
        (*g)->played_n = 1;
        return;
    }
    if ((*g)->board[2] != EMP) {
        (*g)->played_n = 3;
        return;
    }
}

void choose_corners(data **g)
{
    if ((*g)->board[1] != EMP) {
        (*g)->played_n = 2;
        return;
    }
    if ((*g)->board[5] != EMP) {
        (*g)->played_n = 6;
        return;
    }
    if ((*g)->board[3] != EMP) {
        (*g)->played_n = 4;
        return;
    }
    if ((*g)->board[7] != EMP) {
        (*g)->played_n = 8;
        return;
    }
}

static void choose_diag(data **game, char *p, char *n)
{
    if (my_c_isinstr(p, '2') && my_c_isinstr(p, '5') && my_c_isinstr(n, '8')) {
        (*game)->played_n = 8;
        return;
    }
    if (my_c_isinstr(p, '5') && my_c_isinstr(p, '8') && my_c_isinstr(n, '2')) {
        (*game)->played_n = 2;
        return;
    }
    if (my_c_isinstr(p, '6') && my_c_isinstr(p, '5') && my_c_isinstr(n, '4')) {
        (*game)->played_n = 4;
        return;
    }
    if (my_c_isinstr(p, '5') && my_c_isinstr(p, '4') && my_c_isinstr(n, '6')) {
        (*game)->played_n = 6;
        return;
    }
    if (((my_c_isinstr(p, '2') && my_c_isinstr(p, '8')) ||
        (my_c_isinstr(p, '6') && my_c_isinstr(p, '4'))) &&
        my_c_isinstr(n, '5'))
        (*game)->played_n = 5;
}

void deny_player(data *game, int *have_to_target)
{
    if (have_to_target[0] || have_to_target[1])
        choose_rowcol(&game, game->player1, game->board);
    else
        choose_diag(&game, game->player1, game->board);
}

void choose_win(data *game, int *have_to_target)
{
    if (have_to_target[0] || have_to_target[1])
        choose_rowcol(&game, game->player2, game->board);
    else
        choose_diag(&game, game->player2, game->board);
}
