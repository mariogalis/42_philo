/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:57:47 by mario             #+#    #+#             */
/*   Updated: 2023/04/13 16:04:29 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstlast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (!new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	ft_error(char *err)
{
	printf("Error : %s\n", err);
	exit(1);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	ans;
	int						sign;

	ans = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	else if (*str == 43)
		str++;
	while (*str > 47 && *str < 58)
	{
		ans = ans * 10 + (*str - 48);
		str++;
	}
	if (ans > 9223372036854775807 && sign < 0)
		return (0);
	else if (ans > 9223372036854775807 && sign > 0)
		return (-1);
	return ((int)(ans * sign));
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

void printargs(t_args *args)
{
	printf("\n*******************\n");
	printf("Philo num   = %d\n", args->philos);
	printf("Time to die = %d\n", args->tdie);
	printf("Time to eat = %d\n", args->teat);
	printf("Time to sle = %d\n", args->tsleep);
	printf("Num of eats = %d\n", args->neats);
	printf("********************\n");
}