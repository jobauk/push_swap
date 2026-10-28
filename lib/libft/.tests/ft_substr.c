#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_substr, .timeout = 5);

Test(ft_substr, extract_start)
{
    char *result = ft_substr("hello", 0, 3);

    cr_assert(eq(str, result, "hel"));
    free(result);
}

Test(ft_substr, extract_middle)
{
    char *result = ft_substr("hello world test", 6, 5);

    cr_assert(eq(str, result, "world"));
    free(result);
}

Test(ft_substr, extract_end)
{
    char *result = ft_substr("hello world", 6, 5);

    cr_assert(eq(str, result, "world"));
    free(result);
}

Test(ft_substr, len_too_big)
{
    char *result = ft_substr("hello", 2, 100);

    cr_assert(eq(str, result, "llo"));
    free(result);
}

Test(ft_substr, last_char)
{
    char *result = ft_substr("hello", 4, 1);

    cr_assert(eq(str, result, "o"));
    free(result);
}

Test(ft_substr, null_terminator)
{
    char *result = ft_substr("hello", 5, 3);

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_substr, start_oob)
{
    char *result = ft_substr("hello", 100, 3);

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_substr, zero_len)
{
    char *result = ft_substr("hello", 2, 0);

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_substr, empty_src)
{
    char *result = ft_substr("", 0, 5);

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_substr, new_alloc)
{
    char s[] = "hello";
    char *result = ft_substr(s, 0, 5);

    cr_assert(ne(ptr, result, s));
    free(result);
}

Test(ft_substr, input_unmodified)
{
    char s[] = "hello";
    char *result = ft_substr(s, 1, 3);

    cr_assert(eq(str, s, "hello"));
    free(result);
}
