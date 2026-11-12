/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:27:58 by lemmerli          #+#    #+#             */
/*   Updated: 2026/11/12 19:05:15 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_input(char *s)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (ft_is_digit(s[i]) == 0)
			return (-1);
		res = res * 10 + (s[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	return (res);
}

int	check_scheduler(char *s, t_args *args)
{
	if (strcmp(s, "fifo") == 0)
	{
		args->scheduler = FIFO;
		return (0);
	}
	if (strcmp(s, "edf") == 0)
	{
		args->scheduler = EDF;
		return (0);
	}
	return (print_error("scheduler must be 'fifo' or 'edf'"));
}

int	check_zeros(t_args *args)
{
	if (args->number_of_coders == 0)
		return (print_error("number_of_coders must be at least 1"));
	if (args->time_to_burnout == 0)
		return (print_error("time_to_burnout must be at least 1"));
	if (args->number_of_compiles_required == 0)
		return (print_error("number_of_compiles_required must be at least 1"));
	return (0);
}

int	parsing(int argc, char **argv, t_args *args)
{
	int	i;

	i = 1;
	if (argc != 9)
		return (print_error("wrong number of arguments"));
	while (i <= 7)
	{
		if (check_input(argv[i]) == -1)
			return (print_error("invalid number"));
		i++;
	}
	args->number_of_coders = check_input(argv[1]);
	args->time_to_burnout = check_input(argv[2]);
	args->time_to_compile = check_input(argv[3]);
	args->time_to_debug = check_input(argv[4]);
	args->time_to_refactor = check_input(argv[5]);
	args->number_of_compiles_required = check_input(argv[6]);
	args->dongle_cooldown = check_input(argv[7]);
	if (check_scheduler(argv[8], args) == -1 || check_zeros(args) == -1)
		return (-1);
	return (0);
}
