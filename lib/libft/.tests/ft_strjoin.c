#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strjoin, .timeout = 5);

Test(ft_strjoin, basic)
{
    char *result = ft_strjoin("hello ", "world");

    cr_assert(not(zero(ptr, result)));
    cr_assert(eq(str, result, "hello world"));
    free(result);
}

Test(ft_strjoin, s1_empty)
{
    char *result = ft_strjoin("", "world");

    cr_assert(eq(str, result, "world"));
    free(result);
}

Test(ft_strjoin, s2_empty)
{
    char *result = ft_strjoin("hello", "");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strjoin, both_empty)
{
    char *result = ft_strjoin("", "");

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_strjoin, new_alloc)
{
    char s1[] = "hello";
    char s2[] = "world";
    char *result = ft_strjoin(s1, s2);

    cr_assert(ne(ptr, result, s1));
    cr_assert(ne(ptr, result, s2));
    free(result);
}

Test(ft_strjoin, independent_result)
{
    char s1[] = "hello";
    char s2[] = "world";
    char *result = ft_strjoin(s1, s2);

    s1[0] = 'X';
    s2[0] = 'Y';

    cr_assert(eq(str, result, "helloworld"));
    free(result);
}

Test(ft_strjoin, null_terminated)
{
    char *result = ft_strjoin("abc", "def");

    cr_assert(eq(int, result[6], '\0'));
    free(result);
}
