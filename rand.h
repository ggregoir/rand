/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:30:16 by ggregoir          #+#    #+#             */
/*   Updated: 2018/03/22 16:38:21 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_H
# define RAND_H

# include <unistd.h>
# include <time.h>

void	printusage();
int		atoipos(const char *str);
void	ft_putnbr(int nb);
int		check(char *str);

#endif