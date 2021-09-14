#include <stdio.h>

int main() {
	char s[101];
	printf("문자를 입력하세요(100자 이내).");
	scanf("%s", s);
	printf("입력된 문자는 %s입니다.",s);
	//system("pause"); // keep terminal open
	return 0;
}