#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_isalpha, .timeout = 5);

Test(ft_isalpha, lowercase_letters)
{
    cr_assert(eq(int, ft_isalpha('a'), 1));
    cr_assert(eq(int, ft_isalpha('m'), 1));
    cr_assert(eq(int, ft_isalpha('z'), 1));
}

Test(ft_isalpha, uppercase_letters)
{
    cr_assert(eq(int, ft_isalpha('A'), 1));
    cr_assert(eq(int, ft_isalpha('M'), 1));
    cr_assert(eq(int, ft_isalpha('Z'), 1));
}

Test(ft_isalpha, digits)
{
    cr_assert(eq(int, ft_isalpha('0'), 0));
    cr_assert(eq(int, ft_isalpha('5'), 0));
    cr_assert(eq(int, ft_isalpha('9'), 0));
}

Test(ft_isalpha, non_alphanumeric)
{
    cr_assert(eq(int, ft_isalpha(' '), 0));
    cr_assert(eq(int, ft_isalpha('\n'), 0));
    cr_assert(eq(int, ft_isalpha('!'), 0));
    cr_assert(eq(int, ft_isalpha('@'), 0));
    cr_assert(eq(int, ft_isalpha('['), 0));
    cr_assert(eq(int, ft_isalpha('{'), 0));
}
