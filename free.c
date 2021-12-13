/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galee <galee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:18:07 by galee             #+#    #+#             */
/*   Updated: 2021/12/08 20:18:07 by galee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	free_all(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->num)
	{
		pthread_mutex_destroy(&(rule->philo[i].eating));
		i++;
	}
	free(rule->philo);
	i = 0;
	pthread_mutex_destroy(&(rule->print));
	while (i < rule->num)
	{
		pthread_mutex_destroy(&(rule->forks[i]));
		i++;
	}
}

void	detach_thread(t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->num)
	{
		pthread_detach(rule->philo[i].thread_id);
		i++;
	}
}
