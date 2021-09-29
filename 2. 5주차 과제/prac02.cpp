#include <iostream>
using namespace std;
int i;
class A
{
public:
	~A()
	{
		i = 10;
	}
};
int& foo()
{
	i = 10;
	int& j = i;
	A ob;
	return j;
}
int main()
{
	cout << foo() << endl;
	return 0;
}