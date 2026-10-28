#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_isdigit, .timeout = 5);

Test(ft_isdigit, lowercase_letters)
{
    cr_assert(eq(int, ft_isdigit('a'), 0));
    cr_assert(eq(int, ft_isdigit('m'), 0));
    cr_assert(eq(int, ft_isdigit('z'), 0));
}

Test(ft_isdigit, uppercase_letters)
{
    cr_assert(eq(int, ft_isdigit('A'), 0));
    cr_assert(eq(int, ft_isdigit('M'), 0));
    cr_assert(eq(int, ft_isdigit('Z'), 0));
}

Test(ft_isdigit, digits)
{
    cr_assert(eq(int, ft_isdigit('0'), 1));
    cr_assert(eq(int, ft_isdigit('5'), 1));
    cr_assert(eq(int, ft_isdigit('9'), 1));
}

Test(ft_isdigit, non_alphanumeric)
{
    cr_assert(eq(int, ft_isdigit(' '), 0));
    cr_assert(eq(int, ft_isdigit('\n'), 0));
    cr_assert(eq(int, ft_isdigit('!'), 0));
    cr_assert(eq(int, ft_isdigit('@'), 0));
    cr_assert(eq(int, ft_isdigit('['), 0));
    cr_assert(eq(int, ft_isdigit('{'), 0));
}
