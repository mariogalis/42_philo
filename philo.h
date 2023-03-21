/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:40 by mario             #+#    #+#             */
/*   Updated: 2023/03/21 16:57:34 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct s_args
{
	int	philos;
	int	tdie;
	int	teat;
	int	tsleep;
	int	neats;
}	t_args;

int     ft_atoi(const char *str);
int     ft_isdigit(int c);
void    ft_error(char *str);
void	get_args(int argc, char *argv[], t_args *args);


void printargs(t_args *args);
#endif