/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** main number scrabble memory allocation and free
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/numberscrabble.h"

int quit(char *to_be_freed)
{
    free(to_be_freed);
    return (END_OF_FILE);
}

data *freer(data *game)
{
    if (game && game->board && game->board[0])
        free(game->board);
    if (game->player2)
        free(game->player2);
    if (game->player1)
        free(game->player1);
    if (game->name2)
        free(game->name2);
    if (game->name1)
        free(game->name1);
    if (game)
        free(game);
    return (NULL);
}

data *mallocator(void)
{
    data *game = malloc(sizeof(data));

    if (!game)
        return (NULL);
    game->player1 = malloc(sizeof(char) * 10);
    if (!game->player1)
        return (freer(game));
    game->player2 = malloc(sizeof(char) * 10);
    if (!game->player2)
        return (freer(game));
    return (game);
}
