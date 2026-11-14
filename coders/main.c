/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:55 by lemmerli          #+#    #+#             */
/*   Updated: 2026/11/14 14:36:59 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_args		args;
	long long	fix_time;
	long long	new_time;
	int			i;

	i = 0;
	if (parsing(argc, argv, &args) == -1)
		return (1);
	printf("Number of coders: %d\n", args.number_of_coders);
	printf("Time to burnout: %d\n", args.time_to_burnout);
	printf("Time to compile: %d\n", args.time_to_compile);
	printf("Time to debug: %d\n", args.time_to_debug);
	printf("Time to refactor: %d\n", args.time_to_refactor);
	printf("Number of compiles required: %d\n", args.number_of_compiles_required);
	printf("Dongle cooldown: %d\n", args.dongle_cooldown);
	printf("Schcceduler: %d\n", args.scheduler);
	fix_time = get_time_ms();
	while (i < 5)
	{
		sleep_in_steps(500);
		new_time = get_time_ms();
		printf("Time difference: %lld\n", new_time - fix_time);
		i++;
	}
	return (0);
}
