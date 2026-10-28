#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_isprint, .timeout = 5);

Test(ft_isprint, lowercase_letters)
{
    cr_assert(eq(int, ft_isprint('a'), 1));
    cr_assert(eq(int, ft_isprint('m'), 1));
    cr_assert(eq(int, ft_isprint('z'), 1));
}

Test(ft_isprint, uppercase_letters)
{
    cr_assert(eq(int, ft_isprint('A'), 1));
    cr_assert(eq(int, ft_isprint('M'), 1));
    cr_assert(eq(int, ft_isprint('Z'), 1));
}

Test(ft_isprint, digits)
{
    cr_assert(eq(int, ft_isprint('0'), 1));
    cr_assert(eq(int, ft_isprint('5'), 1));
    cr_assert(eq(int, ft_isprint('9'), 1));
}

Test(ft_isprint, non_alphanumeric)
{
    cr_assert(eq(int, ft_isprint(' '), 1));
    cr_assert(eq(int, ft_isprint('!'), 1));
    cr_assert(eq(int, ft_isprint('@'), 1));
    cr_assert(eq(int, ft_isprint('['), 1));
    cr_assert(eq(int, ft_isprint('{'), 1));
}


Test(ft_isprint, ws)
{
    cr_assert(eq(int, ft_isprint('\t'), 0));
    cr_assert(eq(int, ft_isprint('\n'), 0));
    cr_assert(eq(int, ft_isprint('\v'), 0));
    cr_assert(eq(int, ft_isprint('\f'), 0));
    cr_assert(eq(int, ft_isprint('\r'), 0));
}

Test(ft_isprint, non_ascii)
{
	cr_assert(eq(int, ft_isprint('\x80'), 0));
    cr_assert(eq(int, ft_isprint('\xff'), 0));
}
