/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:51:06 by lemmerli          #+#    #+#             */
/*   Updated: 2026/11/14 14:35:01 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

long long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	sleep_in_steps(long long dur)
{
	long long	target_time;
	long long	act_time;

	act_time = get_time_ms();
	target_time = dur + act_time;
	while (act_time < target_time)
	{
		usleep(250);
		act_time = get_time_ms();
	}
}
