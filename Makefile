NAME = libftprintf.a
LIBFT_DIR = libft/

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/
OBJ_DIR = objs/

SRC_NAMES =	ft_printf.c						\
			utils/u_len_base.c				\
			utils/u_put_base.c				\
			utils/wrap_err.c				\
			conversion/handle_sequence.c	\
			conversion/identify_sequence.c	\
			conversion/handlers/char.c		\
			conversion/handlers/int.c		\
			conversion/handlers/percent.c	\
			conversion/handlers/pointer.c	\
			conversion/handlers/string.c	\
			conversion/handlers/uhex.c		\
			conversion/handlers/uint.c

HEADER_NAMES =	utils/utils.h					\
				utils/internal_types.h			\
				conversion/sequence.h			\
				conversion/handlers/handlers.h

SRC_BONUS_NAMES =	utils/repeat_str_n.c						\
					utils/u_len_base.c							\
					utils/u_put_base.c							\
					conversion/handle_sequence.c				\
					conversion/identify_sequence.c				\
					conversion/parse_subspec.c					\
					conversion/handlers/char.c					\
					conversion/handlers/int.c					\
					conversion/handlers/percent.c				\
					conversion/handlers/pointer.c				\
					conversion/handlers/set_fd.c				\
					conversion/handlers/store.c					\
					conversion/handlers/string.c				\
					conversion/handlers/uhex.c					\
					conversion/handlers/uint.c					\
					conversion/handlers/uoct.c					\
					conversion/handlers/utils/unsigned_arg.c	\
					conversion/handlers/utils/u_print_base.c

HEADER_BONUS_NAMES =	utils/utils.h								\
						utils/internal_types.h						\
						conversion/sequence.h						\
						conversion/subspec.h						\
						conversion/handlers/handlers.h				\
						conversion/handlers/utils/handler_utils.h

################################################################################

SRCS = $(addprefix $(SRC_DIR)mandatory/, $(SRC_NAMES))
SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR)bonus/, $(SRC_BONUS_NAMES))
OBJS = $(SRC_NAMES:%.c=$(OBJ_DIR)mandatory/%.o)
OBJS_BONUS = $(SRC_BONUS_NAMES:%.c=$(OBJ_DIR)bonus/%.o)

HEADERS = $(addprefix $(SRC_DIR), $(HEADER_NAMES))
HEADERS_BONUS = $(addprefix $(SRC_BONUS_DIR), $(HEADER_BONUS_NAMES))

.PHONY: all bonus \
clean fclean re

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo $a
	@mkdir -p $(dir $@)
	@echo Building $< with $(CFLAGS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)libft.a $(NAME)
	@ar rcs $(NAME) $^
	@echo Mandatory part done

all: $(NAME)

.bonus: $(NAME) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@echo Bonus part done

bonus: .bonus

clean:
	@make -C $(LIBFT_DIR) clean
	@echo Removing $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo Removing $(NAME)
	@rm -rf $(NAME)

re: fclean all