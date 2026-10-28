#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strrchrr, .timeout = 5);

Test(ft_strrchr, first_char)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strrchr(str, 'h'), &str[0]));
}

Test(ft_strrchr, last_char)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strrchr(str, 'o'), &str[4]));
}

Test(ft_strrchr, last_occurrence)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strrchr(str, 'l'), &str[3]));
}

Test(ft_strrchr, no_match)
{
    char str[] = "hello";
    cr_assert(zero(ptr, ft_strrchr(str, 'x')));
}

Test(ft_strrchr, null_terminator)
{
    char str[] = "hello";
    cr_assert(eq(ptr, ft_strrchr(str, '\0'), &str[5]));
}

Test(ft_strrchr, empty_str)
{
    char str[] = "";
    cr_assert(eq(ptr, ft_strrchr(str, '\0'), &str[0]));
}

Test(ft_strrchr, empty_str_no_match)
{
    char str[] = "";
    cr_assert(zero(ptr, ft_strrchr(str, 'a')));
}
