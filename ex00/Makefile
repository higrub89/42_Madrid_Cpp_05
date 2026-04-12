# --- IDENTIFICACIÓN ---
NAME        = bureaucrat
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -O3
RM          = rm -rf
# --- COLORES ---
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
NC          = \033[0m
# --- DIRECTORIOS ---
OBJ_DIR     = obj
# --- FUENTES ---
SRCS        =	Bureaucrat.cpp \
			 	main.cpp
OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
# --- REGLAS ---
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)--- CREATION ./$(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅  SUCCESSFUL COMPILATION  ✅$(NC)"

$(OBJ_DIR)/%.o: %.cpp Bureaucrat.hpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW) Compiling:$(NC) $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)--- DELETION OF OBJECT FILES ---$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)--- DELETED FILE ./$(NAME) ---$(NC)"

re: fclean all
.PHONY: all clean fclean re
