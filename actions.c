/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/19 18:05:09 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philos)
{
	print_mutex(philos, "Esta pensando", YELLOW);
	sleep(philos->args.tsleep);
	ft_takefork(philos);
}

void	ft_sleep(t_philo *philos)
{
	print_mutex(philos, "ESTA SOBANDO", BLUE);
	sleep(philos->args.tsleep);
	ft_think(philos);
}

void	ft_eat(t_philo *philos)
{
	print_mutex(philos, "ESTA ZAMPANDO", GREEN);
	sleep(philos->args.teat);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "SUELTA LOS TENEDORES", RESET);
	ft_sleep(philos);
}

void	*ft_takefork(void *arg)
{
	t_philo *philos;
	philos = (t_philo *) arg;

	pthread_mutex_lock(&philos->all->mutexfork[philos->left]);
	print_mutex(philos, "TIENE EL TENEDOR IZQUIERDO", RESET);
	pthread_mutex_lock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "TIENE LOS DOS TENEDORES", RESET);
	ft_eat(philos);
	return (0);
}