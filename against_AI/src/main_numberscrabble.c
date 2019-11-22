/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** main number scrabble
*/

#include "../include/my.h"
#include "../include/numberscrabble.h"

static int help(void)
{
    my_putstr("\n\tWelcome to Number Scrabble\n\n \033[1mUSAGE\033[0m\n\t./num"
        "berscrabble\n\n \033[1mDESCRIPTION\033[0m\n\tThis game is made of a s"
        "et of numbers (from 1 to 9) and makes you play\n\tagainst an AI.The"
        " goal is to pick numbers so that three of the numbers\n\tyou have"
        " add up  to exactly  15  while getting your opponent away from\n\tdo"
        "ing it themself. Maybe you're good enough to beat the AI... <.<\n\n\t"
        "\033[1m-h\033[0m, \033[1m--help\033[0m\n\t\tDisplay this help.\n\n   "
        "\033[1mExit status:\033[0m\n\t0\tif the game ended with a draw or the"
        " game was quit (CTRL+D),\n\t1\tif the game ended and the player won,"
        "\n\t2\tif the game ended and the AI won,\n\t84\tif the program ended "
        "with an error.\n\n \033[1mAUTHOR\033[0m\n\tWritten by Quentin di Meo."
        "\n\n \033[1mREPORTING BUGS\033[0m\n\tReport any bug or functioning er"
        "ror to <quentin.di-meo@epitech.eu>\n\n");
    return (SUCCESS);
}

static int print_winner(int id)
{
    if (!id) {
        my_putstr("\nIt's a draw!!\n");
        return (W_DRAW);
    }
    if (id == USER) {
        my_putstr("\nPlayer wins!!\n");
        return (W_USER);
    }
    if (id == AI) {
        my_putstr("\nAI wins!!\n");
        return (W_AI);
    }
    if (id == END_OF_FILE) {
        my_putstr("\nYou quit the game.\n");
        return (SUCCESS);
    }
    return (FAILURE);
}

static int main_numberscrabble(void)
{
    data *game = mallocator();
    int winner;

    setup(&game);
    my_putstr("\n");
    my_putstr(game->board);
    my_putstr("\n");
    winner = game_loop(game);
    freer(game);
    if (winner == END_OF_FILE || winner == DRAW)
        return ((winner == END_OF_FILE) ? END_OF_FILE : W_DRAW);
    return (winner == USER ? W_USER : W_AI);
}

int main(int ac, char **av)
{
    int ret_v;

    if (ac == 2 &&
        (my_str_isequal(av[1], "-h") || my_str_isequal(av[1], "--help")))
        return (help());
    ret_v = main_numberscrabble();
    ret_v = print_winner(ret_v);
    return (ret_v);
}
