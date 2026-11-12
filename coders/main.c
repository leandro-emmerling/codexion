/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:55 by lemmerli          #+#    #+#             */
/*   Updated: 2026/11/12 19:41:54 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_args	args;

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
	return (0);
}
