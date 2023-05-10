/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/05/10 18:40:30 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define EMODIE "💀"
#define EMOALLATE "🍻"

static int	death_checker(t_philo *philos)
{
	while (philos)
	{
		pthread_mutex_lock(&philos->all->mutex_dead);
		if ((ft_timer(philos->all->startime) - philos->lasteat)
			> philos->args.tdie)
		{
			philos->state = philos->filoid;
			pthread_mutex_unlock(&philos->all->mutex_dead);
			pthread_mutex_lock(&philos->all->mutex_print);
			printf(RED"[%lu ms] philo %d has died\n"EMODIE,
				ft_timer(philos->all->startime), philos->filoid);
			exit(0);
		}
		pthread_mutex_unlock(&philos->all->mutex_dead);
		philos = philos->next;
	}
	return (0);
}

int	all_ate(t_philo *philos)
{
	int		ate;
	t_philo	*aux;

	aux = philos;
	ate = 0;
	if (philos->args.neats == -1)
		return (0);
	while (aux)
	{
		if (aux->nate >= aux->args.neats)
			ate++;
		aux = aux->next;
	}
	if (ate == philos->args.philos)
		return (1);
	return (0);
}

int	auxstartroutine(t_philo *philos, t_philo *aux)
{
	ft_usleep(philos, 1);
	if (death_checker(aux) == 1)
		return (1);
	if (all_ate(philos) == 1)
	{
		print_mutex(philos, "all ate\t\t"EMOALLATE, RED);
		return (1);
	}
	return (0);
}

void	ft_startroutine(t_philo *philos)
{
	int		i;
	int		flag;
	t_philo	*aux;

	i = 0;
	flag = 0;
	aux = philos;
	while (aux)
	{
		pthread_create(&aux->thread, NULL, &routine, (void *)aux);
		aux = aux->next;
	}
	aux = philos;
	while (flag != 0)
		flag = auxstartroutine(philos, aux);
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
	philos->all->startime = ft_timer(0);
	ft_startroutine(philos);
	return (0);
}
