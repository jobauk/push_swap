#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_isascii, .timeout = 5);

Test(ft_isascii, lowercase_letters)
{
    cr_assert(eq(int, ft_isascii('a'), 1));
    cr_assert(eq(int, ft_isascii('m'), 1));
    cr_assert(eq(int, ft_isascii('z'), 1));
}

Test(ft_isascii, uppercase_letters)
{
    cr_assert(eq(int, ft_isascii('A'), 1));
    cr_assert(eq(int, ft_isascii('M'), 1));
    cr_assert(eq(int, ft_isascii('Z'), 1));
}

Test(ft_isascii, digits)
{
    cr_assert(eq(int, ft_isascii('0'), 1));
    cr_assert(eq(int, ft_isascii('5'), 1));
    cr_assert(eq(int, ft_isascii('9'), 1));
}

Test(ft_isascii, non_alphanumeric)
{
    cr_assert(eq(int, ft_isascii(' '), 1));
    cr_assert(eq(int, ft_isascii('\n'), 1));
    cr_assert(eq(int, ft_isascii('!'), 1));
    cr_assert(eq(int, ft_isascii('@'), 1));
    cr_assert(eq(int, ft_isascii('['), 1));
    cr_assert(eq(int, ft_isascii('{'), 1));
}

Test(ft_isascii, non_ascii)
{
	cr_assert(eq(int, ft_isascii('\x80'), 0));
    cr_assert(eq(int, ft_isascii('\xff'), 0));
}
