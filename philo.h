/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:40 by mario             #+#    #+#             */
/*   Updated: 2023/04/17 21:09:36 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# define LEFT (philos->filoID + philos->args.philos - 1) % philos->args.philos
# define RIGHT (philos->filoID + 1) % philos->args.philos
# define THINKING 0
# define EATING 1
# define SLEEPING 2

typedef struct s_args
{
	int	philos;
	int	tdie;
	int	teat;
	int	tsleep;
	int	neats;
}	t_args;

typedef struct s_philo
{
	t_args			args;
	pthread_t		forks;
	pthread_mutex_t	mutexfork[200];
	int 			filoID;
	int				repeats;
	int				totalrepeats;
	int				state;
	unsigned long	startime;
	struct s_philo	*next;
	
}t_philo;


int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	ft_error(char *str);
void	get_args(int argc, char *argv[], t_args *args);
void	*ft_takefork(void *arg);
void	ft_eat(t_philo *philos);
void	ft_think(t_philo *philos);
unsigned long int	ft_timer(unsigned long int time_start);
t_philo	*getlist(t_args args);
t_philo	*ft_lstlast(t_philo *lst);



void printargs(t_args *args);
void printlst(t_philo	*philos);
#endif