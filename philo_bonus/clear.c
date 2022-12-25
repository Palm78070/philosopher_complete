/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:14:32 by rthammat          #+#    #+#             */
/*   Updated: 2022/12/25 16:25:07 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_clear(t_philo *ph)
{
	if (ph)
	{
		if (ph->input)
			free(ph->input);
		if (ph->id)
			free(ph->id);
		if (ph->child_id)
			free(ph->child_id);
		if (ph->finish)
			free(ph->finish);
		if (ph->th)
			free(ph->th);
		free(ph);
	}
}

void	ft_error(t_philo *ph, char *s)
{
	printf("%s\n", s);
	ft_clear(ph);
	exit(1);
}

int	detach_all(t_philo *ph)
{
	pthread_detach(ph->th[0]);
	pthread_detach(ph->th[1]);
	pthread_detach(ph->th[2]);
	return (0);
}
