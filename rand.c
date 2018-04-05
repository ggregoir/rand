/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:16:51 by ggregoir          #+#    #+#             */
/*   Updated: 2018/03/22 16:42:02 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rand.h"

int		rand_seed (unsigned int *seed)
{
	unsigned int next = *seed;
	int result;

	next *= 1103515245;
	next += 12345;
	result = (unsigned int) (next / 65536) % 2048;

	next *= 1103515245;
	next += 12345;
	result <<= 10;
	result ^= (unsigned int) (next / 65536) % 1024;

	next *= 1103515245;
	next += 12345;
	result <<= 10;
	result ^= (unsigned int) (next / 65536) % 1024;

	*seed = next;

	return result;
}

int		randrange(int min, int max)
{
	unsigned int j;
	int result;

	j = (unsigned int)&j + (unsigned int)time(NULL);
	result = rand_seed(&j);
	if (max > 100000 || min < 0 || max < min)
		return (-1);
	result = rand_seed((unsigned int*)&result);
	result = result % (max + 1);
	while (result < min)
		result = result + (max - min);
	while (result > max)
		result = result - (max - min);
	return (result);
}

int		randmax(int max)
{
	unsigned int j;
	int result;

	j = (unsigned int)&j + (unsigned int)time(NULL);
	result = rand_seed(&j);
	if (max > 100000)
		return (-1);
	result = rand_seed((unsigned int*)&result);
	result = result % (max + 1);
	return (result);
}

int		rand100()
{
	unsigned int	j;
	int				result;
	
	j = (unsigned int)&j + (unsigned int)time(NULL);
	result = rand_seed(&j);
	result = rand_seed((unsigned int*)&result);
	result = result % 101;
	return (result);
}

int		main(int argc, char **argv)
{
	int		result;
	int		i;

	i = 1;
	result = -1;
	while (i != argc)
	{
		if ((check(argv[i])) == 0)
		{
			printusage();
			return(-1);
		}
		i++;
	}
	if (argc == 1)
		result = rand100();
	else if (argc == 2)
		result = randmax(atoipos(argv[1]));
	else if (argc == 3)
		result = randrange(atoipos(argv[1]), atoipos(argv[2]));
	if (result == -1)
		printusage();
	else
	{
		ft_putnbr(result);
		write(1, "\n", 1);
	}
}

