#Name of archive
NAME = libftprintf.a
LIBFT_NAME = libft.a
LIBFT_DIR = libft/
#Name of debugging executable
DEBUG_NAME = debug.out

#Compiler
CC = cc
#Compiler flags
CFLAGS = -Wall -Wextra -Werror
#Compiler flags to use for debugging
DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

#Directory where source files are located
SRC_DIR = srcs/
#Directory for object subdirectories
OBJ_BASE_DIR = objs/
#Directory for objects from standard builds
OBJ_DIR = $(OBJ_BASE_DIR)standard/
#Directory for objects from debug builds
DEBUG_OBJ_DIR = $(OBJ_BASE_DIR)debug/

#List of source files
SRC_NAMES =	ft_printf									\
			utils/ull_len_base							\
			utils/putbase								\
			utils/repeat_str_n							\
			utils/wrap_err								\
			conversion/handle_sequence					\
			conversion/identify_sequence				\
			conversion/parse_subspec					\
			conversion/handlers/char					\
			conversion/handlers/int						\
			conversion/handlers/percent					\
			conversion/handlers/pointer					\
			conversion/handlers/set_fd					\
			conversion/handlers/store					\
			conversion/handlers/string					\
			conversion/handlers/uhex					\
			conversion/handlers/uint					\
			conversion/handlers/uoct					\
			conversion/handlers/utils/unsigned_arg		\
			conversion/handlers/utils/print_uint_base	\

#List of headers
HEADER_NAMES =	printf.h									\
				utils/utils.h								\
				utils/def_sub.h								\
				utils/internal_types.h						\
				conversion/sequence.h						\
				conversion/subspec.h						\
				conversion/handlers/handlers.h				\
				conversion/handlers/utils/handler_utils.h	\

#### END OF CONFIGURABLE SECTION ####

#Prepend SRC_DIR and append .c to all source files
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_NAMES)))
#Prepend OBJ_DIR and append .o to all would-be object files
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))
#Prepend OBJ_DIR and append .o to all would-be debug object files
DEBUG_OBJS = $(addprefix $(DEBUG_OBJ_DIR), $(addsuffix .o, $(SRC_NAMES)))

HEADERS = $(addprefix $(SRC_DIR), $(HEADER_NAMES))

#Set non-filename targets so make doesn't skip due
#to files unintentionally having the same name as a rule
.PHONY: all \
debug_set debug \
clean fclean re 

# $@ name of the rule
# $^ prerequisite of the rule
# $< first prerequisite
# Build any object files that need recompilation
$(OBJ_DIR)%.o \
$(DEBUG_OBJ_DIR)%.o: $(SRC_DIR)%.c
#	Take the directory path of the file that needs to be built, remove
#	the SRC_DIR portion and replace it with OBJ_DIR instead, and
#	create that directory.

#	We use $< so that we don't get the HEADERS here also. They are included
#	above so modifying the headers can trigger recompilation
	@mkdir -p $(OBJ_DIR)$(subst $(SRC_DIR),,$(dir $<))
	@echo Building $< with $(CFLAGS)
	@$(CC) $(CFLAGS) -c $< -o $@

#Create archive from objects
$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT_NAME) $(NAME)
	@ar rcs $(NAME) $^
	@echo Mandatory part done

all: $(NAME)

#Compile debug executable with debug flags
$(DEBUG_NAME): $(DEBUG_OBJS)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)$(LIBFT_NAME) $(NAME)
	@echo Compiling debug executable
	@$(CC) $(CFLAGS) $(OBJS) $(NAME) -o $@
	@echo Debug done

#Set debug flags, debug object directory, and debug objects
debug_set:
	$(eval CFLAGS = $(DEBUG_FLAGS))
	$(eval OBJ_DIR = $(DEBUG_OBJ_DIR))
	$(eval OBJS = $(DEBUG_OBJS))

debug: debug_set $(DEBUG_NAME)

bonus: all

#Clean up resources generated during build
clean:
	@make -C $(LIBFT_DIR) clean
	@echo Removing $(OBJ_BASE_DIR) and .bonus
	@rm -rf $(OBJ_BASE_DIR) .bonus

#Clean up build artifacts
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@echo Removing $(NAME) and $(DEBUG_NAME)
	@rm -rf $(NAME) $(DEBUG_NAME)

re: fclean all