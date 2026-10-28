#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strchr, .timeout = 5);

Test(ft_strchr, first_char)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strchr(str, 'h'), &str[0]));
}

Test(ft_strchr, char_in_middle)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strchr(str, 'l'), &str[2]));
}

Test(ft_strchr, last_char)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strchr(str, 'o'), &str[4]));
}

Test(ft_strchr, first_occurrence)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strchr(str, 'l'), &str[2]));
}

Test(ft_strchr, no_match)
{
    char str[] = "hello";
    cr_assert(zero(ptr, ft_strchr(str, 'x')));
}

Test(ft_strchr, null_terminator)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strchr(str, '\0'), &str[5]));
}

Test(ft_strchr, empty_str)
{
    char str[] = "";
    cr_assert(eq(ptr, ft_strchr(str, '\0'), &str[0]));
}

Test(ft_strchr, empty_str_no_match)
{
    char str[] = "";
    cr_assert(zero(ptr, ft_strchr(str, 'a')));
}
