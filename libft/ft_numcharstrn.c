/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcharstrn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelee <lelee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:23:35 by lelee             #+#    #+#             */
/*   Updated: 2019/08/13 17:23:46 by lelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Courtesy of Jackson
*/

#include "libft.h"

int		ft_numcharstrn(const char *str, int tofind, int n)
{
	int numchar;
	int i;

	numchar = 0;
	i = -1;
	if (!str || !tofind || !n)
		return (0);
	while (--n >= 0)
		if (str[++i] == (char)tofind)
			numchar++;
	return (numchar);
}
