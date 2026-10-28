*This project has been created as part of the 42 curriculum by jaukes*

## Description
This project contains a lot of utility fuctions from libc to handle strings, memory, and numbers. It also includes some additional functionality for linked lists. Every implementation of a libc function follows the behaviour described in it's man page.

## Instructions
Compile the library:
```sh
make
```
Delete all generated .o files:
```sh
make clean
```
Delete all generated files:
```sh
make fclean
```
Re-compile:
```sh
make re
```
Run all tests:
```sh
make test
```
Filter tests:
```sh
# This will run all tests in the ft_split suite
make test FILTER='ft_split/*'
```
Run a program (for quick testing):
```sh
make run
```
Debug a program (gdb/lldb):
```sh
make debug
```
Run norminette on all srcs:
```sh
make norm
```

## Resources
Mainly the man pages, peers, and Stack Overflow. No AI was used in this project.

### String utilities
ft_isalnum.c
ft_isalpha.c
ft_isascii.c
ft_isdigit.c
ft_isprint.c
ft_split.c
ft_strchr.c
ft_strdup.c
ft_striteri.c
ft_strjoin.c
ft_strlcat.c
ft_strlcpy.c
ft_strlen.c
ft_strmapi.c
ft_strncmp.c
ft_strnstr.c
ft_strrchr.c
ft_strtrim.c
ft_substr.c
ft_tolower.c
ft_toupper.c

### Memory functions
ft_bzero.c
ft_calloc.c
ft_memchr.c
ft_memcmp.c
ft_memcpy.c
ft_memmove.c
ft_memset.c

### Integer conversions
ft_atoi.c
ft_itoa.c

### Linked list
ft_lstadd_back.c
ft_lstadd_front.c
ft_lstclear.c
ft_lstdelone.c
ft_lstiter.c
ft_lstlast.c
ft_lstmap.c
ft_lstnew.c
ft_lstsize.c

### File writing functions
ft_putchar_fd.c
ft_putendl_fd.c
ft_putnbr_fd.c
ft_putstr_fd.c
