#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sconso <sconso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 13:47:30 by sconso            #+#    #+#              #
#    Updated: 2015/01/14 19:53:16 by Myrkskog         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= whatever
COMPILER	= g++
CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -pedantic -ansi -g -ggdb

FILES		= whatever.cpp

INCLUDE		= ./includes/
SRCDIR		= src
OBJDIR		= obj

SRC			= $(addprefix $(SRCDIR)/, $(FILES))
OBJ			= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@$(COMPILER) $(CFLAGS) -o $@ $(OBJ) -I $(INCLUDE)
	@echo "\033[4;32m$@\033[0m created !"


$(OBJDIR):
	@/bin/mkdir $(OBJDIR);			\
	for DIR in $(SRCDIR);			\
	do								\
		/bin/mkdir $(OBJDIR)/$$DIR;	\
	done							\

$(addprefix $(OBJDIR)/, %.o) : %.cpp
	@$(COMPILER) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<
	@/bin/echo -n "Creating objects in $(addprefix $(OBJDIR)/, $(SRCDIR)) : "
	@echo "\033[1;33m$(subst $(SRCDIR)/, , $(<:.cpp=.o))\033[0m"

run: re
	@/usr/bin/clear
	@./$(NAME)

clean:
	@/bin/rm -rf $(OBJDIR) a.out.dSYM
	@/bin/rm -f a.out
	@echo "\033[1;30m$(OBJDIR)\033[0m removed !"


fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[1;30m$(NAME)\033[0m removed !"

re: fclean all

debug : CFLAGS += $(DFLAGS)
debug : re

.SILENT:
.PHONY: all clean fclean re