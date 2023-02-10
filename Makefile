DIRSRC = ./srcs/mandatory/

DIRCINC = ./includes/

DIRLIB = ./libft/

DIRBONUS = ./srcs/bonus/

SRC =	ft_push_swap \
		parsing \
		instructions_1 \
		instructions_2 \
		instructions_3 \
		sort_small \
		sort_big \
		find_index \
		exec_actions \

SRC_B = checker \
		parsing \
		instructions_1 \
		instructions_2 \
		instructions_3 \
		check_instructions \

SRCS = $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))
SRCS_B = $(addprefix ${DIRBONUS}, $(addsuffix .c, ${SRC_B}))

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${SRCS_B:.c=.o}

NAME = push_swap
BONUS_NAME = checker
LFT = libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L./libft -lft
	@echo "✅ push_swap created"

${BONUS_NAME}: ${BONUS_OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} -L./libft -lft
	@echo "✅ checker created"

all: ${NAME}

clean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@cd ${DIRLIB} ${DIRBONUS} && ${MAKE} clean
	@echo "🧽 Directory is clean"

fclean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${NAME} ${BONUS_NAME}
	@cd ${DIRLIB} ${DIRBONUS} && ${MAKE} fclean
	@echo "🧹 Directory is fclean"

re : fclean all

bonus: ${BONUS_NAME}

.PHONY : all clean fclean re bonus
