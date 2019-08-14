/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:12:03 by lelee             #+#    #+#             */
/*   Updated: 2019/08/12 11:27:48 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

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

int main(int ac, char **av)
{
	char size[10];
	int j;
	int i = 0;
	char **grid;
	
	if (ac < 2)
	{
		printf("Incorrect Input\n");
		return (0);
	}
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]))
			size[i] = av[1][i];
		i++;
	}
	grid = ft_grid(size);
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			printf("%c", grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
