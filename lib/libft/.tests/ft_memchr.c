#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <limits.h>
#include "../libft.h"

TestSuite(ft_memchr, .timeout = 5);

Test(ft_memchr, first_byte)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_memchr(str, 'h', 5), &str[0]));
}

Test(ft_memchr, middle_byte)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_memchr(str, 'l', 5), &str[2]));
}

Test(ft_memchr, last_byte)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_memchr(str, 'o', 5), &str[4]));
}

Test(ft_memchr, no_match)
{
    char str[] = "hello";
    cr_assert(zero(ptr, ft_memchr(str, 'x', 5)));
}

Test(ft_memchr, limit_search_to_n)
{
    char str[] = "hello";
    cr_assert(zero(ptr, ft_memchr(str, 'o', 4)));
}

Test(ft_memchr, zero_n)
{
    char str[] = "hello";
    cr_assert(zero(ptr, ft_memchr(str, 'h', 0)));
}

Test(ft_memchr, past_null_byte)
{
    unsigned char str[] = {'a', '\0', 'b', 'c'};
    cr_assert(eq(ptr, ft_memchr(str, 'b', sizeof(str)), &str[2]));
}

Test(ft_memchr, find_null_byte)
{
    unsigned char str[] = {'a', '\0', 'b'};
    cr_assert(eq(ptr, ft_memchr(str, '\0', sizeof(str)), &str[1]));
}

Test(ft_memchr, treat_c_as_uchar)
{
    unsigned char str[] = {'a', UCHAR_MAX, 'b'};
    cr_assert(eq(ptr, ft_memchr(str, -1, sizeof(str)), &str[1]));
}
