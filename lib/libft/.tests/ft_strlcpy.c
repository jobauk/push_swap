#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strlcpy, .timeout = 5);

Test(ft_strlcpy, copies_full)
{
    char dst[16];
    size_t len = ft_strlcpy(dst, "hello", sizeof(dst));

    cr_assert(eq(str, dst, "hello"));
    cr_assert(eq(sz, len, 5));
}

Test(ft_strlcpy, truncates)
{
    char dst[4];
    size_t len = ft_strlcpy(dst, "hello", sizeof(dst));

    cr_assert(eq(str, dst, "hel"));
    cr_assert(eq(sz, len, 5));
}

Test(ft_strlcpy, exact_fit)
{
    char dst[6];
    size_t len = ft_strlcpy(dst, "hello", sizeof(dst));

    cr_assert(eq(str, dst, "hello"));
    cr_assert(eq(sz, len, 5));
}

Test(ft_strlcpy, size_one)
{
    char dst[1] = {'x'};
    size_t len = ft_strlcpy(dst, "hello", sizeof(dst));

    cr_assert(eq(chr, dst[0], '\0'));
    cr_assert(eq(sz, len, 5));
}

Test(ft_strlcpy, size_zero)
{
    char dst[] = "unchanged";
    size_t len = ft_strlcpy(dst, "hello", 0);

    cr_assert(eq(str, dst, "unchanged"));
    cr_assert(eq(sz, len, 5));
}

Test(ft_strlcpy, empty_src)
{
    char dst[8] = "xxxx";
    size_t len = ft_strlcpy(dst, "", sizeof(dst));

    cr_assert(eq(str, dst, ""));
    cr_assert(eq(sz, len, 0));
}

Test(ft_strlcpy, null_terminates)
{
    char dst[4] = {'x', 'x', 'x', 'x'};
    size_t len = ft_strlcpy(dst, "abcdef", sizeof(dst));

    cr_assert(eq(int, dst[3], '\0'));
    cr_assert(eq(sz, len, 6));
}

Test(ft_strlcpy, limit_to_size)
{
    char dst[6] = {'x', 'x', 'x', 'x', 'Y', 'Z'};
    size_t len = ft_strlcpy(dst, "abcdef", 4);

    struct cr_mem dst_mem = {dst, sizeof(dst)};
    struct cr_mem expected_mem = {"abc\0YZ", 6};

    cr_assert(eq(mem, dst_mem, expected_mem));
    cr_assert(eq(sz, len, 6));
}
