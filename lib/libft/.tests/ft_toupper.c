#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_toupper, .timeout = 5);

Test(ft_toupper, lowercase)
{
    cr_assert(eq(int, ft_toupper('a'), 'A'));
    cr_assert(eq(int, ft_toupper('m'), 'M'));
    cr_assert(eq(int, ft_toupper('z'), 'Z'));
}

Test(ft_toupper, uppercase_unchanged)
{
    cr_assert(eq(int, ft_toupper('A'), 'A'));
    cr_assert(eq(int, ft_toupper('M'), 'M'));
    cr_assert(eq(int, ft_toupper('Z'), 'Z'));
}

Test(ft_toupper, digits_unchanged)
{
    cr_assert(eq(int, ft_toupper('0'), '0'));
    cr_assert(eq(int, ft_toupper('5'), '5'));
    cr_assert(eq(int, ft_toupper('9'), '9'));
}

Test(ft_toupper, symbols_unchanged)
{
    cr_assert(eq(int, ft_toupper('!'), '!'));
    cr_assert(eq(int, ft_toupper('@'), '@'));
    cr_assert(eq(int, ft_toupper('{'), '{'));
}
