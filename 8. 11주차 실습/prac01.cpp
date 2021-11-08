#include<iostream>
#include<set>
#include<string>

int main(){
	std::set<int> setOfNumbers;
	int num[10];
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
	}
	for (int i = 0; i < 10; i++) {
		setOfNumbers.insert(num[i]);
	}
	int check = 0;
	for (std::set<int>::iterator it = setOfNumbers.begin(); it != setOfNumbers.end(); ++it) {
		if (check == 0) {
			std::cout << *it;
		}
		if (check == 9) {
			std::cout <<' '<< * it << std::endl;
		}
		check++;
	}

	return 0;
}