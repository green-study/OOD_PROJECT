#include <iostream>
#include <string>
#include <cassert>

class Base {
	std::string s;

public:
	Base() : s("Base") { std::cout << "Base class constructor" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }
};

class Derived : public Base {
	std::string s;

public:
	Derived() : s("Derived"), Base() { std::cout << "Derived class constructor" << std::endl; }

	void what() { std::cout << s << std::endl; }
};
int main() {

	Base p;
	Derived c;
	bool find = true;

	std::cout << " === Pointer ===" << std::endl;
	Base* xx = &c;//OK.upcast
	//try catch�� ����ϱ�?
	try {
		Derived& check = dynamic_cast<Derived&>(p);
	}
	catch (std::bad_cast e) {
		std::cout << "Caught: " << e.what() << std::endl;
		find = false;
	}
	if (find) {
		Derived yy = dynamic_cast<Derived&>(p); // �߸��� ���۷��� ĳ���� Base�� Derived�� �ٿ�ĳ���� �õ�
		yy.what();
	}
	getchar();
	return 0;
}
