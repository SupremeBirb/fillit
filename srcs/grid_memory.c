/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:12:03 by lelee             #+#    #+#             */
/*   Updated: 2019/08/18 17:59:47 by lelee            ###   ########.fr       */
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

char	**ft_grid(char const *xy)
{
	char **grid;
	int i;
	int size;
	
	if (!xy)
		return (NULL);
	size = ft_atoi(xy);
	if (!(grid = (char **)ft_memalloc((size + 1) * sizeof(char *))))
		return (NULL);
	i = -1;
	while (++i < size)
		grid[i] = grid_mark(size);
	return (grid);
}

char  **grid(char *av)
{
	char *size;
	int j;
	int i;
	char **grid;

	if (!(size = ft_strnew(4096)))
		return (NULL);
	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			size[i] = av[i];
		i++;
	}
	grid = ft_grid(size);
	free(size);
	i = 0;
	ft_putendl("\nGrid:");
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
	putchar('\n');
	return (grid);
}
