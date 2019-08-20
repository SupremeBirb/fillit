/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:12:03 by lelee             #+#    #+#             */
/*   Updated: 2019/08/19 18:38:55 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

char	*grid_mark(int size)
{
	char *dot;
	int i;

	i = -1;
	if (!(dot = ft_strnew((size_t)size)))
		return (NULL);
	dot[size--] = '\0';
	while (i < size)
		dot[++i] = '.';
	return (dot);
}

char	**ft_grid(int size)
{
	char **grid;
	int i;

	if (!(grid = (char **)ft_memalloc((size + 1) * sizeof(char *))))
		return (NULL);
	i = -1;
	while (++i < size)
		grid[i] = grid_mark(size);
	saveprint(grid, 0, 0);
	return (grid);
}
