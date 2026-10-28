#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_calloc, .timeout = 5);

Test(ft_calloc, allocates_zeroed_buf) {
	struct cr_mem actual = { .data = ft_calloc(4, 1), .size = 4 };
	struct cr_mem expected = { .data = (unsigned char[4]){}, .size = 4 };
	cr_assert(eq(mem, actual, expected));
	free((void *)actual.data);
}

Test(ft_calloc, returns_null_on_zero) {
	cr_assert(zero(ptr, ft_calloc(4, 0)));
	cr_assert(zero(ptr, ft_calloc(0, 4)));
}

Test(ft_calloc, returns_null_on_overflow) {
	cr_assert(zero(ptr, ft_calloc(SIZE_MAX, 2)));
}
