/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/04/26 20:27:30 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	death_checker(t_philo *philos)
{
	while (philos)
	{
		pthread_mutex_lock(&philos->all->mutex_dead);
		if ((ft_timer(philos->all->startime) - philos->lasteat) > philos->args.tdie)
		{
			philos->state = philos->filoid;
			pthread_mutex_unlock(&philos->all->mutex_dead);
			pthread_mutex_lock(&philos->all->mutex_print);
			printf(RED"[%lu ms] philo %d has died\n",
				ft_timer(philos->all->startime), philos->filoid + 1);
			exit(0);
		}
		pthread_mutex_unlock(&philos->all->mutex_dead);
		philos = philos->next;
	}
	return (0);
}

void	ft_startroutine(t_philo *philos)
{
	int		i;
	t_philo	*aux;

	i = 0;
	aux = philos;
	while (aux)
	{
		pthread_create(&aux->thread, NULL, &routine, (void *)aux);
		aux = aux->next;
	}
	aux = philos;
	while (1)
	{
		ft_usleep(philos, 1);
		if (death_checker(aux) == 1)
			break ;
	}
	aux = philos;
	while (aux)
	{
		pthread_join(&aux->thread[i], NULL);
		i++;
		aux = aux->next;
	}
}

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philos;

	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6)
		ft_error("Number of arguments not valid");
	else
		get_args(argc, argv, &args);
	philos = getlist(args);
	philos->all->startime = timestamp();
	//printlst(philos);
	ft_startroutine(philos);
	return (0);
}

void printlst(t_philo	*philos)
{
	t_philo	*aux;
	int		i;

	aux = philos;
	i = 1;
	while (aux != NULL)
	{
		printf("FILO NUMERO %d\n", i);
		printf("ESTADO = %d\n", aux->state);
		printf("ID DE FILO %d\n", aux->filoid);
		printf("REPEATS %d\n", aux->repeats);
		printf("TOTAL REPEATS %d\n", aux->totalrepeats);
		printf("START TIME : %lu \n", aux->startime);
		printf("TENEDOR DERECHO %d\n", aux->right);
		printf("TENEDOR IZQUIERDO %d\n", aux->left);
		printf("START TIME = %lld\n", philos->all->startime);
		printf("----------------------------------\n");
		aux = aux->next;
		i++;
	}
}
