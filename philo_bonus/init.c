/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:04:35 by rthammat          #+#    #+#             */
/*   Updated: 2022/12/25 15:56:10 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	input_init(t_input *param, int n, char **argv)
{
	int	i;

	i = 1;
	if (!param)
	{
		printf("Error in allocating t_input\n");
		exit(1);
	}
	param->n_phi = ft_atoi(argv[i++]);
	param->t_die = ft_atoi(argv[i++]);
	param->t_eat = ft_atoi(argv[i++]);
	param->t_sleep = ft_atoi(argv[i++]);
	if (i == n)
		param->n_eat = ft_atoi(argv[i]);
	else
		param->n_eat = 0;
	param->start_time = current_time();
}

void	init_semaphore(t_philo *ph)
{
	int	n_phi;

	n_phi = ph->input->n_phi;
	sem_unlink("/fork");
	sem_unlink("/detach");
	sem_unlink("/print");
	sem_unlink("/dead");
	ph->fork = sem_open("/fork", O_CREAT, 0644, n_phi);
	ph->detach = sem_open("/detach", O_CREAT, 0644, 0);
	ph->print = sem_open("/print", O_CREAT, 0644, 1);
	ph->dead = sem_open("/dead", O_CREAT, 0644, 0);
	if (ph->fork == SEM_FAILED || ph->detach == SEM_FAILED
		|| ph->print == SEM_FAILED || ph->dead == SEM_FAILED)
	{
		printf("error to initialize semaphore\n");
		exit(1);
	}
}

void	struct_init(t_input *param, t_philo *ph)
{
	if (!ph)
	{
		free(param);
		ft_error(ph, "Error in allocating struct t_philo");
	}
	memset(ph, 0, sizeof(t_philo));
	ph->input = param;
	init_semaphore(ph);
	ph->finish = (int *)malloc(sizeof(int));
	ph->id = (pid_t *)malloc(sizeof(pid_t) * ph->input->n_phi);
	ph->child_id = (pid_t *)malloc(sizeof(pid_t) * ph->input->n_phi);
	ph->th = (pthread_t *)malloc(sizeof(pthread_t) * 3);
	if (!ph->id || !ph->child_id || !ph->finish || !ph->th)
		ft_error(ph, "Error in allocating malloc in struct");
	memset(ph->finish, 0, sizeof(int));
	memset(ph->id, 0, sizeof(pid_t) * ph->input->n_phi);
	memset(ph->child_id, 0, sizeof(pid_t) * ph->input->n_phi);
	memset(ph->th, 0, sizeof(pthread_t) * 3);
	ph->no = 0;
}
