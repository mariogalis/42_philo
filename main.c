/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/04/13 15:59:17 by mario            ###   ########.fr       */
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