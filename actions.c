/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/05/03 18:40:30 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define emoeat "🍔"
#define emofork "🍴"
#define emosleep "😴"
#define emothink "🤔"

void	ft_think(t_philo *philos)
{
	print_mutex(philos, "is thinking\t"emothink, YELLOW);
	ft_usleep(philos, philos->args.tsleep);
}

void	ft_sleep(t_philo *philos)
{
	print_mutex(philos, "is sleeping\t"emosleep, BLUE);
	ft_usleep(philos, philos->args.tsleep);
}

int	ft_eat(t_philo *philos)
{
	philos->lasteat = ft_timer(philos->all->startime);
	print_mutex(philos, "is eating\t\t"emoeat, GREEN);
	philos->nate++;
	ft_usleep(philos, philos->args.teat);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
	return (0);
}

void	*routine(void *arg)
{
	t_philo *philos;
	philos = (t_philo *) arg;
	if (philos->filoid % 2 != 0)
		ft_usleep(philos, 100);
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
	print_mutex(philos, "has taken a fork\t"emofork, RESET);
	pthread_mutex_lock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "has taken a fork\t"emofork, RESET);
}