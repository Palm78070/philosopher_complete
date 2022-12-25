/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:05:34 by rthammat          #+#    #+#             */
/*   Updated: 2022/12/25 16:36:58 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_philo *ph)
{
	if (timestamp(ph) - ph->lastmeal > (unsigned long)ph->input->t_die)
	{
		ft_display(ph, timestamp(ph), "died");
		*ph->finish = 1;
		return (1);
	}
	return (0);
}

void	*check_dead(void *arg)
{
	int		i;
	t_philo	*ph;

	ph = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (is_dead(ph))
			break ;
		usleep(10);
	}
	sem_post(ph->dead);
	return (NULL);
}

void	*ft_dead(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	sem_wait(ph->dead);
	detach_all(ph);
	sem_post(ph->dead);
	exit(EXIT_SUCCESS);
	return (NULL);
}
