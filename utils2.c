/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:16:22 by magonzal          #+#    #+#             */
/*   Updated: 2023/04/24 20:33:54 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_mutex(t_philo *philos, char *str, char *color)
{
	pthread_mutex_lock(&philos->all->mutex_print);
	// if (check_dead(philo) == 1)
	// {
	// 	pthread_mutex_unlock(&all->data->mutex_print);
	// 	return (1);
	// }
	printf("%s TIME = %lu ms    Philo %d %s\n"RESET, color,ft_timer(philos->startime),philos->filoid, str);
	pthread_mutex_unlock(&philos->all->mutex_print);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

