/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble ai denying player rows columns
*/

#include "../../include/my.h"
#include "../../include/numberscrabble.h"

void choose_rowcol(data **game, char *p, char *n)
{
    if (((my_c_isinstr(p, '7') && my_c_isinstr(p, '6')) ||
        (my_c_isinstr(p, '9') && my_c_isinstr(p, '4'))) &&
        my_c_isinstr(n, '2'))
        (*game)->played_n = 2;
    if (((my_c_isinstr(p, '2') && my_c_isinstr(p, '6')) ||
        (my_c_isinstr(p, '5') && my_c_isinstr(p, '3'))) &&
        my_c_isinstr(n, '7'))
        (*game)->played_n = 7;
    if (((my_c_isinstr(p, '2') && my_c_isinstr(p, '7')) ||
        (my_c_isinstr(p, '1') && my_c_isinstr(p, '8'))) &&
        my_c_isinstr(n, '6'))
        (*game)->played_n = 6;
    if (((my_c_isinstr(p, '5') && my_c_isinstr(p, '1')) ||
        (my_c_isinstr(p, '2') && my_c_isinstr(p, '4'))) &&
        my_c_isinstr(n, '9'))
        (*game)->played_n = 9;
    if (((my_c_isinstr(p, '9') && my_c_isinstr(p, '1')) ||
        (my_c_isinstr(p, '7') && my_c_isinstr(p, '3'))) &&
        my_c_isinstr(n, '5'))
        (*game)->played_n = 5;
    if (((my_c_isinstr(p, '9') && my_c_isinstr(p, '5')) ||
        (my_c_isinstr(p, '6') && my_c_isinstr(p, '8'))) &&
        my_c_isinstr(n, '1'))
        (*game)->played_n = 1;
    if (((my_c_isinstr(p, '3') && my_c_isinstr(p, '8')) ||
        (my_c_isinstr(p, '2') && my_c_isinstr(p, '9'))) &&
        my_c_isinstr(n, '4'))
        (*game)->played_n = 4;
    if (((my_c_isinstr(p, '4') && my_c_isinstr(p, '8')) ||
        (my_c_isinstr(p, '7') && my_c_isinstr(p, '5'))) &&
        my_c_isinstr(n, '3'))
        (*game)->played_n = 3;
    if (((my_c_isinstr(p, '4') && my_c_isinstr(p, '3')) ||
        (my_c_isinstr(p, '6') && my_c_isinstr(p, '1'))) &&
        my_c_isinstr(n, '8'))
        (*game)->played_n = 8;
}
