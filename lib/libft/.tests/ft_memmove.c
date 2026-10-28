#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_memmove, .timeout = 5);

Test(ft_memmove, copies_bytes)
{
    char src[] = "hello";
    char dest[6] = {0};

    cr_assert(eq(ptr, ft_memmove(dest, src, 5), dest));
    cr_assert(eq(str, dest, "hello"));
}

Test(ft_memmove, limit_to_n)
{
    char src[] = "hello";
    char dest[] = "xxxxx";

    cr_assert(eq(ptr, ft_memmove(dest, src, 3), dest));
    cr_assert(eq(str, dest, "helxx"));
}

Test(ft_memmove, overlap_dest_after_src)
{
    char src[] = "abcdef";

    cr_assert(eq(ptr, ft_memmove(src + 2, src, 4), src + 2));
    cr_assert(eq(str, src, "ababcd"));
}

Test(ft_memmove, overlap_dest_before_src)
{
    char src[] = "abcdef";

    cr_assert(eq(ptr, ft_memmove(src, src + 2, 4), src));
    cr_assert(eq(str, src, "cdefef"));
}

Test(ft_memmove, src_eq_dest)
{
    char src[] = "hello";

    cr_assert(eq(ptr, ft_memmove(src, src, 5), src));
    cr_assert(eq(str, src, "hello"));
}

Test(ft_memmove, zero_n)
{
    char src[] = "abc";
    char dest[] = "xyz";

    cr_assert(eq(ptr, ft_memmove(dest, src, 0), dest));
    cr_assert(eq(str, dest, "xyz"));
}

Test(ft_memmove, copies_null_bytes)
{
    unsigned char src[] = {'a', '\0', 'b', 'c'};
    unsigned char dest[4] = {0};

    struct cr_mem src_mem = { src, 4 };
    struct cr_mem dest_mem = { dest, 4 };

    cr_assert(eq(ptr, ft_memmove(dest, src, sizeof(src)), dest));
    cr_assert(eq(mem, dest_mem, src_mem));
}
