#include <cstdint>
#include <cstdlib>
#include <iostream>

uint8_t rand5()
{
	return (1 + rand() % 5);
}

uint8_t rand7()
{
	uint8_t res = 0;
	while (res == 0) { // range from 1 to 7
		for (auto i = 0; i < 3; ++i) {
			uint8_t r;
			while ((r = rand5()) == 3);
			res += (r < 3) << i;
		}
	}
	return res;
}

int main()
{
	for (auto i=0;i<100;++i)
		std::cout << (int32_t)rand7() << " ";
	return 0;
}