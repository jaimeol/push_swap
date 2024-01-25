/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:01:44 by jolivare          #+#    #+#             */
/*   Updated: 2024/01/23 13:03:01 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	numspli(char const *s, char c)
{
	char	last;
	int		i;
	char	cont;

	last = c;
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (last == c && s[i] != c)
			cont++;
		last = s[i];
		i++;
	}
	return (cont);
}

static int	lon_sub(char const *s, char c, int len)
{
	int	sol;

	sol = 0;
	while (s[len])
	{
		if (s[len] == c)
			return (sol);
		len++;
		sol++;
	}
	return (sol);
}

static int	fill(const char *s, char *sol, int pos, int sublen)
{
	int	j;

	j = 0;
	while (j < sublen)
	{
		sol[j] = s[pos];
		j++;
		pos++;
	}
	sol[j] = '\0';
	return (j);
}

static char	**freeer(char **sol, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(sol[i]);
		i++;
	}
	free(sol);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**sol;
	int		i;
	int		j;
	int		sublen;

	sol = (char **) malloc(sizeof(*sol) * (numspli(s, c) + 1));
	if (!sol)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		sublen = lon_sub(s, c, i);
		sol[j] = (char *) malloc(sizeof(char) * (sublen + 1));
		if (!sol[j])
			return (freeer(sol, j));
		i += fill(s, sol[j], i, sublen);
		j++;
	}
	sol[j] = NULL;
	return (sol);
}
