#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strnstr, .timeout = 5);

Test(ft_strnstr, match_start)
{
    char big[] = "hello world";
    cr_assert(eq(ptr, ft_strnstr(big, "hello", 11), &big[0]));
}

Test(ft_strnstr, match_middle)
{
    char big[] = "hello world";
    cr_assert(eq(ptr, ft_strnstr(big, "world", 11), &big[6]));
}

Test(ft_strnstr, match_first_occurrence)
{
    char big[] = "abcabc";
    cr_assert(eq(ptr, ft_strnstr(big, "abc", 6), &big[0]));
}

Test(ft_strnstr, no_match)
{
    char big[] = "hello";
    cr_assert(zero(ptr, ft_strnstr(big, "xyz", 5)));
}

Test(ft_strnstr, limit_to_len)
{
    char big[] = "hello world";
    cr_assert(zero(ptr, ft_strnstr(big, "world", 10)));
}

Test(ft_strnstr, no_match_within_len)
{
    char big[] = "hello world";
    cr_assert(zero(ptr, ft_strnstr(big, "world", 8)));
}

Test(ft_strnstr, empty_little)
{
    char big[] = "hello";
    cr_assert(eq(ptr, ft_strnstr(big, "", 5), big));
}

Test(ft_strnstr, empty_little_zero_len)
{
    char big[] = "hello";
    cr_assert(eq(ptr, ft_strnstr(big, "", 0), big));
}

Test(ft_strnstr, zero_len)
{
    char big[] = "hello";
    cr_assert(zero(ptr, ft_strnstr(big, "h", 0)));
}

Test(ft_strnstr, stop_at_null_terminator)
{
    char big[] = {'a', 'b', '\0', 'c', 'd', '\0'};
    cr_assert(zero(ptr, ft_strnstr(big, "cd", 5)));
}
