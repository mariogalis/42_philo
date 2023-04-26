/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:16:22 by magonzal          #+#    #+#             */
/*   Updated: 2023/04/26 20:13:03 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_mutex(t_philo *philos, char *str, char *color)
{
	pthread_mutex_lock(&philos->all->mutex_print);
	if (check_dead(philos) == 1)
	{
		pthread_mutex_unlock(&philos->all->mutex_print);
		return (1);
	}
	printf("%s%lu %d %s\n"RESET, color, ft_timer(philos->startime), philos->filoid, str);
	pthread_mutex_unlock(&philos->all->mutex_print);
	return (0);
}

int	ft_usleep(t_philo *philos, unsigned long int time)
{
	unsigned long int	slept;

	slept = ft_timer(philos->all->startime);
	while (ft_timer(philos->all->startime) - slept < time)
	{
		usleep(50);
		if (check_dead(philos) == 1)
			return (0);
	}
	return (0);
}

unsigned long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	check_dead(t_philo *philos)
{
	pthread_mutex_lock(&philos->all->mutex_dead);
	if (philos->state != -1)
	{
		pthread_mutex_unlock(&philos->all->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philos->all->mutex_dead);
	return (0);
}
