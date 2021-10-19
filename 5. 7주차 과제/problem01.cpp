#include <iostream>
#define interface class

interface Strategy {
public:
	virtual ~Strategy() {}
	virtual int doOperation(int num1, int num2)  = 0;
};

class OperationAdd :public Strategy {
public:
	virtual int doOperation(int num1, int num2) {
		return num1 + num2;
	}
};

class OperationSubstract :public Strategy {
public:
	virtual int doOperation(int num1, int num2) {
		return num1 - num2;
	}
};

class OperationMultiply :public Strategy {
public:
	virtual int doOperation(int num1, int num2) {
		return num1 * num2;
	}
};

class Context {
	Strategy *strategy;
public:
	Context(Strategy* strategy) :strategy(strategy) {}
	~Context() { delete this->strategy; }

	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};

int main() {
	Context *context1 = new Context(new OperationAdd());
	std::cout << "10 + 5 = " << context1->executeStrategy(10, 5) << std::endl;
	Context *context2 = new Context(new OperationSubstract());
	std::cout << "10 - 5 = " << context2->executeStrategy(10, 5) << std::endl;
	Context* context3 = new Context(new OperationMultiply());
	std::cout << "10 * 5 = " << context3->executeStrategy(10, 5) << std::endl;
}