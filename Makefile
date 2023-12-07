#***********************************************************************#
#																		#
#		Header: libline.a												#
#		Description: Library for reading lines from file's descriptor.	#
#													  					#
#***********************************************************************#
NAME = libline.a
CFLAGS = -Wall -Wextra -Werror -c
CC = gcc
CFILES = get_next_line_utils.c \
		get_next_line.c
HFILE = get_next_line.h
OFILES = $(CFILES:.c=.o)
LIB_COMPILATION = ar r

all: obj $(NAME)

obj: $(CFILES)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OFILES): $(HFILE)

$(NAME): $(OFILES)
	$(LIB_COMPILATION) $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
