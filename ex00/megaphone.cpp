#include <cstring>
#include <iostream>

int	main(int c, char **arg)
{
	for (int i = 1; i < c; i++)
		for (unsigned int j = 0; j < std::strlen(arg[i]); j++)
			std::cout << static_cast<char>(std::toupper(arg[i][j]));
	if (c == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
}
