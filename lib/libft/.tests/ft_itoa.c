#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <limits.h>
#include "../libft.h"

TestSuite(ft_itoa, .timeout = 5);

Test(ft_itoa, positive)
{
    char *result = ft_itoa(12345);

    cr_assert(eq(str, result, "12345"));
    free(result);
}

Test(ft_itoa, zero)
{
    char *result = ft_itoa(0);

    cr_assert(eq(str, result, "0"));
    free(result);
}

Test(ft_itoa, negative)
{
    char *result = ft_itoa(-12345);

    cr_assert(eq(str, result, "-12345"));
    free(result);
}

Test(ft_itoa, single_digit)
{
    char *result = ft_itoa(7);

    cr_assert(eq(str, result, "7"));
    free(result);
}

Test(ft_itoa, negative_single_digit)
{
    char *result = ft_itoa(-7);

    cr_assert(eq(str, result, "-7"));
    free(result);
}

Test(ft_itoa, int_max)
{
    char *result = ft_itoa(INT_MAX);

    cr_assert(eq(str, result, "2147483647"));
    free(result);
}

Test(ft_itoa, int_min)
{
    char *result = ft_itoa(INT_MIN);

    cr_assert(eq(str, result, "-2147483648"));
    free(result);
}

Test(ft_itoa, middle_zeroes)
{
    char *result = ft_itoa(1002003);

    cr_assert(eq(str, result, "1002003"));
    free(result);
}
