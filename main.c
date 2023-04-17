/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/04/13 17:12:16 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	leaks(void)
// {
// 	system("leaks philo");
// }


// void*	routine(t_args *args)
// {
// 	while(1)
// 	{
// 		ft_think();
// 	}
// }

void ft_startroutine(t_philo	*philos)
{
	int i;
	t_philo *aux;
	i = 0;
	aux = philos;
	while(aux)
	{
		pthread_create(&aux->forks, NULL, ft_think, philos);
		i++;
		aux = aux->next;
	}
	for (i = 0; i < 5; i++) {
     pthread_join(&philos->forks[i], NULL);  // esperar a que todos los hilos terminen
    }
}

int	main(int argc, char *argv[])
{
	t_args args;
	t_philo	*philos;
	
	//atexit(leaks);
	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6)
		ft_error("Number of arguments not valid");
	else
		get_args(argc, argv, &args);
	philos = getlist(args);
	printlst(philos);
	ft_startroutine(philos);
}

void printlst(t_philo	*philos)
{
	t_philo	*aux;
	aux = philos;
	int i = 1;
	
	while(aux !=NULL)
	{
		printf("FILO NUMERO %d\n", i);
		printf("ESTADO = %d\n",aux->state);
		printf("ID DE FILO %d\n",aux->filoID);
		printf("REPEATS %d\n",aux->repeats);
		printf("TOTAL REPEATS %d\n",aux->totalrepeats);
		printf("----------------------------------\n");
		aux = aux->next;
		i++;
	}
}