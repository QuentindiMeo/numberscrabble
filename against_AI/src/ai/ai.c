/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble artificial intelligence main
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/numberscrabble.h"

static void play(data **game)
{
    uint i = 0;

    my_charcat((*game)->player2, itoc((*game)->played_n));
    my_putstr("AI picked ");
    my_putnbr((*game)->played_n);
    my_putstr("\nAI now has ");
    for (; (*game)->player2[i + 1]; i++) {
        my_putchar((*game)->player2[i]);
        my_putstr(", ");
    }
    my_putchar((*game)->player2[i]);
    my_putstr("\n\n");
    (*game)->board[(*game)->played_n - 1] = '-';
    my_putstr((*game)->board);
    my_putchar('\n');
}

static void choose_random(data **g)
{
    if ((*g)->board[1] != EMP ||
        (*g)->board[5] != EMP ||
        (*g)->board[3] != EMP ||
        (*g)->board[7] != EMP)
        choose_corners(g);
    else if ((*g)->board[6] != EMP ||
             (*g)->board[8] != EMP ||
             (*g)->board[0] != EMP ||
             (*g)->board[2] != EMP)
        choose_diamond(g);
    else {
        (*g)->played_n = 5;
    }
}

void ai_play(data *game)
{
    int rv1[3] = {row_is_abouttowin(game->player2, game->board),
                    col_is_abouttowin(game->player2, game->board),
                    diag_is_abouttowin(game->player2, game->board)};
    int rv2[3] = {row_is_abouttowin(game->player1, game->board),
                    col_is_abouttowin(game->player1, game->board),
                    diag_is_abouttowin(game->player1, game->board)};

    my_putstr("\nAI's turn...\n");
    if (rv1[0] || rv1[1] || rv1[2])
        choose_win(game, rv1);
    else if (rv2[0] || rv2[1] || rv2[2])
        deny_player(game, rv2);
    else
        choose_random(&game);
    play(&game);
}
