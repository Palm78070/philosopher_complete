/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:07:36 by rthammat          #+#    #+#             */
/*   Updated: 2023/01/14 01:15:10 by rath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_input	*param;
	t_philo	*ph;

	if (argc < 5 || argc > 6)
	{
		printf("Error param: n_philo time_die time_eat time_sleep n_eat\n");
		exit(0);
	}
	check_input(argc, argv);
	param = (t_input *)malloc(sizeof(t_input));
	ph = (t_philo *)malloc(sizeof(t_philo));
	input_init(param, argc - 1, argv);
	struct_init(param, ph);
	fork_process(ph);
	return (0);
}
