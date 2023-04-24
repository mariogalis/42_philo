/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/04/24 20:30:20 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_startroutine(t_philo *philos)
{
	int		i;
	t_philo	*aux;

	i = 0;
	aux = philos;
	philos->startime = timestamp();
	while (aux)
	{
		pthread_create(&aux->thread, NULL, &routine, (void *)aux);
		aux = aux->next;
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
	int		i;

	i = 1;
	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6)
		ft_error("Number of arguments not valid");
	else
		get_args(argc, argv, &args);
	philos = getlist(args);
	//printlst(philos);
	ft_startroutine(philos);
	return 0;
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
