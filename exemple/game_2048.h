/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdemay <tdemay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:30:41 by tdemay            #+#    #+#             */
/*   Updated: 2015/02/28 17:32:16 by tdemay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# define ESC 27

# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

enum			e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_env
{
	int		score;
	char	*login;
	int		len;
	int		**tab;
	int		victory;
	WINDOW	**win;
	WINDOW	*head;
	int		fp;
}				t_env;

void			startwin(t_env *env);
void			game(t_env *env);
void			freetab(void **tab, int len);
int				mid_move_up(t_env *env, int i, int b, int d);
int				mid_move_down(t_env *env, int i, int b, int d);
int				mid_move_left(t_env *env, int i, int b, int d);
int				mid_move_right(t_env *env, int i, int b, int d);
int				check_loose_hub(t_env *env);
int				check_loose(t_env *env);
int				check_win(t_env *env);
int				move_tab_up(t_env *env, int i, int c);
int				move_tab_down(t_env *env, int i, int c);
int				move_tab_right(t_env *env, int i, int c);
int				move_tab_left(t_env *env, int i, int c);
void			get_random_tab(int **tab, int len, int d);
int				fus_tab_right(t_env *env, int i, int c);
int				fus_tab_left(t_env *env, int i, int c);
int				fus_tab_up(t_env *env, int i, int c);
int				fus_tab_down(t_env *env, int i, int c);
void			print_tab(int **tab, int len);
int				rsqrt(int number);
void			print_victory(void);
void			print_loose(void);
void			print_title(t_env *env);
int				power_two(unsigned int x);
int				menu(t_env *env, int ch, int sel);
void			highscore(t_env *env);
void			get_score(t_env *env, int b);
char			*ft_str_super_dup2(char *str, char c);
void			get_name(t_env *env);

#endif
