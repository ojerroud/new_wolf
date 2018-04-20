# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/26 16:57:41 by ojerroud          #+#    #+#              #
#    Updated: 2017/11/08 14:16:20 by ojerroud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = wolf3d
vpath %.c src
vpath_h =-I include -I minilibx_macos -I libft/includes \
-I $(HOME)/.brew/Cellar/sdl2/2.0.7/include/
LIB =-L libft/ -lft -L minilibx_macos -lmlx -L \
$(HOME)/.brew/Cellar/sdl2/2.0.7/lib -lSDL2
MINIFLAGS =-framework OpenGL -framework AppKit
SCRIPTDIR = scripts/
OBJDIR := obj/
OBJS := $(addprefix $(OBJDIR)/,main.o read.o error.o test.o init.o key.o move.o ray.o draw.o)

$(OBJDIR)/%.o : %.c
	$(CC) $(vpath_h) -Wall -Wextra -Werror -c \
	$(OUTPUT_OPTION) $< $(CPPFLAGS) $(CFLAGS) 

all : $(OBJS)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) $(LIB) -o $(NAME) $(OBJS) $(MINIFLAGS) #-g -fsanitize=address

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

libsdl2:
	@sh $(SCRIPTDIR)install_brew.sh

clean :
	@make clean -C libft
	@/bin/rm -rf $(OBJDIR)
	@echo "clean wolf3d"

fclean : clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME) $(LIBDIR)

re: fclean all