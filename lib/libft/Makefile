# Compiler
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Compiler debug
LD_FLAGS := -fsanitize=address,undefined
DEBUG_CFLAGS := $(CFLAGS) -g3 -O0 -fno-omit-frame-pointer $(LD_FLAGS)

# Library
NAME := libft.a
NAME_STEM := $(basename $(NAME))

OUTDIR := .
DEBUG_OUTDIR := target

# Source
SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS := $(SRCS:%.c=$(OUTDIR)/%.o)

DEBUG_OBJS := $(SRCS:%.c=$(DEBUG_OUTDIR)/%.o)

TEST_SRCS := $(wildcard .tests/*.c)
TEST_OBJS := $(TEST_SRCS:.tests/%.c=$(DEBUG_OUTDIR)/tests/%.o)

# Output
TEST_BIN := $(DEBUG_OUTDIR)/test
RUN_BIN := $(DEBUG_OUTDIR)/$(NAME_STEM)

# Debugger
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	DEBUGGER := lldb
else
	DEBUGGER := gdb
endif

# Criterion
CRITERION_CFLAGS := $(shell pkg-config --cflags criterion)
CRITERION_LIBS := $(shell pkg-config --libs criterion)

# Default
all: $(OUTDIR)/$(NAME)

# Utility commands
test: $(TEST_BIN)
	@./$(TEST_BIN) $(if $(FILTER),--filter "$(FILTER)")

run: $(RUN_BIN)
	@./$(RUN_BIN)

debug: $(RUN_BIN)
	@$(DEBUGGER) $(RUN_BIN)

norm:
	@norminette $(SRCS)

$(DEBUG_OUTDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(DEBUG_OUTDIR)/tests/%.o: .tests/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(DEBUG_CFLAGS) $(CRITERION_CFLAGS) -c $< -o $@

$(TEST_BIN): $(DEBUG_OBJS) $(TEST_OBJS)
	@$(CC) $(LD_FLAGS) $^ $(CRITERION_LIBS) -o $@

$(RUN_BIN): $(DEBUG_OBJS)
	@$(CC) $(LD_FLAGS) $^ -o $@

# Required commands
$(OUTDIR)/$(NAME): $(OBJS) | $(OUTDIR)
	ar rcs $@ $(OBJS)

$(OUTDIR)/%.o: %.c | $(OUTDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR):
	mkdir -p $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUTDIR)/$(NAME)

re: fclean all
