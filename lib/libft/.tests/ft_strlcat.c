#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strlcat, .timeout = 5);


Test(ft_strlcat, append_full)
{
    char dest[16] = "hello";
    size_t len = ft_strlcat(dest, " world", sizeof(dest));

    cr_assert(eq(str, dest, "hello world"));
    cr_assert(eq(sz, len, 11));
}

Test(ft_strlcat, truncates)
{
    char dest[8] = "abc";
    size_t len = ft_strlcat(dest, "defghi", sizeof(dest));

    cr_assert(eq(str, dest, "abcdefg"));
    cr_assert(eq(sz, len, 9));
}

Test(ft_strlcat, exact_fit)
{
    char dest[7] = "abc";
    size_t len = ft_strlcat(dest, "def", sizeof(dest));

    cr_assert(eq(str, dest, "abcdef"));
    cr_assert(eq(sz, len, 6));
}

Test(ft_strlcat, size_zero)
{
    char dest[] = "abc";
    size_t len = ft_strlcat(dest, "def", 0);

    cr_assert(eq(str, dest, "abc"));
    cr_assert(eq(sz, len, 3));
}

Test(ft_strlcat, empty_src)
{
    char dest[8] = "abc";
    size_t len = ft_strlcat(dest, "", sizeof(dest));

    cr_assert(eq(str, dest, "abc"));
    cr_assert(eq(sz, len, 3));
}

Test(ft_strlcat, empty_dest)
{
    char dest[8] = "";
    size_t len = ft_strlcat(dest, "abc", sizeof(dest));

    cr_assert(eq(str, dest, "abc"));
    cr_assert(eq(sz, len, 3));
}
