/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:22:47 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/02 16:22:55 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

static void lem_in()
{
    t_lem       *lem;
    t_char      *inform;
    t_stream	*streams;

    inform = NULL;
    parsing_lem(&lem, &inform);
    solve(lem, &streams);
    print_inform(inform);
    ft_putendl("");
    run_ants(lem, &streams);
    clear_char(&inform);
    clear_streams(&streams);
    clear_lem(&lem);

}

int main(void)
{
    lem_in();
    return (0);
}