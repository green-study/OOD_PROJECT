#include <iostream>
int main()
{
	//레퍼런스를 const 레퍼런스로 바꾸어 상수를 받을 수 있도록 한다
	const int& x = 5;
	std::cout << x << std::endl;

	//또는 다른 변수에 상수를 저장하고 레퍼런스로 받는다.
	int a = 5;
	int& y = a;
	std::cout << y << std::endl;
}