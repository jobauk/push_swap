#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strncmp, .timeout = 5);

Test(ft_strncmp, equal)
{
    cr_assert(eq(ft_strncmp("hello", "hello", 5), 0));
}

Test(ft_strncmp, s1_smaller)
{
    cr_assert(lt(ft_strncmp("abc", "abd", 3), 0));
}

Test(ft_strncmp, s1_greater)
{
    cr_assert(gt(ft_strncmp("abe", "abd", 3), 0));
}

Test(ft_strncmp, limit_to_n)
{
    cr_assert(eq(ft_strncmp("abcX", "abcY", 3), 0));
}

Test(ft_strncmp, different_first_char)
{
    cr_assert(lt(ft_strncmp("abc", "bbc", 3), 0));
}

Test(ft_strncmp, different_last_char)
{
    cr_assert(lt(ft_strncmp("abc", "abd", 3), 0));
}

Test(ft_strncmp, zero_len_eq)
{
    cr_assert(eq(ft_strncmp("abc", "xyz", 0), 0));
}

Test(ft_strncmp, stop_at_null_terminator)
{
    char s1[] = {'a', 'b', '\0', 'x'};
    char s2[] = {'a', 'b', '\0', 'y'};

    cr_assert(eq(ft_strncmp(s1, s2, 4), 0));
}

Test(ft_strncmp, shorter_str_smaller)
{
    cr_assert(lt(ft_strncmp("ab", "abc", 3), 0));
}

Test(ft_strncmp, compare_as_uhar)
{
    unsigned char s1[] = {0xff, '\0'};
    unsigned char s2[] = {0x01, '\0'};

    cr_assert(gt(ft_strncmp((char *)s1, (char *)s2, 1), 0));
}
