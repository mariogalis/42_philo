/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:02:45 by mario             #+#    #+#             */
/*   Updated: 2023/04/19 18:44:45 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	only_digits(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("Only numbers");
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
	if (argc == 6)
		args->neats = ft_atoi(argv[5]);
	else
		args->neats = 0;
}

t_philo	*ft_lstnew(int i, t_args args, t_all *all)
{
	t_philo	*head;

	head = malloc(sizeof(t_philo));
	if (!head)
		return (NULL);
	head->args = args;
	head->filoid = i;
	head->state = THINKING;
	head->repeats = args.neats;
	head->totalrepeats = 0;
	head->next = NULL;
	head->startime = ft_timer(0);
	head->right = i;
	head->all = all;
	if (i == 1)
		head->left = args.philos;
	else
		head->left = (i + args.philos - 1) % args.philos;
	return (head);
}

t_philo	*getlist(t_args args)
{
	t_philo	*philo;
	t_all	*all;
	int		i;

	all = malloc(sizeof(t_all));
	i = 1;
	pthread_mutex_init(&all->mutex_print, NULL);
	while (i <= args.philos)
	{
		pthread_mutex_init(&all->mutexfork[i], NULL);
		i++;
	}
	i = 1;
	philo = ft_lstnew(i, args, all);
	if (!philo)
		return (NULL);
	i++;
	while (i <= args.philos)
	{
		ft_lstadd_back(&philo, ft_lstnew(i, args, all));
		i++;
	}
	return (philo);
}
