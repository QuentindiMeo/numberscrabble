/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble game loop
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/numberscrabble.h"

static void play(data **game)
{
    uint i = 0;

    my_charcat((*game)->player1, itoc((*game)->played_n));
    my_putstr("Player picked ");
    my_putnbr((*game)->played_n);
    my_putstr("\nPlayer now has ");
    for (; (*game)->player1[i + 1]; i++) {
        my_putchar((*game)->player1[i]);
        my_putstr(", ");
    }
    my_putchar((*game)->player1[i]);
    my_putstr("\n\n");
    (*game)->board[(*game)->played_n - 1] = '-';
    my_putstr((*game)->board);
    my_putchar('\n');
}

static int get_n(data **game)
{
    char *entry = NULL;
    size_t buff = 0;

    (*game)->played_n = 0;
    my_putstr("Pick: ");
    while (!(*game)->played_n) {
        if (getline(&entry, &buff, stdin) == ERROR)
            return (quit(entry));
        (*game)->played_n = my_getnbr(entry);
        if (check_played_nb(*game) == FAILURE)
            (*game)->played_n = err_out_of_range();
    }
    free(entry);
    return (SUCCESS);
}

static int user_play(data *game)
{
    my_putstr("\nYour turn:\n");
    if (get_n(&game) == END_OF_FILE)
        return (END_OF_FILE);
    play(&game);
    return (SUCCESS);
}

int game_loop(data *game)
{
    uchar whose_turn = AI;
    int ret_v;

    for (uchar over = FALSE; over != TRUE;) {
        whose_turn = switch_turn(whose_turn);
        if (whose_turn == USER)
            ret_v = user_play(game);
        else
            ai_play(game);
        if (ret_v == END_OF_FILE)
            return (END_OF_FILE);
        if (!(is_there_any_nb_left(game) == YES && !is_win(game, 0)))
            over = TRUE;
    }
    if (!is_win(game, 1))
        whose_turn = DRAW;
    return (whose_turn);
}
