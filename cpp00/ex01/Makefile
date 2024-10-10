FILES       = PhoneBook Contact Main Utils

NAME        = phonebook

CC          = c++
CCFLAGS     = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

OBJ_DIR     = .obj/

OBJS        = $(addprefix $(OBJ_DIR), $(notdir $(FILES:=.o)))

vpath %.cpp ./

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CCFLAGS) -o $(NAME)
	@echo "$(DARKBLUE)-== $(NAME) created! ツ ==-$(DEFAULT)"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CCFLAGS) -c -o $@ $< 

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)-== all object files deleted! ==-$(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)-== all files deleted! ==-$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re

# ANSI COLORS
DEFAULT = \033[0m
RED     = \033[1;31m
YELLOW  = \033[1;33m
GREEN   = \033[1;32m
BLUE    = \033[1;36m
DARKBLUE = \033[1;34m
ORANGE  = \033[38;5;208m
