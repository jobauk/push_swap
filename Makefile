CC := cc

NAME := push_swap
NAME_STEM := $(basename $(NAME))

SRC_DIR := ./src
BUILD_DIR := ./build
OUT_DIR := ./bin
LIB_DIR := ./lib

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEBUG_OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/debug/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
DEBUG_DEPS := $(DEBUG_OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d) $(wildcard $(LIB_DIR)/*/include)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LIBS := lib/ft_printf/libftprintf.a lib/libft/libft.a

# LIB_NAMES := libft
# LIBS := $(foreach l,$(LIB_NAMES),lib/$(l)/$(l).a)

CFLAGS := -Wall -Wextra -Werror -Wpedantic -MMD -MP $(INC_FLAGS)
LD_FLAGS := -fsanitize=address,undefined
DEBUG_CFLAGS := $(CFLAGS) \
	-g3 -O0 -fno-omit-frame-pointer \
	-fstrict-aliasing -Wcast-align \
	-Wconversion -Wsign-conversion \
	-Wshadow -Wundef \
	$(LD_FLAGS)

BIN := $(OUT_DIR)/$(NAME)
DEBUG_BIN := $(OUT_DIR)/$(NAME).dbg
	
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	DEBUGGER := lldb
else
	DEBUGGER := gdb
endif

all: $(OUT_DIR)/$(NAME)

$(OUT_DIR)/$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

x:
	@echo $(INC_DIRS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(OUT_DIR)

re: fclean all

-include $(DEPS)

-include $(DEBUG_DEPS)
