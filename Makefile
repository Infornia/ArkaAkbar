##
# http://www.glfw.org/docs/latest/build.html
##


## PROJET

NAME = arkanoid

SM_GLFW = glfw
SM_SOIL = soil

LIBFT = libft/libft.a
LIBGLFW = $(SM_GLFW)/src/libglfw.a
LIBSOIL = $(SM_SOIL)/libSOIL.a

## COMPILATEUR

OS = $(shell uname -s)

CC = clang

FLAGS = -Wall -Werror -Wextra -Wno-deprecated-declarations

## FICHIERS

SRC = 	src/main_cdivry.c \
	src/callback.c \
	src/draw.c \
	src/draw_fuck_norm.c \
	src/error.c \
	src/game.c \
	src/menu.c \
	src/key.c \
	src/parsing.c \
	src/text.c \
	src/highscore.c \
	src/chrono.c \
	src/tools.c \
	src/vector.c

INC =  -I ./inc/
INC += -I ./libft/inc/
INC += -I ./$(SM_GLFW)/include
INC += -I ./$(SM_SOIL)/src/

OBJ = $(SRC:.c=.o)

LIB =  -L ./libft/ -lft
LIB += -L ./$(SM_GLFW)/src/ -lglfw3
LIB += -L ./$(SM_SOIL)/ -lSOIL
#LIB += -L/usr/X11

# LIB MAC OS
ifeq ($(OS),Darwin)
LIB += -framework Cocoa
LIB += -framework OpenGL
LIB += -framework IOKit
LIB += -framework CoreVideo
LIB += -framework GLUT
LIB += -framework Carbon
endif

# LIB LINUX
ifeq ($(OS),Linux)
LIB += `pkg-config --cflags glfw3`
LIB += `pkg-config --libs glfw3` -L/usr/lib64/xorg

endif



## REGLES

all: $(LIBSOIL) $(LIBGLFW) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(INC) $(LIB) -o $(NAME) $(SRC)

clean:
	make -C libft/ clean
#	make -C glfw/ clean
	rm -fr $(OBJ)
	rm -fr src/CMakeFiles
	rm -fr src/Makefile
	rm -fr src/cmake_install.cmake
	rm -fr src/cmake_install.cmake
	rm -fr src/glfw3.pc
	rm -fr src/glfw3Config.cmake
	rm -fr src/glfw3ConfigVersion.cmake

fclean: libglfw_rm libsoil_rm clean
	make -C libft/ fclean
	rm -fr src/glfw_config.h
	rm -fr src/libglfw3.a
	rm -fr $(NAME) 
	rm -fr soil soil.zip
	rm -fr tests_glfw 
#	make -C glfw/ fclean

%.o:%.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@



$(SM_GLFW):
#	rm -fr $(SM_GLFW)
	git submodule add https://github.com/glfw/glfw.git $(SM_GLFW)
#	( cd $(SM_GLFW) && cmake . && make && make install && cd .. )
	( cd $(SM_GLFW) && cmake . && make && cd .. )

$(SM_SOIL):
#	rm -fr $(SM_SOIL)
	git submodule add https://github.com/kbranigan/Simple-OpenGL-Image-Library.git $(SM_SOIL)
#	( cd $(SM_SOIL) && cmake . && make && make install && cd .. )
	( cd $(SM_SOIL) && cmake . && make && cd .. )

$(LIBFT):
	make -C libft/

re: fclean all

$(LIBGLFW): $(SM_GLFW)
	git submodule init
	git submodule update

$(LIBSOIL): $(SM_SOIL)
	git submodule init
	git submodule update

libglfw_rm:
	mkdir -p $(SM_GLFW)
	rm -fr $(SM_GLFW)
	git rm -fr --cached $(SM_GLFW)
	rm -rf .git/modules/$(SM_GLFW)
	rm -fr $(SM_GLFW)
	rm -fr .gitmodules

libsoil_rm:
	mkdir -p $(SM_SOIL)
	rm -fr $(SM_SOIL)
	git rm -fr --cached $(SM_SOIL)
	rm -rf .git/modules/$(SM_SOIL)
	rm -fr $(SM_SOIL)
	rm -fr .gitmodules

pouet:
	cmake $(SM_GLFW)/

.PHONY: all clean fclean re

test: all
	mv -f src/test.wtf src/test.c
	$(CC) $(INC) $(LIB) -o tests_glfw src/test.c
	mv -f src/test.c src/test.wtf
	./tests_glfw

mwilk: all
	mv -f src/mwilk_work.c src/test.c
	$(CC) $(INC) $(LIB) -o tests_glfw src/test.c
	mv -f src/test.c src/mwilk_work.c
	./tests_glfw
