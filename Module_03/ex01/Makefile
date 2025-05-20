# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 11:01:31 by jmeirele          #+#    #+#              #
#    Updated: 2025/05/20 13:37:43 by jmeirele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = scavtrap

#==============================================================================#
#                                FLAGS & COMMANDS                              #
#==============================================================================#

CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -g -std=c++98
RM          = rm -fr
MKDIR       = mkdir -p

#==============================================================================#
#                                 SOURCE FILES                                 #
#==============================================================================#

BUILD_PATH  = .build

SRCS        = main.cpp \
              ClapTrap.cpp \
              ScavTrap.cpp

INCLUDES    = -I.
OBJS        = $(SRCS:%.cpp=$(BUILD_PATH)/%.o)

#==============================================================================#
#                                    RULES                                     #
#==============================================================================#

all: $(NAME)

$(BUILD_PATH)/%.o: %.cpp
	$(MKDIR) $(dir $@)
	$(CPP) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

test: all $(BUILD_PATH)
	tmux set-option remain-on-exit on
	@echo "[$(YEL)Running $(GRN)$(NAME)$(YEL) tests$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)$(NAME)$(D): $(MAG)Get Output$(D)"
	./$(NAME) > $(BUILD_PATH)/test_out.txt
	sed 's/\[[^]]*\] //' ./19920104_091532.log > $(BUILD_PATH)/reflog.txt
	sed 's/\[[^]]*\] //' $(BUILD_PATH)/test_out.txt > $(BUILD_PATH)/trim.txt
	tmux split-window -h "cat ./19920104_091532.log"
	tmux split-window -h "cat $(BUILD_PATH)/test_out.txt"
	@echo "$(CYA)$(NAME)$(D): $(MAG)Get Diff$(D)"
	diff $(BUILD_PATH)/trim.txt $(BUILD_PATH)/reflog.txt
	@echo "$(YEL)$(_SEP)$(D)"

#==============================================================================#
#                                  DEBUGGING                                   #
#==============================================================================#

GDB_FILE     = gdb.txt

gdb: all $(NAME)
	tmux split-window -h "gdb --tui --args ./$(NAME)"
	tmux resize-pane -L 5
	make get_log

get_log:
	rm -f $(GDB_FILE)
	touch $(GDB_FILE)
	@if command -v lnav; then \
		lnav $(GDB_FILE; \)
	else \
		tail -f $(GDB_FILE; \)
	fi

#==============================================================================#
#                                CLEANING RULES                                #
#==============================================================================#

clean:
	$(RM) $(BUILD_PATH) $(GDB_FILE)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
