#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_memset, .timeout = 5);

Test(ft_memset, fills_buf) {
	struct cr_mem actual = { (unsigned char[8]){}, 8 };
	struct cr_mem expected = {
		(unsigned char[8]){
			0x42, 0x42, 0x42, 0x42,
			0x42, 0x42, 0x42, 0x42
		},
		8
	};

	cr_assert(eq(ptr, ft_memset((void *)actual.data, 0x42, sizeof(actual.data)), (void *)actual.data));
	cr_assert(eq(mem, actual, expected));
}

Test(ft_memset, zero_len) {
	struct cr_mem actual = { (unsigned char[4]){1, 2, 3, 4}, 4 };
	struct cr_mem expected = { (unsigned char[4]){1, 2, 3, 4}, 4 };

	cr_assert(eq(ptr, ft_memset((void *)actual.data, 0xff, 0), (void *)actual.data));
	cr_assert(eq(mem, actual, expected));
}
