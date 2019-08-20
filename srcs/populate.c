/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:29:29 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/19 16:01:23 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int leftmost(int *coords)
{
	int i;

	i = 0;
	if (coords[0] < i)
		i = coords[0];
	if (coords[2] < coords[0])
		i = coords[2];
	if (coords[4] < coords[2])
		i = coords[4];
	return (-i);
}

int downmost(int *coords)
{
	int i;

	i = 0;
	if (coords[1] > i)
		i = coords[1];
	if (coords[3] > coords[1])
		i = coords[3];
	if (coords[5] > coords[3])
		i = coords[5];
	return (i);
}

void	addtolist(t_tetro *str, t_tetro *firsttet)
{
	while (firsttet->next)
		firsttet = firsttet->next;
	firsttet->next = str;
	str->next = NULL;
}

/*
**	is called by makelist to populate the rest of the newtet struct with coordinates.
*/

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
	newtet->down = downmost(newtet->cords);
	return (newtet);
}

/*
**	finds the first '#' character. uses it as a reference point in order to 
**	make a list of coordinates relative to the first position. allocates memory
**	then passes the string into listcoords to map out the coordinate positions.
*/

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

/*
//	takes string and number of tetros generated from tetrovalid.c. creates first
//	tetronimo and places into linked list. populates the rest of the list.
*/

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

//delete
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
		printf("Downmost: %d\n", tet->down);
		ft_putchar('\n');
		j++;
		tet = tet->next;
	}
}

//delete?
int	maker(char *tetro, int tetronum)
{
	t_tetro *newunit;
	newunit = populate(tetro, tetronum);
	print_tet(newunit);
	return (0);
}
