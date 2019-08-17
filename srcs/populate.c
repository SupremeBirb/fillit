/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:29:29 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/17 02:08:18 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetro	*makelist(char *str, int len)
{
	t_tetro	*newtet;
	int subx;
	int holdx;
	int y;
	int	cordnum;

	holdx = 0;
	y = 0;
	cordnum = -1;
	while (*str++ != '#')
	{
		len--;
		holdx++;
		if (*str == '\n')
			holdx = -1;
	}
	subx = holdx;
	printf("holdx:\t%d\n", holdx);
	if (!(newtet = (t_tetro *)ft_memalloc(sizeof(*newtet))))
		return (NULL);
	while (--len > 0)
	{
		subx++;
		if (*str == '\n')
		{
			y++;
			subx = -1;
		}
		if (*str == '#')
		{
			newtet->cords[++cordnum] = (subx - holdx);
			newtet->cords[++cordnum] = (y);
			printf("(%d, %d)\n", (subx - holdx), y);
		}
		str++;
	}
	return (newtet);
}

void	addtolist(t_tetro *str, t_tetro *firsttet)
{
	while (firsttet->next)
		firsttet = firsttet->next;
	firsttet->next = str;
	str->next = NULL;
}

t_tetro	*populate(char *str, int tetronum)
{
	t_tetro	*firsttet;

	firsttet = makelist(&(*str), 21);
	while (--tetronum > 0)
	{
		str += 21;
		addtolist(makelist(&(*str), 21), firsttet);
	}
	return firsttet;
}

int	maker(char *tetro, int tetronum)
{
	t_tetro *newunit;
	newunit = populate(tetro, tetronum);
	return (0);
}