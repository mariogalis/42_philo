/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:02:45 by mario             #+#    #+#             */
/*   Updated: 2023/04/13 16:47:11 by mario            ###   ########.fr       */
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

t_philo	*ft_lstnew(int i, t_args args)
{
	t_philo	*head;

	head = malloc(sizeof(t_philo));
	if (!head)
		return (NULL);
    head->args = args;
    pthread_mutex_init(&head->mutexfork[i], NULL);
    head->filoID= i;
    head->state = THINKING;
    head->repeats = args.neats;
    head->totalrepeats = 0;
	head->next = NULL;
	return (head);
}

t_philo	*getlist(t_args args)
{
	t_philo	*philo;
	int			i;

	i = 1;
	philo = ft_lstnew(i, args);
	if (!philo)
		return (NULL);
	while (i < args.philos)
	{
		ft_lstadd_back(&philo, ft_lstnew(i, args));
		i++;
	}
	return (philo);
}