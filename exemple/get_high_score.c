/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_high_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:41:59 by frcugy            #+#    #+#             */
/*   Updated: 2015/02/28 16:04:40 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

char			*ft_str_super_dup(char *str, char c)
{
	char	*dest;
	int		i;
	int		b;

	dest = (char*)malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	b = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	while (str[i])
	{
		dest[b] = str[i];
		i++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

void			sort_tab(char **logins, char **scores)
{
	char	*tmp;
	int		i;
	int		b;

	i = 0;
	while (scores[i])
	{
		b = i + 1;
		if (scores[b] && ft_atoi(scores[i]) < ft_atoi(scores[b]))
		{
			tmp = scores[b];
			scores[b] = scores[i];
			scores[i] = tmp;
			tmp = logins[b];
			logins[b] = logins[i];
			logins[i] = tmp;
			if (i > 0)
				i--;
			continue ;
		}
		i++;
	}
}

void			print_in_fucking_file(t_env *env, char **logins, char **scores)
{
	int		i;

	i = 0;
	sort_tab(logins, scores);
	env->fp = open("./scores.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (logins[i])
	{
		write (env->fp, logins[i], ft_strlen(logins[i]));
		write (env->fp, "=", 1);
		write (env->fp, scores[i], ft_strlen(scores[i]));
		write (env->fp, "\n", 1);
		i++;
	}
	close(env->fp);
}

void			init_tob(t_env *env, int b, char ***logins, char ***scores)
{
	*scores = (char**)ft_memalloc(sizeof(char*) * (b + 2));
	*logins = (char**)ft_memalloc(sizeof(char*) * (b + 2));
	*scores[0] = ft_itoa(env->score);
	*logins[0] = ft_strdup(env->login);
}

void			get_score(t_env *env, int b)
{
	char		*line;
	char		**scores;
	char		**logins;

	scores = NULL;
	logins = NULL;
	env->fp = open("./scores.txt", O_RDONLY | O_CREAT, 0777);
	while (get_next_line(env->fp, &line) > 0)
		b++;
	close(env->fp);
	env->fp = open("./scores.txt", O_RDONLY | O_CREAT, 0777);
	init_tob(env, b, &logins, &scores);
	b = 1;
	while (get_next_line(env->fp, &line) > 0)
	{
		logins[b] = ft_str_super_dup2(line, '=');
		scores[b] = ft_str_super_dup(line, '=');
		b++;
	}
	close(env->fp);
	print_in_fucking_file(env, logins, scores);
	freetab((void**)logins, b + 1);
	free(logins);
	freetab((void**)scores, b + 1);
	free(scores);
}
