SRCS = srcs/main.cpp tests/test.vector.cpp tests/test.map.cpp tests/test.pair.cpp tests/test.stack.cpp
ODIR = .obj
OBJS = $(addprefix $(ODIR)/, $(SRCS:.cpp=.o))
DEP = $(OBJS:.o=.d)
CC = c++
FLAGS = -Wall -Wextra -g3 -fsanitize=address
CFLAGS = $(FLAGS) -MMD
RM = rm -rf
NAME = ft_containers

all: init $(NAME)

init:
	@mkdir -p .obj/tests .obj/srcs

-include $(DEP)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(ODIR)/%.o: %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(DEP)
	$(RM) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
