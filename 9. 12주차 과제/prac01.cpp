#include <iostream>

template < typename T>
void swapXX(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;

	swapXX<int> (a, b);
	swapXX<float> (c, d);

	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	return 0;
}
