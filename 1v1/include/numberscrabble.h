/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble header
*/

#ifndef NUMBERSCRABBLE_H_
#define NUMBERSCRABBLE_H_

struct data {
    char *board;
    int played_n;
    char *player1;
    char *player2;
    char *name1;
    char *name2;
};
typedef struct data data;

typedef enum {
    EMP = '-',
    END_OF_FILE2 = -2,
} default_numberscrabble_t;

typedef enum {
    DRAW = 0,
    PLAYER1 = 1,
    PLAYER2 = 2,
    W_DRAW = 0,
    W_PLAYER1 = 1,
    W_PLAYER2 = 2,
} return_values_numberscrabble_t;

int err_out_of_range(void);

int is_win(data *game);

int check_played_nb(data *game);
int is_there_any_nb_left(data *game);
int switch_turn(int id);
int game_loop(data *game);

int quit(char *to_be_freed);
data *freer(data *game);
data *mallocator(void);

char *get_names(data **game);
int get_parameters(int ac, char **av, data *game);
void setup(data **game);

#endif
