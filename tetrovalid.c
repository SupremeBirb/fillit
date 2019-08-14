/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrovalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:20:31 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/13 20:51:19 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int		validchar(char c)
{
	if (c == '\n' || c == '#' || c == '.')
		return (1);
	return (0);
}

int		validfield(char *input)		//returns number of tetrominos, or 0 if invalid
{
	int i;
	int tetronum;

	i = -1;
	tetronum = 0;
	while (input[++i])
	{
		if (!(validchar(input[i])))
			return (0);
		if (input[i] == '\n' && ((i + 1 - tetronum) % 5 != 0))		//error checks grid width and checks if tetromino is valid
			return (0);
		if ((i + 1 - tetronum) % 20 == 0)	//checks for line seperation between inputs and adds to tetro counter
		{
			if (input[i + 1])
			{
				tetronum++;
				i++;
			}
			else
				return (tetronum + 1);
		}
	}
	return (0);
}

int		connectcheck(const char *i)			//checks for tetronimo boundry blocks
{
	if (ft_numcharstrn(&i[-5], '\n', 5) == 2)
		return((*(i + 5) == '#' || *(i + 1) == '#' || *(i - 1) == '#') ? 1 : 0);
	if (ft_numcharstrn(&i[0], '\n', 5) == 2)
		return((*(i - 5) == '#' || *(i + 1) == '#' || *(i - 1) == '#') ? 1 : 0);
	if (*(i - 5) == '#' || *(i + 5) == '#' ||
	*(i + 1) == '#' || *(i - 1) == '#')
		return (1);
	return (0);
}

int		tetrochecker(const char *str, int tetronum)
{
	int i;

	i = 0;
	while (--tetronum >= 0 && str[i])
	{
		if (ft_numcharstrn(&str[i], '#', 20) != 4)
			return (0);
		while ((str[i] != '\n' || str[i + 1] != '\n') && str[i])
		{
			if (str[i] == '#')
				if (!(connectcheck(&str[i])))
					return (0);
			i++;
		}
		i += 2;
	}
	return (1);
}

int	mastercheck(char *tetros)
{
	int tetronum;

	if (!(tetronum = validfield(tetros)))
	{
		printf("Invalid input\n");				//delet this nephew, and merge with if statement below
		return (-1);
	}
	printf("Tetronum %d\n", tetronum);
	if (!(tetrochecker(tetros, tetronum)))
	{
		printf("Invalid tetronimos\n");			//delet this nephew
		return (-1);
	}
	return (0);
}

//translates tetromino string into (char **)
//returns NULL if invalid input

/*
char	**strtoarr(char *piece)
{
	int 	i;
	int		y;
	int		x;
	char	**tetrarray;

	i = 0;
	y = 0;
	x = 0;
	tetrarray = (char **)malloc(sizeof(char *) * 4);
	while (piece[i])
	{
		if (piece[i] == '\n')
		{
			i++;
			y++;
			x = 0;
		}
		tetrarray[y][x++] = (piece[i++]);
	}
	return (tetrarray);
	char **grid;
    int i;
    int size;
    
    if (!str)
        return (NULL);
    size = ft_atoi(str);
    if (!(grid = (char **)ft_memalloc((size + 1) * sizeof(char *))))
        return (NULL);
    i = -1;
    while (++i < size)
    {
        grid[i] = grid_mark(size);
        printf("i: %d\n", i); 
        printf("string: %s\n", grid[i]);
    }
    return (grid);
*/
