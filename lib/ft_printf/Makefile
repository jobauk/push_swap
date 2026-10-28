CC := cc

NAME := libftprintf.a
NAME_STEM := $(basename $(NAME))

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEBUG_OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/debug/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
DEBUG_DEPS := $(DEBUG_OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := -Wall -Wextra -Werror -pedantic -MMD -MP $(INC_FLAGS)
LD_FLAGS := -fsanitize=address,undefined
DEBUG_CFLAGS := $(CFLAGS) \
	-g3 -O0 -fno-omit-frame-pointer \
	-fstrict-aliasing -Wcast-align \
	-Wconversion -Wsign-conversion \
	-Wshadow -Wundef \
	$(LD_FLAGS)

BIN := $(BUILD_DIR)/$(NAME_STEM)
DEBUG_BIN := $(BUILD_DIR)/debug/$(NAME_STEM)

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	DEBUGGER := lldb
else
	DEBUGGER := gdb
endif

.PHONY = all run debug norm bonus clean fclean re

all: $(NAME)

# Utilities
run: $(BIN)
	@./$<

debug: $(DEBUG_BIN)
	@$(DEBUGGER) $<

build: $(DEBUG_BIN)

$(BIN): $(OBJS)
	@$(CC) $^ -o $@

$(DEBUG_BIN): $(DEBUG_OBJS)
	@$(CC) $(LD_FLAGS) $^ -o $@

# Required
bonus: all

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(BUILD_DIR)/debug/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	@$(CC) $(DEBUG_CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo $(DEPS)
	rm -f $(OBJS) $(DEPS)

debug-clean:
	rm -f $(DEBUG_OBJS) $(DEBUG_DEPS)

fclean: clean
	rm -f $(NAME)

debug-fclean: debug-clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

-include $(DEBUG_DEPS)
