#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

static char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - ' ');
    return (c);
}

static char add_index(unsigned int i, char c)
{
    return (c + i);
}

TestSuite(ft_strmapi, .timeout = 5);

Test(ft_strmapi, normal)
{
    char *result = ft_strmapi("hello", to_upper);

    cr_assert(eq(str, result, "HELLO"));
    free(result);
}

Test(ft_strmapi, pass_correct_index)
{
    char *result = ft_strmapi("aaaa", add_index);

    cr_assert(eq(str, result, "abcd"));
    free(result);
}

Test(ft_strmapi, empty_string)
{
    char *result = ft_strmapi("", to_upper);

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_strmapi, new_alloc)
{
    char str[] = "hello";
    char *result = ft_strmapi(str, to_upper);

    cr_assert(ne(ptr, result, str));
    free(result);
}

Test(ft_strmapi, input_unmodified)
{
    char str[] = "hello";
    char *result = ft_strmapi(str, to_upper);

    cr_assert(eq(str, str, "hello"));
    free(result);
}
