/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:16:22 by magonzal          #+#    #+#             */
/*   Updated: 2023/04/19 18:03:46 by magonzal         ###   ########.fr       */
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
	printf("%sPhilo %d %s\n"RESET, color, philos->filoid, str);
	pthread_mutex_unlock(&philos->all->mutex_print);
	return (0);
}