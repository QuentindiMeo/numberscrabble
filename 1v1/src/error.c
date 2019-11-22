/*
** PERSONAL PROJECT, 2019
** numberscrabble
** File description:
** number scrabble errors
*/

#include "../include/my.h"

int err_out_of_range(void)
{
    my_putstr("Error: this number is invalid or was already picked\n");
    my_putstr("Pick: ");
    return (SUCCESS);
}
