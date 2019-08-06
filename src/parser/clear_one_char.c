/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_one_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: breolson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:46:20 by breolson          #+#    #+#             */
/*   Updated: 2019/08/03 15:46:35 by breolson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lem_in.h"

void		clear_one_char(t_char **letter)
{
	(void)(*letter)->letter;
	(*letter)->next = NULL;
	free(*letter);
	(*letter) = NULL;
}
