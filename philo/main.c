/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:30 by mario             #+#    #+#             */
/*   Updated: 2023/05/10 20:32:41 by magonzal         ###   ########.fr       */
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
			philos->all->state = philos->filoid;
			pthread_mutex_unlock(&philos->all->mutex_dead);
			pthread_mutex_lock(&philos->all->mutex_print);
			printf(RED"[%lu ms] philo %d has died\t"EMODIE,
				ft_timer(philos->all->startime), philos->filoid);
			printf("\n");
			pthread_mutex_unlock(&philos->all->mutex_print);
			return (1);
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
		pthread_mutex_lock(&philos->all->mutex_dead);
		if (aux->nate >= aux->args.neats)
			ate++;
		pthread_mutex_unlock(&philos->all->mutex_dead);
		aux = aux->next;
	}
	if (ate == philos->args.philos)
		return (1);
	return (0);
}

static void	help_me(t_philo *philos, t_philo *aux)
{
	while (1)
	{
		ft_usleep(philos, 1);
		if (death_checker(aux) == 1)
			break ;
		if (all_ate(philos) == 1)
		{
			print_mutex(philos, "all ate\t\t"EMOALLATE, RED);
			pthread_mutex_lock(&philos->all->mutex_dead);
			philos->all->state = philos->filoid;
			pthread_mutex_unlock(&philos->all->mutex_dead);
			break ;
		}
	}
}

void	ft_startroutine(t_philo *philos)
{
	t_philo	*aux;

	aux = philos;
	while (aux)
	{
		pthread_create(&aux->thread, NULL, &routine, (void *)aux);
		aux = aux->next;
	}
	aux = philos;
	help_me(philos, aux);
	aux = philos;
	while (aux)
	{
		pthread_join(aux->thread, NULL);
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
