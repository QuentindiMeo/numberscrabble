/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble detectors ai
*/

#include "../include/my.h"
#include "../include/numberscrabble.h"

int diag_is_abouttowin(char *p, char *n)
{
    if ((my_c_isinstr(p, '2') && my_c_isinstr(p, '5') && my_c_isinstr(n, '8'))
    || (my_c_isinstr(p, '2') && my_c_isinstr(p, '8') && my_c_isinstr(n, '5'))
    || (my_c_isinstr(p, '5') && my_c_isinstr(p, '8') && my_c_isinstr(n, '2')))
        return (YES);
    if ((my_c_isinstr(p, '6') && my_c_isinstr(p, '5') && my_c_isinstr(n, '4'))
    || (my_c_isinstr(p, '6') && my_c_isinstr(p, '4') && my_c_isinstr(n, '5'))
    || (my_c_isinstr(p, '5') && my_c_isinstr(p, '4') && my_c_isinstr(n, '6')))
        return (YES);
    return (NO);
}

int col_is_abouttowin(char *p, char *n)
{
    if ((my_c_isinstr(p, '2') && my_c_isinstr(p, '9') && my_c_isinstr(n, '4'))
    || (my_c_isinstr(p, '2') && my_c_isinstr(p, '4') && my_c_isinstr(n, '4'))
    || (my_c_isinstr(p, '9') && my_c_isinstr(p, '4') && my_c_isinstr(n, '4')))
        return (YES);
    if ((my_c_isinstr(p, '7') && my_c_isinstr(p, '5') && my_c_isinstr(n, '3'))
    || (my_c_isinstr(p, '7') && my_c_isinstr(p, '3') && my_c_isinstr(n, '5'))
    || (my_c_isinstr(p, '5') && my_c_isinstr(p, '3') && my_c_isinstr(n, '7')))
        return (YES);
    if ((my_c_isinstr(p, '6') && my_c_isinstr(p, '1') && my_c_isinstr(n, '8'))
    || (my_c_isinstr(p, '6') && my_c_isinstr(p, '8') && my_c_isinstr(n, '1'))
    || (my_c_isinstr(p, '1') && my_c_isinstr(p, '8') && my_c_isinstr(n, '6')))
        return (YES);
    return (NO);
}

int row_is_abouttowin(char *p, char *n)
{
    if ((my_c_isinstr(p, '2') && my_c_isinstr(p, '7') && my_c_isinstr(n, '6'))
    || (my_c_isinstr(p, '2') && my_c_isinstr(p, '6') && my_c_isinstr(n, '7'))
    || (my_c_isinstr(p, '7') && my_c_isinstr(p, '6') && my_c_isinstr(n, '2')))
        return (YES);
    if ((my_c_isinstr(p, '9') && my_c_isinstr(p, '5') && my_c_isinstr(n, '1'))
    || (my_c_isinstr(p, '9') && my_c_isinstr(p, '1') && my_c_isinstr(n, '5'))
    || (my_c_isinstr(p, '5') && my_c_isinstr(p, '1') && my_c_isinstr(n, '9')))
        return (YES);
    if ((my_c_isinstr(p, '4') && my_c_isinstr(p, '3') && my_c_isinstr(n, '8'))
    || (my_c_isinstr(p, '4') && my_c_isinstr(p, '8') && my_c_isinstr(n, '3'))
    || (my_c_isinstr(p, '3') && my_c_isinstr(p, '8') && my_c_isinstr(n, '4')))
        return (YES);
    return (NO);
}
