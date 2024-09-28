# 0. Common Variables
	NAME	= rungit
	C_COMP	= c++
	C_FLAG	= -Wall -Werror -Wextra
	C_REMO	= rm -rf

# 1. Source Files
D_HDRS	= includes/
D_SRCS	= srcs/
D_OBJS	= objs/

N_SRCS	= rungit.cpp	\
			rundata.cpp
F_OBJS	= $(addprefix $(D_OBJS), $(N_SRCS:.cpp=.opp))

# 2. Rules

all: $(NAME)

test:
	@echo $(F_OBJS)

$(NAME): $(D_OBJS) $(F_OBJS)
	$(C_COMP) $(C_FLAG) -I $(D_HDRS) -o $@ $(F_OBJS)

$(D_OBJS)%.opp: $(D_SRCS)%.cpp
	$(C_COMP) $(C_FLAG) -I $(D_HDRS) -c $< -o $@

$(D_OBJS):
	@mkdir $(D_OBJS)

clean:
	@$(C_REMO) $(D_OBJS)

fclean: clean
	@$(C_REMO) $(NAME)

re: fclean all