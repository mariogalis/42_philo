/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/04/18 19:37:30 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	leaks(void)
// {
// 	system("leaks philo");
// }
void	ft_startroutine(t_all all)
{
	int		i;
	t_all	aux;

	i = 0;
	aux = all;
	while (aux.philos)
	{
		pthread_create(&aux.philos->forks, NULL, &ft_takefork, (void *)&all);
		aux.philos = aux.philos->next;
		i++;
	}
	i = 0;
	aux = all;
	while (aux.philos)
	{
		pthread_join(&aux.philos->forks[i], NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philos;
	t_all	all;
	int		i;

	//atexit(leaks);
	i = 1;
	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6)
		ft_error("Number of arguments not valid");
	else
		get_args(argc, argv, &args);
	philos = getlist(args);
	all.philos = philos;
	pthread_mutex_init(&all.mutex_print, NULL);
	while (i < args.philos)
	{
		pthread_mutex_init(&all.mutexfork[i], NULL);
		i++;
	}
	printlst(philos);
	ft_startroutine(all);
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
		printf("----------------------------------\n");
		aux = aux->next;
		i++;
	}
}
