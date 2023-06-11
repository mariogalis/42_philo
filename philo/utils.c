/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:57:47 by mario             #+#    #+#             */
/*   Updated: 2023/05/10 18:35:48 by magonzal         ###   ########.fr       */
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

unsigned long int	ft_atoi(char const *str)
{
	unsigned long long int	ans;

	ans = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str > 47 && *str < 58)
	{
		ans = ans * 10 + (*str - 48);
		str++;
	}
	return ((unsigned long int)ans);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
