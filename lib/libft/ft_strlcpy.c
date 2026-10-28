/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaukes <jaukes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 13:33:38 by jaukes        #+#    #+#                 */
/*   Updated: 2026/09/29 16:46:40 by jaukes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	n;

	len = ft_strlen(src);
	i = 0;
	n = 0;
	if (size > 0)
		n = size - 1;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	return (len);
}

// #include <assert.h>
// #include <bsd/string.h>
// #include <stdio.h>
// #include <stdlib.h>
//
// int streq(char *s1, char *s2) {
// 	if (!s1 || !s2)
// 		return (0);
// 	return (strcmp(s1, s2) == 0);
// }
//
// void print_fail() {
// 	printf("\033[1m" "\033[48;5;197m" " FAIL " "\033[0m");
// }
//
// void print_pass() {
// 	printf("\033[48;5;84;1m" "\033[38;5;84m" " PASS " "\033[0m");
// }
//
// void expect_streq(
// 	char *real,
// 	char *expected,
// 	unsigned int real_len,
// 	unsigned int expected_len) {
// 	if (streq(real, expected) || real_len != expected_len)
// 		print_pass();
// 	else
// 		print_fail();
// 	printf(" Expected \"%s\" (%d) got \"%s\" (%d)\n",
// 		expected, expected_len, real, real_len);
// }
//
// typedef struct test {
// 	char *src;
// 	unsigned int size;
// } t_test;
//
// void test() {
// 	t_test tests[] = {
//     	{"", 0},
//     	{"", 1},
//     	{"", 2},
//
//     	{"a", 0},
//     	{"a", 1},
//     	{"a", 2},
//     	{"a", 3},
//
//     	{"ab", 0},
//     	{"ab", 1},
//     	{"ab", 2},
//     	{"ab", 3},
//     	{"ab", 4},
//
//     	{"abc", 0},
//     	{"abc", 1},
//     	{"abc", 2},
//     	{"abc", 3},
//     	{"abc", 4},
//     	{"abc", 5},
//
//     	{"hello", 0},
//     	{"hello", 1},
//     	{"hello", 2},
//     	{"hello", 3},
//     	{"hello", 4},
//     	{"hello", 5},
//     	{"hello", 6},
//     	{"hello", 7},
//
//     	{"123456789", 0},
//     	{"123456789", 1},
//     	{"123456789", 5},
//     	{"123456789", 8},
//     	{"123456789", 9},
//     	{"123456789", 10},
//     	{"123456789", 11},
//
//     	{"abcdefghijklmnopqrstuvwxyz", 0},
//     	{"abcdefghijklmnopqrstuvwxyz", 1},
//     	{"abcdefghijklmnopqrstuvwxyz", 5},
//     	{"abcdefghijklmnopqrstuvwxyz", 10},
//     	{"abcdefghijklmnopqrstuvwxyz", 25},
//     	{"abcdefghijklmnopqrstuvwxyz", 26},
//     	{"abcdefghijklmnopqrstuvwxyz", 27},
//     	{"abcdefghijklmnopqrstuvwxyz", 50},
//
//     	{"The quick brown fox jumps over the lazy dog", 0},
//     	{"The quick brown fox jumps over the lazy dog", 1},
//     	{"The quick brown fox jumps over the lazy dog", 10},
//     	{"The quick brown fox jumps over the lazy dog", 20},
//     	{"The quick brown fox jumps over the lazy dog", 42},
//     	{"The quick brown fox jumps over the lazy dog", 43},
//     	{"The quick brown fox jumps over the lazy dog", 44},
//     	{"The quick brown fox jumps over the lazy dog", 100},
// 	};
//
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(t_test); i++) {
// 		t_test t = tests[i];
//
// 		char *ref_dest = malloc(sizeof(char) * (t.size + 1));
// 		memset(ref_dest, 0x00, sizeof(char) * (t.size + 1));
// 		size_t ref_len = strlcpy(ref_dest, t.src, t.size);
//
// 		char *dest = malloc(sizeof(char) * (t.size + 1));
// 		memset(dest, 0x00, sizeof(char) * (t.size + 1));
// 		unsigned int len = ft_strlcpy(dest, t.src, t.size);
//
// 		expect_streq(dest, ref_dest, len, ref_len);
// 		free(dest);
// 		free(ref_dest);
// 	}
// }
//
// int main() {
// 	test();
// }
