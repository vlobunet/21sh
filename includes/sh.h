/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <vlobunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 11:44:00 by vlobunet          #+#    #+#             */
/*   Updated: 2018/08/16 16:56:02 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ftw.h>
# include <unistd.h>
# include <sys/param.h>
# include <fcntl.h>

/*
**╔═══════════════╦═════════════════════════════════════════════════════╗
**║     TOKEN     ║                          KEY                        ║
**╠═══════════════╬═════════════════════════════════════════════════════╣
**║ 1	CMD		  ║	ALT_RT	alt+right		по слову вправо				║
**║ 3	";"		  ║	ALT_LT	alt+left		по слову влево				║
**║ 4	'|"		  ║	HOME	home			в начало					║
**║ 6	"<"		  ║	END		end				в конец						║
**║ 7	">"		  ║	RIGHT	right			по символу вправо			║
**║ 8	'||"	  ║	LEFT	left 			по символу влево			║
**║ 9	'&&"	  ║	UP		up				вверх на 1					║
**║ 10	"<<"	  ║	DOWN	down			вниз на 1					║
**║ 11	">>"	  ║	ESC		esc				очистить или выйти			║
**║ 12	"<>"	  ║	BACK	backspase 		удалить перед курсором 1	║
**║ 13	"<&"	  ║	TAB		tab				автодополнение				║
**║ 14	">&"	  ║	DEL		del				удалить после курсора все	║
**║ 18	">>&"	  ║	S_L		shift+left		выделить слева 1 символ		║
**║ 19	"&>"	  ║	S_R		shift+right		выделить справа 1 символ	║
**║ 20	"&<"	  ║	S_H		shift+home		выделить до начала строки	║
**║ 21	"&>>"	  ║	S_E		shift+end		выделить до конца строки	║
**║ 22	"&<<"	  ║	SA_L	shift+alt+left	выделить левое слово		║
**║ 15	FD_IN	  ║	SA_R	shift+alt+right	выделить правое слово		║
**║ 16	TARGET	  ║	A_A		alt+a			выделить всю строку			║
**║ 17	ARG		  ║	A_CPY	alt+c			копировать					║
**║               ║	A_PST	alt+v			вставить					║
**║               ║	A_CUT	alt+x			вырезать					║
**╚═══════════════╩═════════════════════════════════════════════════════╝
*/

# define ALT_RT		1130044187
# define ALT_LT		1146821403
# define HOME		4741915
# define END		4610843
# define RIGHT		4414235
# define LEFT		4479771
# define UP			4283163
# define DOWN		4348699
# define ESC		27
# define BACK		127
# define TAB		9
# define DEL		2117294875
# define S_L		74982532143899
# define S_R		73883020516123
# define S_H		79380578655003
# define S_E		77181555399451
# define SA_L		19193286420945691
# define SA_R		18911811444235035
# define A_CPY		42947
# define A_PST		10127586
# define A_CUT		8948194
# define A_A		42435

# define LENLIB		16

# define STDINN		0
# define STDOUT		1
# define STDERR		2

typedef struct			s_history
{
	char				*content;
	int					id;
	struct s_history	*prev;
	struct s_history	*next;
}						t_history;

typedef struct			s_sel
{
	char				*cmd;
	int					strlen_mes;
	struct termios		savetty;
	int					pos[3];
	char				**m_env;
	t_history			*story;
	char				*cpy;
	int					real_story;
	int					size_sel;
	int					f;
	int					fd[3];
}						t_sel;

typedef struct			s_list
{
	char				*content;
	char				*name;
	int					size;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

typedef struct			s_tmp
{
	char				*left;
	char				*right;
	int					ws;
	t_list				*e;
}						t_tmp;
t_sel					g_sel;

typedef struct			s_token
{
	struct s_token		*next;
	struct s_token		*prev;
	int					sel;
	char				*content;
	int					type;
}						t_token;

typedef struct			s_scanf
{
	char				*cmd;
	long				key;
}						t_scanf;

typedef struct			s_lib
{
	int					token;
	int					priority;
}						t_lib;

typedef struct			s_tree
{
	int					token;
	char				**cmd;
	t_token				*token_or;
	struct s_tree		*father;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

typedef struct			s_param
{
	int					e;
	int					b;
	int					n;
	int					flag;
	int					i;
	int					u;
}						t_param;

typedef struct			s_select
{
	char				*cmd;
	int					s;
	int					os;
}						t_select;

void					print_key(char key, int flag);
int						printnbr(int i);
void					ft_printf(char key, char *str, int size_mess);

char					*ft_scanf(int fd, int size_mess);
t_scanf					*new_scanf(int fd, int size_mess);
char					*go_up(char *cmd, int size_mess);
char					*go_down(char *cmd, int size_mess);
void					go_left(int flag, int size_mess);
void					go_right(char *cmd, int flag);
void					go_to_start_str(int size_mess);
void					go_to_end_str(char *cmd);
void					go_to_next_word(char *cmd);
void					go_to_prev_word(char *cmd, int size_mess);
char					*del_previous_word(char *cmd, int size_mess);
char					*line_editing(char *cmd, long key, int size_mess);
char					*full_deletion(char *cmd, int size_mess);
char					*del_after_cursor(char *cmd);
char					*del_sumb(char *s1, int size_mess);
char					*print_sumb(char buff, char *s1, int size_mess);

void					ft_lstadd(t_list **alst, t_list *new_lst);
t_list					*ft_lstnew(char *name, char *path);
t_history				*ft_lstnew_el(char *cmd, int fd);
void					free_lst(t_token *lst);
void					ft_lstdel_all(t_list **lst);
void					ft_tokdel_all(t_token **lst);

char					*get_env(char *env, char **env_g);

struct termios			get_default_settings(void);
void					res_default_settings(struct termios savetty);
void					ft_freestrarr(char **arr);

void					add_comand_to_story(char *cmd);
char					*history_up(char *cmd, int size_mess);
char					*history_down(char *cmd, int size_mess);

void					run_exit(void);

void					autocomplete(long key, int size_mess, int i, \
	t_token *t);
void					if_dquote_cmd(void);

int						token_main(char *str, t_token **lst_token);
t_token					*creat_token(char *str, int s, char *tmp);
void					add_token_lst(t_token **lst_token, t_token *new);
int						get_token_size(char *str);
int						validity_test(t_token **lst);
void					clear_token_lst(t_token **tok);

void					get_sigint(int sig);
void					init_shell(void);
void					init_signal(void);

void					ft_print_message(void);

int						run_tree(t_tree *root, int ret);

int						set_type(char *content);

t_tree					*new_tree(t_token *token);
int						ft_is_separ(int type);
int						ft_is_dir(int type);
int						ft_isredir(int type);

t_token					*search_toke(t_token *lst);
char					**concate_cmd(t_token *lst);
t_token					*search_toke_prev(t_token *lst);
t_tree					*recurs_creat_tree(t_token *lst);

int						exeec_redir(t_tree *root);

void					print_error_term(void);
void					print_error_data(int i);
void					print_error_quote(void);
int						ft_err_message(char *s);
void					print_error(char *error);
void					error_arg(char arg);
int						error_unset(char *str);
void					print_error_name_t(void);

char					*set_cmd(char *str);

int						run_sh_cmd(t_token *token);
void					exit_signal(void);
void					ft_exec(char **av, char **env);

int						ft_is_error(t_token *tmp, t_token *prev);
t_token					*search_token(t_token *token);
int						run_token_cmd(t_token *tok);

t_tree					*add_tree(t_token *lst);
t_tree					*creat_right(t_token *lst);
t_tree					*creat_left(t_token *lst);
char					**copy_fd(t_token *tmp);

int						command_check(char **cmd);
int						run_env();
char					*run_get_env(char *env, char **env_g, int flag);
int						cheak_atr(char **cmd_attr, t_param *lst_pr);
int						exeec_cmd(t_tree *root, char **p);
int						env_exec(char **cmd, char **env);
int						run_cd(char **cmd);
int						run_set(char *cmd_attr0, char *cmd_attr1);
int						run_setenv(char **atribut);
int						run_unsetenv(char **str);
char					**realloc_envv(int size);
int						run_echo(char **s, char *t, int flag, int i);

char					*ft_get_env_var(char *str);

int						check_token3(t_token **t, char *str, int s, int i);
void					check_token4(t_token **lst);
void					set_all_token(t_token *hed);
void					check_key(long key, int size_mess, int flag);
int						pr_autoc(t_token *t, char *lstr, char *word, \
	int size_mess);
void					get_fd(t_list **lst, char *str);
void					get_bin(t_list **lst, char *str, int i, char **fd);

void					select_start(long key, int size_mess, t_select *sel);
void					select_char(long key, int size_mess, t_select *sel);
void					check_select_key(long key, int size_mess, t_select *s, \
	int startpos);
void					paste_select(int size_mess, char *lcmd, char *rcmd, \
	char *tmp);

int						man_echo(void);
int						man_cd(void);
int						man_setenv(void);
int						man_env(void);
int						man_unsetenv(void);
int						run_man(char *str);
int						print_help_file(int size, char *str, int flag, int ret);
void					run_help(void);
char					*creat_file(char **cmd, int i, int fd, int coll);
int						get_size(char *str, int flag, int i);
int						get_redirected(char *s, int i);
char					**set_cmds(char **cmd, char *tmp, char *buf);
void					signal_dfl(void);
void					divide_the_string(t_token *t, char *tmp,\
	char **cmd, int *i);
char					*create_content(char *tmp, int i, int j);
#endif
