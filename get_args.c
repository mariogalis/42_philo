/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:02:45 by mario             #+#    #+#             */
/*   Updated: 2023/05/10 20:47:28 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	only_digits(char *argv[])
{
	int	i;
	int	j;
	int	only_0;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		only_0 = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != '0')
				only_0 = 1;
			if (!ft_isdigit(argv[i][j]))
				ft_error("Only numbers");
			j++;
		}
		if (only_0 == 0)
			ft_error("Not a valid number");
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
		args->neats = -1;
}

t_philo	*ft_lstnew(int i, t_args args, t_all *all)
{
	t_philo	*head;

	head = malloc(sizeof(t_philo));
	if (!head)
		return (NULL);
	head->args = args;
	head->filoid = i;
	head->repeats = args.neats;
	head->nate = 0;
	head->next = NULL;
	head->startime = ft_timer(0);
	head->right = i;
	head->all = all;
	head->lasteat = 0;
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
	all->state = -1;
	i = 1;
	pthread_mutex_init(&all->mutex_print, NULL);
	pthread_mutex_init(&all->mutex_dead, NULL);
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

void	*routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *) arg;
	pthread_mutex_lock(&philos->all->mutex_dead);
	philos->lasteat = ft_timer(philos->all->startime);
	pthread_mutex_unlock(&philos->all->mutex_dead);
	if (philos->filoid % 2 != 0)
		ft_usleep(philos, 20);
	routineaux(philos);
	pthread_mutex_unlock(&philos->all->mutex_dead);
	return (0);
}
