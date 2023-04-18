/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:40 by mario             #+#    #+#             */
/*   Updated: 2023/04/18 19:40:07 by magonzal         ###   ########.fr       */
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
# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD -1
# define RESET "\x1b[0m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define RED "\x1b[31m"


typedef struct s_args
{
	int					philos;
	unsigned long int	tdie;
	unsigned long int	teat;
	unsigned long int	tsleep;
	int					neats;
}	t_args;

typedef struct s_philo
{
	t_args			args;
	pthread_t		forks;
	int				filoid;
	int				repeats;
	int				totalrepeats;
	unsigned long	startime;
	int				state;
	int				left;
	int				right;
	struct s_philo			*next;
}t_philo;

typedef struct s_all
{
	t_philo			*philos;
	pthread_mutex_t	mutexfork[202];
	pthread_mutex_t	mutex_print;
}t_all;

unsigned long int	ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_lstadd_back(t_philo **lst, t_philo *new);
void				ft_error(char *str);
void				get_args(int argc, char *argv[], t_args *args);
void				*ft_takefork(void *arg);
void				ft_eat(t_all *all);
void				ft_think(t_all *all);
unsigned long int	ft_timer(unsigned long int time_start);
t_philo				*getlist(t_args args);
t_philo				*ft_lstlast(t_philo *lst);
void				printargs(t_args *args);
void				printlst(t_philo	*philos);
int	print_mutex(t_all *all, char *str, char *color);
#endif