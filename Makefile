INC = includes
SRC = src/*.c
LIBX = minilibx
LIBALL = libft
INCS = -I$(LIBX) -I$(INC) -I$(LIBALL)
LIBS = minilibx/libmlx.a -L$(LIBALL) -L$(LIBX) -lmlx
FLAGS = $(INCS) $(LIBS) -framework OpenGL -framework Appkit
NAME = so_long.out

LIBXLINUX = minilibx-linux
LIBSLINUX = minilibx-linux/libmlx.a -L$(LIBALL) -L$(LIBXLINUX)
INCSLINUX = -I$(LIBXLINUX) -I$(INC) -I$(LIBALL)
FLAGSLINUX = $(INCSLINUX) $(LIBSLINUX) -lXext -lX11 -lm -lz

all:
	@clear
	@echo -n Compiling Libs...
	@make -s -C $(LIBX)
	@echo Done
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGS) -o $(NAME)
	@echo Done

test:
	@clear
	@echo -n Compiling so_long...
	@gcc $(SRC) $(FLAGSLINUX) -o $(NAME)
	@echo Make Done
	@clear
	@./so_long.out map/1.ber

l:
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
	@SLEEP 10 \
	git push

clean:
	@rm -rf $(NAME)
	@make -s fclean -C $(LIBALL)
	@make -s clean -C $(LIBX)
	@make -s clean -C $(LIBXLINUX)

fclean: clean

re: fclean all

bonus: all

norm:
	@clear
	@norminette $(INC) $(SRC) $(LIBALL)
