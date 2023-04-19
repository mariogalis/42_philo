/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/19 18:58:42 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philos)
{
	print_mutex(philos, "Esta pensando", YELLOW);
	usleep(philos->args.tsleep);
}

void	ft_sleep(t_philo *philos)
{
	print_mutex(philos, "ESTA SOBANDO", BLUE);
	usleep(philos->args.tsleep);
}

void	ft_eat(t_philo *philos)
{
	print_mutex(philos, "ESTA ZAMPANDO", GREEN);
	usleep(philos->args.teat);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "SUELTA LOS TENEDORES", RESET);
}

void	*routine(void *arg)
{
	t_philo *philos;
	philos = (t_philo *) arg;
	if (philos->filoid % 2 != 0)
		usleep(100);
	while(1)
	{
		ft_takefork(philos);
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
	}
	return(0);
}

void	ft_takefork(t_philo *philos)
{
	pthread_mutex_lock(&philos->all->mutexfork[philos->left]);
	print_mutex(philos, "TIENE EL TENEDOR IZQUIERDO", RESET);
	pthread_mutex_lock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "TIENE LOS DOS TENEDORES", RESET);
}