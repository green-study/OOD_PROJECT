#include <iostream>
int main()
{
	//���۷����� const ���۷����� �ٲپ� ����� ���� �� �ֵ��� �Ѵ�
	const int& x = 5;
	std::cout << x << std::endl;

	//�Ǵ� �ٸ� ������ ����� �����ϰ� ���۷����� �޴´�.
	int a = 5;
	int& y = a;
	std::cout << y << std::endl;
}