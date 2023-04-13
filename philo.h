/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:40:40 by mario             #+#    #+#             */
/*   Updated: 2023/04/13 16:04:33 by mario            ###   ########.fr       */
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
# define LEFT (i + N - 1) % N
# define RIGHT (i + 1) % N
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
	pthread_t		fork;
	pthread_mutex_t	mutexfork;
	int 			filoID;
	int				repeats;
	int				totalrepeats;
	int				state;
	struct s_philo			*next;
	
}t_philo;


int     ft_atoi(const char *str);
int     ft_isdigit(int c);
void    ft_error(char *str);
void	get_args(int argc, char *argv[], t_args *args);
void	ft_think(t_args args, int philo);
void	ft_takefork(t_args args, int philo);
t_philo	*getlist(t_args args);
t_philo	*ft_lstlast(t_philo *lst);
void	ft_lstadd_back(t_philo **lst, t_philo *new);



void printargs(t_args *args);
void printlst(t_philo	*philos);
#endif