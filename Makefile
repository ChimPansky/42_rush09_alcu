NAME = alcu

all: $(NAME)

SOURCE_DIR = src
BUILD_DIR = build

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g #-Wpedantic
# CFLAGS += -g -Og -fsanitize=address,undefined,leak

include colors.mk
LIBFT = libs/libft/libft.a
$(LIBFT):
	@make -C libs/libft all clean
IFLAGS += -Ilibs/libft
LFLAGS += -Llibs/libft -lft

.PHONY: lft
lft:
	@make -C libs/libft all clean

FILENAMES += \
	alcu.c \
	board.c \
	moves.c

FILENAMES += \
	get_next_line/get_next_line.c \
	get_next_line/ft_free_and_null.c \
	get_next_line/ft_memmove.c

FILENAMES += \
	utils/ft_isspace.c \
	utils/ft_putstr_fd.c \
	utils/ft_strlen.c

SRC = $(addprefix $(SOURCE_DIR)/,$(FILENAMES))
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(BUILD_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -MMD -c $< -o $@

-include $(DEP)

clean:
	rm -fr $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# valgrind:
# 	valgrind --leak-check=full --show-leak-kinds=all --track-fds=all ./$(NAME) resources/scene_descriptions/01_test.cub

.PHONY: all clean fclean re
