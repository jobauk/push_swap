#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_isalnum, .timeout = 5);

Test(ft_isalnum, lowercase_letters)
{
    cr_assert(eq(int, ft_isalnum('a'), 1));
    cr_assert(eq(int, ft_isalnum('m'), 1));
    cr_assert(eq(int, ft_isalnum('z'), 1));
}

Test(ft_isalnum, uppercase_letters)
{
    cr_assert(eq(int, ft_isalnum('A'), 1));
    cr_assert(eq(int, ft_isalnum('M'), 1));
    cr_assert(eq(int, ft_isalnum('Z'), 1));
}

Test(ft_isalnum, digits)
{
    cr_assert(eq(int, ft_isalnum('0'), 1));
    cr_assert(eq(int, ft_isalnum('5'), 1));
    cr_assert(eq(int, ft_isalnum('9'), 1));
}

Test(ft_isalnum, non_alphanumeric)
{
    cr_assert(eq(int, ft_isalnum(' '), 0));
    cr_assert(eq(int, ft_isalnum('\n'), 0));
    cr_assert(eq(int, ft_isalnum('!'), 0));
    cr_assert(eq(int, ft_isalnum('@'), 0));
    cr_assert(eq(int, ft_isalnum('['), 0));
    cr_assert(eq(int, ft_isalnum('{'), 0));
}
