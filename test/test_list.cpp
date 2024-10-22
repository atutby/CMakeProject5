#include <iostream>

TEST() {
	const size_t x{ 5 };
	const size_t y{ 5 };
	ASSERT_EQ(x, y);
}