/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <qpeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 02:32:01 by qpeng             #+#    #+#             */
/*   Updated: 2019/06/18 02:38:56 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"
#include <stdio.h>

void    run(t_vm *vm)
{
    while (1)
    {
        // 
        ++vm->corewar.cycle;
        // if (++vm->corewar.cycle > vm->corewar.dump_cycle)
        //     print_mem(vm);
        run_process(vm);
        if (vm->corewar.cycle > vm->corewar.kill_cycle)
            printf("start killing!\n");
        if (!vm->nprocess)
            ERROR("some one win!");
        // gui shit
    }
}

void    read_args(t_vm *vm, int ac, char **av)
{
    int     i;
    int     fd;

    i = 1;
    while (i < ac)
    {
        loader(vm, av[i]);
        i++;
    }
}

void    cleanup(t_vm *vm)
{
    t_process *tmp = vm->process_list;
    while (tmp)
    {
        tmp = tmp->next;
        free(tmp);
    }
}

int     main(int ac, char **av)
{
    t_vm vm;
    
    bzero_(&vm, sizeof(t_vm));
    vm.nplayers = ac - 1;
    setbuf(stdout, NULL);
    if (ac < 2)
        printf("ac \n");
    read_args(&vm, ac, av);
    print_mem(&vm);
    run(&vm);
    cleanup(&vm);
    return (0);
}