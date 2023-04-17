/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/17 21:12:55 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philos)
{

	printf("%d is thinking...\n", philos->filoID);
	sleep(philos->args.tsleep);
	ft_takefork(philos);
}

void	ft_sleep(t_philo *philos)
{
	printf("Filósofo %d esta sobando \n", philos->filoID);
	sleep(philos->args.tsleep);
	ft_think(philos);
}

void	ft_eat(t_philo *philos)
{
	printf("Filósofo %d esta zampando\n", philos->filoID);
	sleep(philos->args.teat);
	pthread_mutex_unlock(&philos->mutexfork[LEFT]);
	pthread_mutex_unlock(&philos->mutexfork[RIGHT]);
	// if(philos->repeats != 0 && philos->repeats != philos->totalrepeats)
	// 	philos->totalrepeats++;
	ft_sleep(philos);
}

void	*ft_takefork(void *arg)
{
	printf("HOLI");
	t_philo *philos = (t_philo *) arg;
	
	pthread_mutex_lock(&philos->mutexfork[LEFT]);
	printf("Filósofo %d tiene el tenedor izquierdo \n", philos->filoID);
	pthread_mutex_lock(&philos->mutexfork[RIGHT]);
	printf("Filósofo %d tiene ambos tenedores \n", philos->filoID);
	ft_eat(philos);
	
	return (0);
}


