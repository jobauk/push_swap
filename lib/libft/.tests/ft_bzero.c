#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_bzero, .timeout = 5);

Test(ft_bzero, is_zeroed) {
	char arr[] = "Hello, world!";
	char ref[14] = {};

	ft_bzero(arr, sizeof(arr));

	struct cr_mem actual = { .data = arr, .size = sizeof(arr) };
	struct cr_mem expected = { .data = ref, .size = sizeof(ref) };

	cr_assert(eq(mem, actual, expected));
}
