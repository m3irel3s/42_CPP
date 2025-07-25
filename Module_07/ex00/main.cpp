#include "Whatever.hpp"

int main()
{
	int a = 10;
	int b = 5;

	int res1 = max(a, b);
	std::cout << "max between: " << a << " and " << b << " -> " << res1 << std::endl;
	
	char e = 'a';
	char f = 'z';
	
	char res2 = min(e, f);
	std::cout << "min between: " << e << " and " << f << " -> " << res2 << std::endl;
	
	std::string g = "bb";
	std::string h = "aaaaa";
	
	std::string res3 = max(g, h);
	std::cout << "max between: " << g << " and " << h << " -> " << res3 << std::endl;

	std::cout << "old g value: " << g << std::endl;
	std::cout << "old h value: " << h << std::endl;
	
	swap(g, h);
	
	std::cout << "new g value: " << g << std::endl;
	std::cout << "new h value: " << h << std::endl;
}