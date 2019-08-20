/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:37:05 by lelee             #+#    #+#             */
/*   Updated: 2019/08/19 16:05:58 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	saveprint(char **grid, int y, int x)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (i == y && j == x)
				ft_putchar('o');
			else
				ft_putchar(grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

int	fillit(t_tetro *curr, char **grid, int y, int x, char a)
{
	char temp;
	saveprint(grid, y, x);

	temp = a + 1;
	if (!curr)
		return (1);
	if (!grid[y])
		return (0);
	if (grid[y][x] == '.' && l_bndry(x, curr) && d_bndry(y, curr, ft_strlen(grid[0])))
		if (isfree(curr, grid, y, x))
		{
			if (fillit(curr->next, place(curr, grid, y, x, ++a), 0, 0, temp))
				return (1);
			else
				clear(curr, grid, y, x, --a);
		}
	return (grid[y][x + 1] != '\0' ? fillit(curr, grid, y, ++x, a) : fillit(curr, grid, ++y, 0, a));
}

int doit(char **grid, t_tetro *fresh)
{
	fillit(fresh, grid, 0, 0, ('A' - 1));
	return (1);
}
