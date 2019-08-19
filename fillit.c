/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:37:05 by lelee             #+#    #+#             */
/*   Updated: 2019/08/18 20:39:07 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		isfree(t_tetro *curr, char **grid, int y, int x)
{
	if (grid[y + (curr->cords[1])][x + (curr->cords[0])] == '.' &&
	grid[y + (curr->cords[3])][x + (curr->cords[2])] == '.' &&
	grid[y + (curr->cords[5])][x + (curr->cords[4])] == '.')
		return (1);
	return (0);
}

char	**place(t_tetro *curr, char **grid, int y, int x, char letter)
{
	grid[y][x] = letter;
	grid[y + (curr->cords[1])][x + (curr->cords[0])] = letter;
	grid[y + (curr->cords[3])][x + (curr->cords[2])] = letter;
	grid[y + (curr->cords[5])][x + (curr->cords[4])] = letter;
	return (grid);
}

char	**clear(t_tetro *curr, char **grid, int y, int x, char letter)
{
	letter = letter + 1 - 1;
	grid[y][x] = '.';
	grid[y + (curr->cords[1])][x + (curr->cords[0])] = '.';
	grid[y + (curr->cords[3])][x + (curr->cords[2])] = '.';
	grid[y + (curr->cords[5])][x + (curr->cords[4])] = '.';
	return (grid);
}

int l_boundary(int x, t_tetro *curr)
{
	if (x < curr->left)
		return (0);
	return (1);
}

char		**fillit(t_tetro *curr, char **grid, int y, int x, char a)
{
	char temp;

	temp = a + 1;
	if (!curr)
		return (grid);
	if (!grid[y])
		return (NULL);
	if (grid[y][x] == '.')
		if (l_boundary(x, curr))
			if (isfree(curr, grid, y, x))
				return (fillit(curr->next, place(curr, grid, y, x, ++a), 0, 0, temp));
	// if (curr != isfree(curr, grid, y, x))
	// 	clear(curr, grid, y, x, a)
		
	return (grid[y][x + 1] != '\0' ? fillit(curr, grid, y, ++x, a) : fillit(curr, grid, ++y, 0, a));
}

int doit(char **grid, t_tetro *fresh)
{
	int i;
	int j;

	i = 0;
	grid = fillit(fresh, grid, 0, 0, ('A' - 1));
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			ft_putchar(grid[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
	return (1);
}
