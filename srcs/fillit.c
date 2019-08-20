/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:37:05 by lelee             #+#    #+#             */
/*   Updated: 2019/08/19 19:02:39 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

void	saveprint(char **grid)
{
	int i;
	int j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
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
	saveprint(grid);

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

