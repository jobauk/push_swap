#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_atoi, .timeout = 5);

Test(ft_atoi, zero) {
	cr_assert(eq(int, ft_atoi("0"), 0));
	cr_assert(eq(int, ft_atoi("000"), 0));
	cr_assert(eq(int, ft_atoi("+000"), 0));
	cr_assert(eq(int, ft_atoi("-000"), 0));
}

Test(ft_atoi, leading_zero) {
	cr_assert(eq(int, ft_atoi("042"), 42));
	cr_assert(eq(int, ft_atoi("00042"), 42));
	cr_assert(eq(int, ft_atoi("+00042"), 42));
	cr_assert(eq(int, ft_atoi("-00042"), -42));
}

Test(ft_atoi, leading_ws) {
	cr_assert(eq(int, ft_atoi(" 42"), 42));
	cr_assert(eq(int, ft_atoi(" +42"), 42));
	cr_assert(eq(int, ft_atoi(" -00042"), -42));
	cr_assert(eq(int, ft_atoi("\t42"), 42));
	cr_assert(eq(int, ft_atoi("\n42"), 42));
	cr_assert(eq(int, ft_atoi("\v42"), 42));
	cr_assert(eq(int, ft_atoi("\f42"), 42));
	cr_assert(eq(int, ft_atoi("\r42"), 42));
	cr_assert(eq(int, ft_atoi("\t\n\v\f\r 42"), 42));
}

Test(ft_atoi, leading_chars) {
	cr_assert(eq(int, ft_atoi("42digits"), 42));
	cr_assert(eq(int, ft_atoi(" 42\t"), 42));
	cr_assert(eq(int, ft_atoi("+042hi"), 42));
	cr_assert(eq(int, ft_atoi("-42.78"), -42));
}

Test(ft_atoi, limits) {
	cr_assert(eq(int, ft_atoi("-2147483648"), -2147483648));
	cr_assert(eq(int, ft_atoi("+2147483647"), 2147483647));
	cr_assert(eq(int, ft_atoi("2147483647"), 2147483647));
}


Test(ft_atoi, invalid_input) {
	cr_assert(eq(int, ft_atoi("hello"), 0));
	cr_assert(eq(int, ft_atoi(".78"), 0));
	cr_assert(eq(int, ft_atoi("+"), 0));
	cr_assert(eq(int, ft_atoi(""), 0));
	cr_assert(eq(int, ft_atoi("++42"), 0));
	cr_assert(eq(int, ft_atoi("+-42"), 0));
}
