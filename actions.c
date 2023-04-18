/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:26 by mario             #+#    #+#             */
/*   Updated: 2023/04/18 19:39:53 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_all *all)
{
	print_mutex(all, "Esta pensando", YELLOW);
	sleep(all->philos->args.tsleep);
	ft_takefork(all);
}

void	ft_sleep(t_all *all)
{
	print_mutex(all, "ESTA SOBANDO", BLUE);
	sleep(all->philos->args.tsleep);
	ft_think(all);
}

void	ft_eat(t_all *all)
{
	print_mutex(all, "ESTA ZAMPANDO", GREEN);
	sleep(all->philos->args.teat);
	pthread_mutex_unlock(&all->mutexfork[all->philos->left]);
	pthread_mutex_unlock(&all->mutexfork[all->philos->right]);
	print_mutex(all, "SUELTA LOS TENEDORES", RESET);
	// if (philos->repeats != 0 && philos->repeats != philos->totalrepeats)
	// 	philos->totalrepeats++;
	// else if (philos->repeats == philos->totalrepeats)
	// {
	// 	printf(RED"FILO %d se lleno comio %d veces\n", philos->filoid, philos->totalrepeats);
	// 	exit(0);
	// }
	ft_sleep(all);
}

void	*ft_takefork(void *arg)
{
	t_all *all;

	all = (t_all *) arg;
	pthread_mutex_lock(&all->mutexfork[all->philos->left]);
	printf("\tPHILO %d CON TENEDOR %d\n", all->philos->filoid, all->philos->left);
	print_mutex(all, "TIENE EL TENEDOR IZQUIERDO", RESET);
	pthread_mutex_lock(&all->mutexfork[all->philos->right]);
	print_mutex(all, "TIENE LOS DOS TENEDORES", RESET);
	printf("\tPHILO %d CON TENEDORES %d y %d \n", all->philos->filoid, all->philos->left, all->philos->right);
	ft_eat(all);
	return (0);
}
