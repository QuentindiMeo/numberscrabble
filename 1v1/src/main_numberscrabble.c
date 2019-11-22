/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** main number scrabble
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/numberscrabble.h"

static int help(void)
{
    my_putstr("\n\tWelcome to Number Scrabble\n\n \033[1mUSAGE\033[0m\n\t./num"
        "berscrabble\n\n \033[1mDESCRIPTION\033[0m\n\tThis game is made of a s"
        "et of numbers (from 1 to 9) and makes you play\n\tagainst each other."
        "   The goal is to pick numbers so that three of the\n\tnumbers you ha"
        "ve add up to exactly 15 while getting your opponent away\n\tfrom do"
        "ing it themself. Maybe you're good enough to beat your opponent\n\n\t"
        "\033[1m-h\033[0m, \033[1m--help\033[0m\n\t\tDisplay this help.\n\n\t"
        "\033[1m--names\033[0m\n\t\tMake the program ask for two names to use "
        "as player names.\n\n   \033[1mExit status:\033[0m\n\t0\tif the game e"
        "nded with a draw or the game was quit (CTRL+D),\n\t1\tif the game end"
        "ed and Player 1 won,\n\t2\tif the game ended and Player 2 won,\n\t84"
        "\tif the program ended with an error.\n\n \033[1mAUTHOR\033[0m\n\tWri"
        "tten by Quentin di Meo.\n\n \033[1mREPORTING BUGS\033[0m\n\tReport an"
        "y bug or functioning error to <quentin.di-meo@epitech.eu>\n\n");
    return (SUCCESS);
}

static int print_winner(data *game, int id)
{
    if (!id) {
        my_putstr("\nIt's a draw!!\n");
        return (W_DRAW);
    }
    if (id == PLAYER1) {
        my_putstr("\n");
        my_putstr(game->name1);
        my_putstr(" wins!!\n");
        return (W_PLAYER1);
    }
    if (id == PLAYER2) {
        my_putstr("\n");
        my_putstr(game->name2);
        my_putstr(" wins!!\n");
        return (W_PLAYER2);
    }
    if (id == END_OF_FILE) {
        my_putstr("\nYou quit the game.\n");
        return (SUCCESS);
    }
    return (FAILURE);
}

static int main_numberscrabble(data *game)
{
    int winner;

    my_putstr("\n");
    my_putstr(game->board);
    my_putstr("\n");
    winner = game_loop(game);
    if (winner == END_OF_FILE || winner == DRAW)
        return ((winner == END_OF_FILE) ? END_OF_FILE : W_DRAW);
    return (winner == PLAYER1 ? W_PLAYER1 : W_PLAYER2);
}

int main(int ac, char **av)
{
    int ret_v;
    data *game = NULL;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    game = mallocator();
    setup(&game);
    ret_v = get_parameters(ac, av, game);
    if (ret_v == FAILURE || ret_v == END_OF_FILE2)
        return (FAILURE);
    ret_v = main_numberscrabble(game);
    ret_v = print_winner(game, ret_v);
    freer(game);
    return (ret_v);
}
