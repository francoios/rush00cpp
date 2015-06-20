/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:29:41 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 17:26:39 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			**init_tab(int len)
{
	int		**tab;
	int		i;
	int		b;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * len);
	while (i < len)
	{
		tab[i] = (int*)malloc(sizeof(int) * len);
		i++;
	}
	i = 0;
	while (i < len)
	{
		b = 0;
		while (b < len)
		{
			tab[i][b] = 0;
			b++;
		}
		i++;
	}
	get_random_tab(tab, len, 2);
	return (tab);
}

void		init_env_game(t_env *env)
{
	int			i;

	i = 0;
	env->score = 0;
	env->login = ft_strdup("John");
	env->victory = 0;
	env->tab = init_tab(env->len);
	env->win = (WINDOW**)malloc(sizeof(WINDOW*) * (env->len * env->len));
	while (i < (env->len * env->len))
	{
		env->win[i] = newwin(LINES / env->len, COLS / env->len,
			((i % env->len) * ((LINES - 3) / env->len)) + 2,
			(i / env->len) * (COLS / env->len));
		i++;
	}
}

void		del_env_game(t_env *env)
{
	int			i;

	i = 0;
	while (i < (env->len * env->len))
	{
		delwin(env->win[i]);
		i++;
	}
	free (env->login);
	free (env->win);
	freetab((void**)env->tab, env->len);
	free(env->tab);
}

void		sighandler(int signum)
{
	if (signum == SIGINT)
	{
		endwin();
		exit(1);
	}
}

int			main(void)
{
	t_env	env;
	int		ret;

	if (!power_two(WIN_VALUE))
		return (0);
	signal(SIGINT, sighandler);
	startwin(&env);
	while (true)
	{
		ret = menu(&env, 0, 0);
		if (ret == 2)
			break ;
		else if (ret == 1)
			highscore(&env);
		else if (ret == 0)
		{
			init_env_game(&env);
			game(&env);
			get_name(&env);
			get_score(&env, 0);
			del_env_game(&env);
		}
	}
	return (endwin(), 0);
}
