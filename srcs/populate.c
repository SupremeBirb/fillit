/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:29:29 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/18 19:04:34 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int leftmost(int *coords)
{
	int i;

	i = 0;
	if (coords[0] < i)
		i = coords[0];
	if (coords[2] < i)
		i = coords[2];
	if (coords[4] < i)
		i = coords[4];
	return (-i);
}

t_tetro	*listcoord(char *str, int len, int holdx, t_tetro *newtet)
{
	int subx;
	int y;
	int cordnum;

	subx = holdx;
	y = 0;
	cordnum = -1;
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
		}
		str++;
	}
	newtet->left = leftmost(newtet->cords);
	return (newtet);
}

//for another function
void	print_tet(t_tetro *tet)
{
	int i;
	int j;

	j = 1;
	while (tet)
	{
		i = -1;
		while (++i < 6)
		{
			printf("Tetromino #%d: x: %d\t", j, tet->cords[i]);
			printf("y: %d\n", tet->cords[i + 1]);
			i++;
		}
		printf("Leftmost: %d\n", tet->left);
		ft_putchar('\n');
		j++;
		tet = tet->next;
	}
}

t_tetro	*makelist(char *str, int len)
{
	t_tetro	*newtet;
	int holdx;

	holdx = 0;
	while (*str++ != '#')
	{
		len--;
		holdx++;
		if (*str == '\n')
			holdx = -1;
	}
	if (!(newtet = (t_tetro *)ft_memalloc(sizeof(*newtet))))
		return (NULL);
	return (listcoord(str, len, holdx, newtet));
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
	return (firsttet);
}

int	maker(char *tetro, int tetronum)
{
	t_tetro *newunit;
	newunit = populate(tetro, tetronum);
	print_tet(newunit);
	return (0);
}
