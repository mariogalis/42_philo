/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/05/10 20:47:30 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define EMOEAT "🍔"
#define EMOFORK "🍴"
#define EMOSLEEP "😴"
#define EMOTHINK "🤔"

static int	ft_think(t_philo *philos)
{
	print_mutex(philos, "is thinking\t"EMOTHINK, YELLOW);
	pthread_mutex_lock(&philos->all->mutex_dead);
	return (philos->all->state);
}

static int	ft_sleep(t_philo *philos)
{
	print_mutex(philos, "is sleeping\t"EMOSLEEP, BLUE);
	ft_usleep(philos, philos->args.tsleep);
	pthread_mutex_lock(&philos->all->mutex_dead);
	return (philos->all->state);
}

static int	ft_eat(t_philo *philos)
{
	print_mutex(philos, "is eating\t"EMOEAT, GREEN);
	pthread_mutex_lock(&philos->all->mutex_dead);
	philos->nate++;
	philos->lasteat = ft_timer(philos->all->startime);
	pthread_mutex_unlock(&philos->all->mutex_dead);
	ft_usleep(philos, philos->args.teat);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
	pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
	pthread_mutex_lock(&philos->all->mutex_dead);
	return (philos->all->state);
}

static int	ft_takefork(t_philo *philos)
{
	pthread_mutex_lock(&philos->all->mutexfork[philos->left]);
	print_mutex(philos, "has taken a fork\t"EMOFORK, RESET);
	pthread_mutex_lock(&philos->all->mutex_dead);
	if (philos->args.philos == 1)
	{
		pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
		return (1);
	}
	pthread_mutex_unlock(&philos->all->mutex_dead);
	pthread_mutex_lock(&philos->all->mutexfork[philos->right]);
	print_mutex(philos, "has taken a fork\t"EMOFORK, RESET);
	pthread_mutex_lock(&philos->all->mutex_dead);
	return (philos->all->state);
}

void	routineaux(t_philo *philos)
{
	while (1)
	{
		if (ft_takefork(philos) != -1)
		{
			pthread_mutex_unlock(&philos->all->mutexfork[philos->left]);
			pthread_mutex_unlock(&philos->all->mutexfork[philos->right]);
			break ;
		}
		pthread_mutex_unlock(&philos->all->mutex_dead);
		if (ft_eat(philos) != -1)
			break ;
		pthread_mutex_unlock(&philos->all->mutex_dead);
		if (ft_sleep(philos) != -1)
			break ;
		pthread_mutex_unlock(&philos->all->mutex_dead);
		if (ft_think(philos) != -1)
			break ;
		pthread_mutex_unlock(&philos->all->mutex_dead);
	}
}
