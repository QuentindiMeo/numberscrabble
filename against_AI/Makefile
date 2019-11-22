##
## PERSONAL PROJECT, 2019
## numberscrabble
## File description:
## Makefile
##

SRC	=	src/error.c			\
		src/ai/ai_rowcol.c		\
		src/ai/ai2.c			\
		src/ai/ai.c			\
		src/overpick.c			\
		src/game_loop.c			\
		src/detectors2.c		\
		src/detectors.c			\
		src/malloc_free_setup.c		\
		src/main_numberscrabble.c	\

OBJ	=	$(SRC:.c=.o)

HEADER_PATH     =       include/

CC	=	@gcc

LIB     =       include/libmy.a

CFLAGS	=	-I $(HEADER_PATH) -Wall -Werror -Wextra --pedantic

NAME	=	numberscrabble

.PHONY: clean fclean re numberscrabble

all: $(NAME)

$(NAME): $(OBJ)
	@echo Compiling \'$(NAME)\'
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo \'$(NAME)\' compiled successfully

clean:
	@rm -rf $(OBJ)
	@echo Cleaned .o for \'$(NAME)\'

fclean:	clean
	@rm -rf $(NAME)
	@echo Cleaned \'$(NAME)\'

re: fclean all
