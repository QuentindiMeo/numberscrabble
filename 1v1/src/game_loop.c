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

static void play(data **game, int whose_turn)
{
    uint i = 0;

    if (whose_turn == PLAYER1)
        my_charcat((*game)->player1, itoc((*game)->played_n));
    else
        my_charcat((*game)->player2, itoc((*game)->played_n));
    my_putstr(whose_turn == PLAYER1 ? (*game)->name1 : (*game)->name2);
    my_putstr(" picked ");
    my_putnbr((*game)->played_n);
    my_putstr("\n");
    my_putstr(whose_turn == PLAYER1 ? (*game)->name1 : (*game)->name2);
    my_putstr(" now has ");
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

static int user_play(data *game, int whose_turn)
{
    my_putstr("\nYour turn:\n");
    if (get_n(&game) == END_OF_FILE)
        return (END_OF_FILE);
    play(&game, whose_turn);
    return (SUCCESS);
}

int game_loop(data *game)
{
    uchar whose_turn = PLAYER2;

    for (uchar over = FALSE; over != TRUE;) {
        whose_turn = switch_turn(whose_turn);
        if (user_play(game, whose_turn) == END_OF_FILE)
            return (END_OF_FILE);
        if (!(is_there_any_nb_left(game) == YES && !is_win(game)))
            over = TRUE;
    }
    if (!is_win(game))
        whose_turn = DRAW;
    return (whose_turn);
}
