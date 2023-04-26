/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/25 19:13:17 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philos)
{
	print_mutex(philos, "is thinking", YELLOW);
	usleep(philos->args.tsleep);
}

void	ft_sleep(t_philo *philos)
{
	print_mutex(philos, "is sleeping", BLUE);
	usleep(philos->args.tsleep);
}

int	ft_eat(t_philo *philos)
{
	if(philos->repeats == philos->totalrepeats)
	{
		pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
		pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
		return (1);
	}
	print_mutex(philos, "is eating", GREEN);
	usleep(philos->args.teat);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
		return (0);
}

void	*routine(void *arg)
{
	t_philo *philos;
	int eats = 0;
	philos = (t_philo *) arg;
	if (philos->filoid % 2 != 0)
		usleep(500);
	while(1)
	{
		if(eats == philos->args.philos)
		{
			print_mutex(0,"everyone ate", RED);
			exit(0);
		}
		ft_takefork(philos);
		eats += ft_eat(philos);
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