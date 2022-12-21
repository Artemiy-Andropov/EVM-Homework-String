#include <iostream>
#include "String.h"
#include "Exception.h"

int main()
{
	try
	{
		String test_1;

		String test_2;

		std::cin >> test_1;

		std::cin >> test_2;

		std::cout << test_1 << std::endl;

		char c = ' ';

		test_1.Insert(c, 3);

		std::cout << test_1 << std::endl;

		test_1.Erase(2, 5);

		std::cout << test_1 << std::endl;

		c = '?';

		test_1.Push_Back(c);

		std::cout << test_1 << std::endl;

		test_1.Resize(10, c);

		std::cout << test_1 << std::endl;

		test_1.Swap(test_2);

		std::cout << test_1 << std::endl;
		std::cout << test_2 << std::endl;

		test_2.Append(test_1);

		std::cout << test_2 << std::endl;

		test_1 = test_1.C_str();

		for (int index = 0; index < test_1.Lenght(); ++index)
			std::cout << static_cast<int>(test_1[index]) << " ";

		std::cout << std::endl;

		String test_3(test_2);

		test_3.Erase(2, 15);

		std::cout << test_3 << std::endl;

		std::cout << test_2.Find(test_3, 0) << std::endl;

		String test_4;

		test_4 = test_2.SubStr(3, 25);

		std::cout << test_2 << std::endl;
		std::cout << test_4 << std::endl;

		std::cout << test_4[72] << std::endl;
	}
	catch (StringException& exception_)
	{
		std::cerr << "An exception occurred at string (" << exception_.GetError() << ")" << std::endl;
	}
	return 0;
}