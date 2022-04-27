INC = includes
SRC = src/*.c
LIBX = minilibx
INCS = -I$(LIBX) -I$(INC)
LIBS = minilibx/libmlx.a -L$(LIBX) -lmlx
FLAGS = $(INCS) $(LIBS) -framework OpenGL -framework Appkit
NAME = so_long.out

LIBXLINUX = minilibx-linux
LIBSLINUX = minilibx-linux/libmlx.a -L$(LIBXLINUX)
INCSLINUX = -I$(LIBXLINUX) -I$(INC)
FLAGSLINUX = $(INCSLINUX) $(LIBSLINUX) -lXext -lX11 -lm -lz

all:
	@clear
	@echo -n Compiling Libs...
	@make -s -C $(LIBX)
	@echo Done
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGS) -o $(NAME)
	@echo Done

linux:
	@clear
	@echo -n Compiling minilibx...
	@echo
	@make -s -C $(LIBXLINUX)
	@echo Done
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGSLINUX) -o $(NAME)
	@echo Done

git:
	@clear
	@git add .
	@echo "commit msg" 
	@read COMMIT; \
	git commit -m "$$COMMIT"; \
	git push;

clean:
	@rm -rf $(NAME)
	@make -s clean -C $(LIBX)
	@make -s clean -C $(LIBXLINUX)

fclean: clean

re: fclean all

bonus: all

norm:
	@clear
	@norminette $(INC) $(SRC) $(LIBALL)
