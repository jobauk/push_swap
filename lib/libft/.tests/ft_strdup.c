#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strdup, .timeout = 5);

Test(ft_strdup, duplicates_str)
{
    char *copy = ft_strdup("hello");

    cr_assert(not(zero(ptr, copy)));
    cr_assert(eq(str, copy, "hello"));
    free(copy);
}

Test(ft_strdup, new_alloc)
{
    char str[] = "hello";
    char *copy = ft_strdup(str);

    cr_assert(ne(ptr, copy, str));
    free(copy);
}

Test(ft_strdup, duplicates_empty_str)
{
    char *copy = ft_strdup("");

    cr_assert(not(zero(ptr, copy)));
    cr_assert(eq(str, copy, ""));
    free(copy);
}

Test(ft_strdup, copy_is_independent)
{
    char str[] = "hello";
    char *copy = ft_strdup(str);

    str[0] = 'X';

    cr_assert(eq(str, copy, "hello"));
    free(copy);
}

Test(ft_strdup, has_null_terminator)
{
    char *copy = ft_strdup("abc");

    cr_assert(eq(chr, copy[3], '\0'));
    free(copy);
}
