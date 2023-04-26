/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/26 20:04:58 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philos)
{
	print_mutex(philos, "is thinking", YELLOW);
	ft_usleep(philos, philos->args.tsleep);
}

void	ft_sleep(t_philo *philos)
{
	print_mutex(philos, "is sleeping", BLUE);
	ft_usleep(philos, philos->args.tsleep);
}

int	ft_eat(t_philo *philos)
{
	// if(philos->repeats == philos->totalrepeats)
	// {
	// 	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	// 	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
	// 	return (1);
	// }
	philos->lasteat = ft_timer(philos->all->startime);
	print_mutex(philos, "is eating", GREEN);
	ft_usleep(philos, philos->args.teat);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo *philos;
	//int eats = 0;
	philos = (t_philo *) arg;
	if (philos->filoid % 2 != 0)
		ft_usleep(philos, 100);
	while(1)
	{
		// if(eats == philos->args.philos)
		// {
		// 	print_mutex(0,"everyone ate", RED);
		// 	exit(0);
		// }
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
	print_mutex(philos, "has taken a fork", RESET);
	pthread_mutex_lock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "has taken a fork", RESET);
}