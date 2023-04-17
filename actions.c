/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/13 17:05:53 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philos)
{
	sleep(philos->args.tdie);
	pthread_mutex_unlock(&philos->mutexfork[LEFT]);
    pthread_mutex_unlock(&philos->mutexfork[RIGHT]);
	if(philos->repeats != 0 && philos->repeats != philos->totalrepeats)
		philos->totalrepeats++;
	
}

void	ft_takefork(t_philo *philos)
{
	pthread_mutex_lock(&philos->mutexfork[LEFT]);
	printf("Filósofo %d tiene el tenedor izquierdo (%d)...\n", philos->filoID, LEFT);
	pthread_mutex_lock(&philos->mutexfork[RIGHT]);
    printf("Filósofo %d tiene ambos tenedores (%d, %d) y está comiendo...\n", philos->filoID, LEFT, RIGHT);
	ft_eat(philos);
}

void	*ft_think(void *arg)
{
	t_philo *philos = (t_philo *) arg;

	printf("%d is thinking", philos->filoID);
	sleep(philos->args.tsleep);
	ft_takefork(philos);
	return 0;
}

