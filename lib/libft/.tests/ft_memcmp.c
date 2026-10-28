#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_memcmp, .timeout = 5);

Test(ft_memcmp, equal)
{
    char s1[] = "hello";
    char s2[] = "hello";

    cr_assert(eq(ft_memcmp(s1, s2, 5), 0));
}

Test(ft_memcmp, s1_lt_s2)
{
    char s1[] = "abc";
    char s2[] = "abd";

    cr_assert(lt(ft_memcmp(s1, s2, 3), 0));
}

Test(ft_memcmp, s1_gt_s2)
{
    char s1[] = "abe";
    char s2[] = "abd";

    cr_assert(gt(ft_memcmp(s1, s2, 3), 0));
}

Test(ft_memcmp, only_compare_n_bytes)
{
    char s1[] = "abcX";
    char s2[] = "abcY";

    cr_assert(eq(ft_memcmp(s1, s2, 3), 0));
}

Test(ft_memcmp, different_first_byte)
{
    char s1[] = "abc";
    char s2[] = "bbc";

    cr_assert(lt(ft_memcmp(s1, s2, 3), 0));
}

Test(ft_memcmp, different_last_byte)
{
    char s1[] = "abc";
    char s2[] = "abd";

    cr_assert(lt(ft_memcmp(s1, s2, 3), 0));
}

Test(ft_memcmp, different_len_buffers)
{
    char s1[] = "axy";
    char s2[] = "ba";

    cr_assert(lt(ft_memcmp(s1, s2, 2), 0));
}

Test(ft_memcmp, zero_n)
{
    char s1[] = "abc";
    char s2[] = "xyz";

    cr_assert(eq(ft_memcmp(s1, s2, 0), 0));
}

Test(ft_memcmp, compare_past_null_byte)
{
    unsigned char s1[] = {'a', '\0', 'b'};
    unsigned char s2[] = {'a', '\0', 'c'};

    cr_assert(lt(ft_memcmp(s1, s2, 3), 0));
}

Test(ft_memcmp, compare_as_uchar)
{
    unsigned char s1[] = {0xff};
    unsigned char s2[] = {0x01};

    cr_assert(gt(ft_memcmp(s1, s2, 1), 0));
}
