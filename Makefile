NAME		= 21sh
SRCS		= src/scanf/historu_func.c \
			  src/scanf/key_func.c \
			  src/scanf/scanf_src.c \
			  src/scanf/up_do_le_nd.c \
			  src/scanf/scanf.c \
			  src/scanf/myquote.c\
			  src/scanf/line_editing.c \
			  \
			  src/set_token/src_token.c\
			  src/set_token/token_size.c\
			  src/set_token/token_main.c \
			  src/set_token/check_token.c \
			  src/set_token/check_token_src.c \
			  src/set_token/validity_test.c \
			  src/set_token/validity_test_src.c \
			  src/set_token/size_src.c \
			  src/set_token/create_content.c \
			  \
			  src/signal/main_signal.c\
			  src/signal/src_signal.c \
			  \
			  src/main/ft_printmessage.c\
			  src/main/set_mode.c \
			  src/main/main.c \
			  src/main/lst_func.c \
			  src/main/help.c \
			  src/main/help_src.c \
			  \
			  src/error/error_1.c \
			  src/error/error_2.c \
			  \
			  src/tree/new_tree.c \
			  src/tree/search_token.c \
			  src/tree/concate_cmd.c \
			  src/tree/run_tree.c \
			  src/tree/exeec_redir.c \
			  \
			  src/exec/run_token_cmd.c \
			  src/exec/run_env.c \
			  src/exec/run_cd.c \
			  src/exec/run_unsetenv.c \
			  src/exec/run_echo.c \
			  src/exec/env_src_fun.c  \
			  src/exec/run_setenv.c \
			  src/exec/my_exec_cmd.c \
			  src/exec/launcher.c \
			  src/exec/launcher_src.c \
			  \
			  src/autocomplete/autocoplete.c \
			  src/autocomplete/autocoplete_src1.c \
			  src/autocomplete/autocoplete_src2.c \
			  \
			  src/select/select_main.c \
			  src/select/select_src.c \
			  \
			  src/man/man_src_1.c \
			  src/man/man_src_2.c \

OBJS		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror -g -O3
HEADER		= includes/sh.h
LIB			= libft/libft.a

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[01;38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m
RES			= \033[m


all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(LIB) -ltermcap
		@echo  "\b$(YELLOW) : OK$(RES)"

%.o: %.c $(HEADER)
	@gcc -c $(FLAGS) -o $@ -c $<
	@echo  "$(YELLOW)█$(RES)\c)"

$(LIB):
	@echo  "$(GREEN)Compiling: $(WHITE)libft$(RES)$(YELLOW) : $(RES)\c)"
	@make -C libft
	@echo  "$(GREEN)Compiling: $(WHITE)21sh $(RES)$(YELLOW) : $(RES)\c)"

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)
	@make -C libft fclean

re: fclean $(NAME)
