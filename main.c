/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/03/21 17:00:38 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void printargs(t_args *args)
{
	printf("\n*******************\n");
	printf("Philo num   = %d\n", args->philos);
	printf("Time to die = %d\n", args->tdie);
	printf("Time to eat = %d\n", args->teat);
	printf("Time to sle = %d\n", args->tsleep);
	printf("Num of eats = %d\n", args->neats);
	printf("********************\n");
}


int	main(int argc, char *argv[])
{
	t_args args;

	memset(&args, 0, sizeof(t_args));
	if (argc < 5 || argc > 6)
		ft_error("Number of arguments not valid");
	else
		get_args(argc, argv, &args);

}