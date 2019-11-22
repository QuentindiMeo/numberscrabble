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
};
typedef struct data data;

typedef enum {
    EMP = '-',
} default_numberscrabble_t;

typedef enum {
    DRAW = 0,
    USER = 1,
    AI = 2,
    W_DRAW = 0,
    W_USER = 1,
    W_AI = 2,
} return_values_numberscrabble_t;

int err_out_of_range(void);
char *err_invalid_arg(void);

void choose_diamond(data **g);
void choose_corners(data **g);
void choose_rowcol(data **game, char *p, char *n);
void choose_win(data *game, int *have_to_target);
void deny_player(data *game, int *have_to_target);
int diag_is_abouttowin(char *p, char *n);
int col_is_abouttowin(char *p, char *n);
int row_is_abouttowin(char *p, char *n);
int is_win(data *game);

void ai_play(data *game);

int check_played_nb(data *game);

int is_there_any_nb_left(data *game);
int switch_turn(int id);
int game_loop(data *game);

int quit(char *to_be_freed);
data *freer(data *game);
data *mallocator(void);

int get_parameters(int ac, char **av, data *game);
void setup(data **game);

#endif
