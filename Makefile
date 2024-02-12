NAME = libftprintf.a
LIBFT_DIR = libft/
DEBUG_NAME = debug.out

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

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
debug_set debug \
clean fclean re

$(OBJ_DIR)%.o: $(subst debug/,,$(SRC_DIR)%.c)
	@mkdir -p $(dir $@)
	@echo Building $< with $(CFLAGS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)libft.a $(NAME)
	@ar rcs $(NAME) $^
	@echo Mandatory part done

all: $(NAME)

bonus: $(NAME) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@echo Bonus part done

$(DEBUG_NAME): $(OBJS_DEBUG)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(libft.a) $(NAME)
	@echo Compiling debug executable
	@$(CC) $(CFLAGS) $(OBJS) $(NAME) -o $@
	@echo Debug done

#Set debug flags, debug object directory, and debug objects
debug_set:
	$(eval CFLAGS = $(DEBUG_FLAGS))
	$(eval OBJ_DIR = $(OBJ_DEBUG_DIR))
	$(eval OBJS = $(OBJS_DEBUG))

debug: debug_set $(DEBUG_NAME)

#Clean up resources generated during build
clean:
	@make -C $(LIBFT_DIR) clean
	@echo Removing $(OBJ_DIR)
	@rm -rf $(OBJ_DIR)

#Clean up build artifacts
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo Removing $(NAME) and $(DEBUG_NAME)
	@rm -rf $(NAME) $(DEBUG_NAME)

re: fclean all