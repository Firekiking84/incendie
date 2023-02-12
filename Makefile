NAME=		incendie

SRC=		src/main.c				\
		src/incendie.c				\
		src/mk_color.c				\
		src/fill_palette.c			\
		src/set_pixel.c				\
		src/get_ratio.c				\
		src/get_value.c				\
		src/sens_finder.c			\
		src/norme.c				\
		src/set_line.c				\
		src/diagonale_line.c			\
		src/val_abs_f.c				\
		src/def_lower_line.c			\
		src/init_pixelarray.c			\
		src/average_color.c			\
		src/move_cursor.c			\
		src/calcul_and_apply.c			\
		src/average_composant.c			\
		src/reset_position.c			\
		src/def_fire.c				\
		src/def_fire_body.c			\
		src/def_shape.c				\
		src/draw_shapes.c			\
		src/init_layer_value.c			\
		src/mon_incendie.c			\
		src/diagonale_management.c		\
		src/def_smoke.c				\
		src/plasma.c				\
		src/fill_palette_plasma.c		\


OBJS=		$(SRC:.c=.o)

INCLUDE=	-I./include

CC= 		gcc

FLAGS=		-W -Wextra -g

LDFLAGS=	-llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -ldl \
		-lpthread -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_videoio    \
		-lopencv_core -lavcall


all:$(NAME)

$(NAME):$(OBJS)
		$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

.c.o:
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

ar:$(OBJS)
		ar rc $(NAME).a $(OBJS)

clean:
		rm *~ include/*~ src/*~ src/*.o

fclean:
		rm $(NAME)
t:
		make re
		make
		./$(NAME)
g:
		gdb --arg ./$(NAME)

re:
		make fclean
		make clean
