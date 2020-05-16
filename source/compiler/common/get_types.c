/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Epitech First Year Project: Make programs fight
*/

#include "compiler/compiler.h"

static void find_types(char **args, int *type)
{
    int index = 0;

    for (int i = 0; args[i]; ++i) {
        if ('r' == args[i][0])
            type[index] = T_REG;
        else if (DIRECT_CHAR == args[i][0])
            type[index] = T_DIR;
        else
            type[index] = T_IND;
        ++index;
    }
}

static char **get_args(char *line, char **tmp)
{
    int index = 0;

    for (int i = 0; line[i]; ++i)
        if (' ' == line[i])
            index = i;
    tmp = my_str_to_word_array(line + index + 1, SEPARATOR_CHAR);
    return (tmp);
}

int *get_types(char *name, char *line, int nb_arg, char **args)
{
    static int n = 0;
    int *type = malloc(sizeof(int) * MAX_ARGS_NUMBER);
    char **tmp = get_args(line, tmp);
    int j = 0;

    for (j = 0; tmp[j]; j++);
    if (j == 1) args[n] = m_strdup(tmp[0]);
    else if (j == 3) args[n] = m_strdup(strcat(tmp[0], strcat(tmp[1], tmp[2])));
    if (NULL == tmp || NULL == type)
        return (NULL);
    for (int i = 0; MAX_ARGS_NUMBER > i; ++i)
        type[i] = -1;
    find_types(tmp, type);
    if (false == check_types(name, type)) {
        for (int i = 0; tmp[i]; ++i)
            free(tmp[i]);
        free(tmp);
        return (NULL);
    }
    for (int i = 0; tmp[i]; ++i)
        free(tmp[i]);
    free(tmp);
    n++;
    return (type);
}
