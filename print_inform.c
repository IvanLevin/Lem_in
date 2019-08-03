/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:38:21 by gkshleri          #+#    #+#             */
/*   Updated: 2019/08/03 15:38:24 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/lem_in.h"

void	print_inform(t_char *inform)
{
	while (inform)
	{
		ft_putchar(inform->letter);
		inform = inform->next;
	}
}
