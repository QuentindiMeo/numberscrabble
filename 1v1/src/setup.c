/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** setup number scrabble
*/

#include <stdlib.h>
#include <getopt.h>
#include "../include/my.h"
#include "../include/numberscrabble.h"

static char *do_switch(char c, data **game)
{
    switch (c) {
    case 'n' :
        return (get_names(game));
        break;
    case '?' :
        my_putstr("Try './numberscrabble --help' for more information.\n");
        return (NULL);
        break;
    }
    return ("-");
}

static struct option *set_longopts(void)
{
    struct option *longopts = malloc(sizeof(struct option) * 1);

    longopts[0].name = "names";
    longopts[0].has_arg = 0;
    longopts[0].flag = NULL;
    longopts[0].val = 'n';
    return (longopts);
}

int get_parameters(int ac, char **av, data *game)
{
    char c = 0;
    char *ret_v;
    struct option *longopts = set_longopts();

    do {
        c = getopt_long(ac, av, "1:2:", longopts, NULL);
        ret_v = do_switch(c, &game);
        if (ret_v == NULL) {
            free(longopts);
            return (FAILURE);
        } else if ((*ret_v) == 'n') {
            free(longopts);
            freer(game);
            return (END_OF_FILE2);
        }
    } while (c != END_OF_ARGS);
    free(longopts);
    return (SUCCESS);
}

void setup(data **game)
{
    (*game)->board = my_strdup("123456789");
    (*game)->board[9] = 0;
    (*game)->played_n = 0;
    for (uint i = 0; i < 10; i++) {
        (*game)->player1[i] = 0;
        (*game)->player2[i] = 0;
    }
    (*game)->name1 = my_strdup("Player 1");
    (*game)->name2 = my_strdup("Player 2");
}
