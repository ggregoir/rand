/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:14:26 by ggregoir          #+#    #+#             */
/*   Updated: 2018/03/22 16:41:29 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rand.h"

static size_t		ft_strlen(const char *str)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

static void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c =  nb + '0';
		write(1, &c, 1);
	}
}

int		atoipos(const char *str)
{
	unsigned int	nb;

	nb = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 - '0' + *str;
		str++;
	}
	return (nb);
}

void	printusage()
{
	ft_putstr("usage : ./rand [MAX] / ./rand [MIN MAX]\n");
	ft_putstr("MAX can't be above 100000\n");
	ft_putstr("./rand will display random number between 0 and 100\n.");
	ft_putstr("/rand MAX will display random number between 0 and MAX\n./ra");
	ft_putstr("nd MIN MAX will display random number between MIN and MAX\n");
}

int		check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return(i);
}