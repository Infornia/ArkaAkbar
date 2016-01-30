##
# http://www.glfw.org/docs/latest/build.html
##


## PROJET

NAME = arkanoid

LIBFT = libft/libft.a

SUBMODULE = glfw

## COMPILATEUR

OS = $(shell uname -s)

CC = clang

FLAGS = -Wall -Werror -Wextra

## FICHIERS

SRC = src/main.c

INC = -I ./inc/ -I ./libft/inc/ -I ./glfw/include

OBJ = $(SRC:.c=.o)

LIB = -L ./libft/ -lft -L ./glfw/src/ -lglfw3
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

all: $(SUBMODULE) $(LIBFT) $(NAME)

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

fclean: submodule_rm clean
	make -C libft/ fclean
	rm -fr src/glfw_config.h
	rm -fr src/libglfw3.a
	rm -fr $(NAME) 
	rm -fr tests_glfw 
#	make -C glfw/ fclean

%.o:%.c
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(SUBMODULE):
#	rm -fr $(SUBMODULE)
	git submodule add https://github.com/glfw/glfw.git $(SUBMODULE)
#	( cd $(SUBMODULE) && cmake . && make && make install && cd .. )
	( cd $(SUBMODULE) && cmake . && make && cd .. )

$(LIBFT):
	make -C libft/

re: fclean all

submodule_rm:
	mkdir -p $(SUBMODULE)
	#mv $(SUBMODULE) $(SUBMODULE)_tmp
	#git submodule deinit $(SUBMODULE)    
	rm -fr $(SUBMODULE)
	git rm -fr --cached $(SUBMODULE)
	rm -rf .git/modules/$(SUBMODULE)
	rm -fr $(SUBMODULE)
	rm -fr .gitmodules
	#mv $(SUBMODULE)_tmp $(SUBMODULE)

pouet:
	cmake $(SUBMODULE)/

.PHONY: all clean fclean re

test: all
	mv -f src/test.wtf src/test.c
	$(CC) $(INC) $(LIB) -o tests_glfw src/test.c
	mv -f src/test.c src/test.wtf
	./tests_glfw

te: all
	mv -f src/lol.c src/test.c
	$(CC) $(INC) $(LIB) -o tests_glfw src/test.c
	mv -f src/test.c src/lol.c
	./tests_glfw
