#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strlen, .timeout = 5);

Test(ft_strlen, normal_str)
{
    cr_assert(eq(sz, ft_strlen("hello"), 5));
}

Test(ft_strlen, empty_str)
{
    cr_assert(eq(sz, ft_strlen(""), 0));
}

Test(ft_strlen, single_char)
{
    cr_assert(eq(sz, ft_strlen("a"), 1));
}

Test(ft_strlen, stop_at_null_terminator)
{
    char s[] = {'a', 'b', '\0', 'c', 'd', '\0'};
    cr_assert(eq(sz, ft_strlen(s), 2));
}

Test(ft_strlen, count_non_alphanum)
{
    cr_assert(eq(sz, ft_strlen("a b!@#"), 6));
}

Test(ft_strlen, long_str)
{
    cr_assert(eq(sz, ft_strlen("abcdefghijklmnopqrstuvwxyz"), 26));
}
