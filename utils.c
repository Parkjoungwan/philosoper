/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galee <galee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:18:07 by galee             #+#    #+#             */
/*   Updated: 2021/12/06 16:47:42 by joupark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_printf(t_rule *rule, char *str, int idx)
{
	pthread_mutex_lock(&(rule->print));
	if (rule->die == 0)
	{
		printf("%lld %d ", set_time() - rule->t_start, idx);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(rule->print));
}

int	ft_atoi(const char *str)
{
	int			i;
	int			r;
	long long	n;
	int			c;

	i = 0;
	r = 1;
	while ((str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			r = -1;
	n = 0;
	c = n;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + r * (str[i++] - '0');
		if (r == 1 && n < 0)
			return (-1);
		else if (r == -1 && n > 0)
			return (0);
	}
	return (n);
}
