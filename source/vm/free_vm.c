/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Debian]
** File description:
** vm
*/

#include "vm/vm.h"

void free_vm(vm_t *vm)
{
    free(vm->data->champ[0].instruction);
    free(vm->data);
    free(vm->ram);
    free(vm->commande);
}
