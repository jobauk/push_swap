#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_tolower, .timeout = 5);

Test(ft_tolower, uppercase)
{
    cr_assert(eq(int, ft_tolower('A'), 'a'));
    cr_assert(eq(int, ft_tolower('M'), 'm'));
    cr_assert(eq(int, ft_tolower('Z'), 'z'));
}

Test(ft_tolower, lowercase_unchanged)
{
    cr_assert(eq(int, ft_tolower('a'), 'a'));
    cr_assert(eq(int, ft_tolower('m'), 'm'));
    cr_assert(eq(int, ft_tolower('z'), 'z'));
}

Test(ft_tolower, digits_unchanged)
{
    cr_assert(eq(int, ft_tolower('0'), '0'));
    cr_assert(eq(int, ft_tolower('5'), '5'));
    cr_assert(eq(int, ft_tolower('9'), '9'));
}

Test(ft_tolower, symbols_unchanged)
{
    cr_assert(eq(int, ft_tolower('!'), '!'));
    cr_assert(eq(int, ft_tolower('@'), '@'));
    cr_assert(eq(int, ft_tolower('{'), '{'));
}
