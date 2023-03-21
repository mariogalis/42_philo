/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:02:45 by mario             #+#    #+#             */
/*   Updated: 2023/03/21 17:03:15 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void only_digits(char *argv[])
{
    int i = 1, j;

    while (argv[i] != NULL) {
        j = 0;
        while (argv[i][j] != '\0') {
            if (!ft_isdigit(argv[i][j])) {
				ft_error("Only numbers");
            }
            j++;
        }
        i++;
    }
}

void	get_args(int argc, char *argv[], t_args *args)
{
	only_digits(argv);
	args->philos = ft_atoi(argv[1]);
	args->tdie = ft_atoi(argv[2]);
	args->teat = ft_atoi(argv[3]);
	args->tsleep = ft_atoi(argv[4]);
	if(argc == 6)
		args->neats = ft_atoi(argv[5]);
	else
		args->neats = 0;
}