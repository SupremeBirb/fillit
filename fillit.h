/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 09:16:37 by jfelty            #+#    #+#             */
/*   Updated: 2019/08/19 18:44:29 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** cords are [x1, y1, x2, y2, x3, y3]
*/

typedef	struct		s_tetro
{
	int				cords[6];
	int				left;
	int				down;
	struct s_tetro	*next;	
}					t_tetro;

/*
** grid_memory.c
*/

char		*grid_mark(int size);
char		**ft_grid(int size);

/*
** tetrovalid.c
*/

int			validchar(char c);
int			validfield(char *input);
int			connectcheck(const char *i, int n);
int			tetrochecker(const char *str, int tetronum);
int			mastercheck(char *tetro);

/*
** populate.c
*/

t_tetro		*populate(char *str, int tetronum);
t_tetro		*makelist(char *str, int len);
void		addtolist(t_tetro *str, t_tetro *firsttet);
int			maker(char *tetro, int tetronum);
void		print_tet(t_tetro *tet);

/*
** O_R_C.c
*/

int			error(int fd);
char		*readfile(int fd);

/*
** placencheck.c
*/

int			isfree(t_tetro *curr, char **grid, int y, int x);
char		**place(t_tetro *curr, char **grid, int y, int x, char letter);
char		**clear(t_tetro *curr, char **grid, int y, int x, char letter);
int 		l_bndry(int x, t_tetro *curr);
int			d_bndry(int y, t_tetro *curr, int gridsize);

/*
** fillit.c
*/

int			fillit(t_tetro *curr, char **grid, int y, int x, char a);
int 		doit(char **grid, t_tetro *fresh);
void		saveprint(char **grid, int y, int x);

#endif
