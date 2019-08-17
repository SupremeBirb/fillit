/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrovalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:20:31 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/17 04:18:19 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		validchar(char c)
{
	if (c == '\n' || c == '#' || c == '.')
		return (1);
	return (0);
}

/*
**	checks that only valid characters are sent through the input.
**	also checks that the field is of valid size with correct
**	tetronimo separators. returns the number of tetronimos sent
**	through. or 0 if invalid field.
*/

int		validfield(char *input)
{
	int i;
	int tetronum;

	i = -1;
	tetronum = 0;
	while (input[++i])
	{
		if (!(validchar(input[i])))
			return (0);
		if (input[i] == '\n' && ((i + 1 - tetronum) % 5 != 0))
			return (0);
		if ((i + 1 - tetronum) % 20 == 0)
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

/*
**	returns the number of connecting sides for each tetronimo.
*/

int		connectcheck(const char *i, int n)
{
	int touching;

	touching = 0;
	if (n < 1)
		return ((*(i + 1) == '#') + (*(i + 5) == '#'));
	if (n < 4)
		return ((*(i + 1) == '#') + (*(i - 1) == '#') + (*(i + 5) == '#'));
	if (ft_numcharstrn(&i[-5], '\n', 5) == 2 && *(i + 5) == '#')
		touching++;
	else if (ft_numcharstrn(&i[0], '\n', 5) == 2 && *(i - 5) == '#')
	{
		touching++;
	}
	else
	{
		if (*(i + 5) == '#')
			touching++;
		if (*(i - 5) == '#')
			touching++;
	}
	if (*(i + 1) == '#')
		touching++;
	if (*(i - 1) == '#')
		touching++;
	printf("touching:\t%d\t", touching);
	return (touching);
}

/*
**	checks that each tetronimo is valid. first passes string into ft_numcharstrn, 
**	which thecks that each segment has 4 '#'. than while we do not encounter two
**	new line characters in a row, the function checks that each block has a total
**	of six connecting sides. failing any of these checks returns 0.
*/

int		tetrochecker(const char *str, int tetronum)
{
	int i;
	int	sides;

	i = 0;
	sides = 0;
	while (--tetronum >= 0 && str[i])
	{
		if (ft_numcharstrn(&str[i], '#', 20) != 4)
			return (0);
		while ((str[i] != '\n' || str[i + 1] != '\n') && str[i])
		{
			if (str[i] == '#')
			{
				sides += connectcheck(&str[i], i);
				printf("i:\t\t%d\t", i);
				printf("sides:\t\t%d\n", sides);
			}
			i++;
		}
		if (sides < 6)
			return (0);
		sides = 0;
		i += 2;
	}
	return (1);
}

int	mastercheck(char *tetro)
{
	int tetronum;
	
	if (!(tetronum = validfield(tetro)))
	{
		printf("Invalid input\n");				//delet this nephew, and merge with if statement below
		return (-1);
	}
	printf("Tetronum: %d\n", tetronum);
	if (!(tetrochecker(tetro, tetronum)))
	{
		printf("Invalid tetronimos\n");			//delet this nephew
		return (-1);
	}
	return (tetronum);
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