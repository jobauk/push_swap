#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_strtrim, .timeout = 5);

Test(ft_strtrim, trim_both_sides)
{
    char *result = ft_strtrim("  hello  ", " ");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strtrim, trim_start)
{
    char *result = ft_strtrim("---hello", "-");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strtrim, trim_end)
{
    char *result = ft_strtrim("hello---", "-");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strtrim, multi_char_set)
{
    char *result = ft_strtrim(" \t\nhello\n\t ", " \t\n");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strtrim, no_middle_trim)
{
    char *result = ft_strtrim("--hel--lo--", "-");

    cr_assert(eq(str, result, "hel--lo"));
    free(result);
}

Test(ft_strtrim, no_trim)
{
    char *result = ft_strtrim("hello", " ");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strtrim, empty_set)
{
    char *result = ft_strtrim("hello", "");

    cr_assert(eq(str, result, "hello"));
    free(result);
}

Test(ft_strtrim, empty_str)
{
    char *result = ft_strtrim("", " ");

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_strtrim, str_is_set)
{
    char *result = ft_strtrim("------", "-");

    cr_assert(eq(str, result, ""));
    free(result);
}

Test(ft_strtrim, new_alloc)
{
    char str[] = "hello";
    char *result = ft_strtrim(str, " ");

    cr_assert(ne(ptr, result, str));
    free(result);
}

Test(ft_strtrim, input_unmodified)
{
    char str[] = "--hello--";
    char *result = ft_strtrim(str, "-");

    cr_assert(eq(str, str, "--hello--"));
    free(result);
}
