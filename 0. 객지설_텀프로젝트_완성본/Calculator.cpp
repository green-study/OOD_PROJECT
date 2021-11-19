#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#define interface class

using namespace std;

interface Strategy {
public:
	virtual long operation(long num1, long num2) = 0;
};

class CalculateAdd : public Strategy {
public:
	long operation(long num1, long num2) {
		return num1 + num2;
	}
};

class CalculateSub : public Strategy {
public:
	long operation(long num1, long num2) {
		return num1 - num2;
	}
};

class CalculateMul : public Strategy {
public:
	long operation(long num1, long num2) {
		return num1 * num2;
	}
};

class CalculateDiv : public Strategy {
public:
	long operation(long num1, long num2) {
		return num1 / num2;
	}
};

class Find_operator {
	Strategy* strategy;
public:
	Find_operator(Strategy* strategy) {
		this->strategy = strategy;
	}
	~Find_operator() {}
	long executeStrategy(int num1, int num2) {
		return strategy->operation(num1, num2);
	}
};

class Calculator {
	char* input;
	static Calculator* calculator;
	Calculator(char* input = 0) {
		this->input = input;
	}
public:
	void set_input(char* input) {
		this->input = input;
	}
	long get_result() {
		vector<string> test = split(input);
		long result = Result(Convert(test));
		return result;
	}
	static Calculator* instance() {
		if (calculator==NULL) {
			calculator = new Calculator;
		}
		return calculator;
	}
	int GetOpPrec(string op)
	{
		if (op == "*" || op == "/") {
			return 2;
		}
		else if (op == "+" || op == "-") {
			return 1;
		}
		else if (op == "(") {
			return 0;
		}
		else if (op == ")") {
			return -1;
		}
		else {
			return -2;
		}
	}

	int WhoPreOp(string op1, string op2)
	{
		int op1Prec = GetOpPrec(op1);
		int op2Prec = GetOpPrec(op2);

		if (op1Prec >= op2Prec)
		{
			return 1;
		}
		else if (op1Prec < op2Prec)
		{
			return 0;
		}
	}


	vector<string> Convert(vector<string> test)
	{
		stack<string> oper;
		vector<string> changed;
		string word;
		int code;
		string temp;

		vector<string>::iterator iter;

		for (auto iter = test.begin(); iter != test.end(); iter++)
		{
			word = *iter;
			code = GetOpPrec(word);

			switch (code)
			{
			case -2: //숫자
				changed.push_back(word);
				break;
			case 2: //곱하기나누기
			case 1: //더하기빼기
				while (oper.size() > 0)
				{
					//Stack이 비어있지 않다면
					temp = oper.top();

					if (WhoPreOp(temp, word))
					{	//스택에 있는 연산자 우선순위가 높다면
						temp = oper.top();
						oper.pop();

						changed.push_back(temp);
					}
					else {
						break;
					}
				}
				oper.push(word);

				break;
			case 0:
				oper.push(word);
				break;
			case -1:
				while (1)
				{
					temp = oper.top();
					oper.pop();
					if (oper.empty() && temp != "(") {
						throw exception("check operator");
						break;
					}
					if (temp == "(")
					{
						break;
					}

					changed.push_back(temp);
				}

			default:
				break;
			}

		}
		//남아있으면 pop
		while (!oper.empty())
		{
			temp = oper.top();
			oper.pop();
			changed.push_back(temp);
		}


		return changed;


	}


	long Calc(long first, long second, string word)
	{
		if (word == "*") {
			Find_operator* foperator = new Find_operator(new CalculateMul());
			return foperator->executeStrategy(first, second);
		}
		else if (word == "/") {
			if (second == 0) {
				throw exception("can't divide by ZERO!");
				return 0;
			}
			Find_operator* foperator = new Find_operator(new CalculateDiv());
			return foperator->executeStrategy(first, second);
		}
		else if (word == "+") {
			Find_operator* foperator = new Find_operator(new CalculateAdd());
			return foperator->executeStrategy(first, second);
		}
		else if (word == "-") {
			Find_operator* foperator = new Find_operator(new CalculateSub());
			return foperator->executeStrategy(first, second);
		}

	}

	long Result(vector<string> test)
	{
		stack<long> oper1;
		string word;
		long first;
		long second;
		long result;
		long temp;
		vector<string>::iterator iter;

		for (auto iter = test.begin(); iter != test.end(); iter++)
		{
			word = *iter;
			if (isdigit(word[0]))
			{
				oper1.push(stol(word));
			}
			else {
				if (oper1.empty()) {
					throw exception("check operator!");
					return 0;
				}
				temp = oper1.top();
				oper1.pop();
				if (oper1.empty()) {
					throw exception("check operator!");
					return 0;
				}
				second = temp;
				temp = oper1.top();
				oper1.pop();
				first = temp;
				try {
					result = Calc(first, second, word);
				}
				catch (exception& e) {
					throw;
				}
				oper1.push(result);
			}
		}
		temp = oper1.top();
		oper1.pop();
		if (!oper1.empty()) {
			throw exception("wrong input, check plz!");
			return 0;
		}
		return temp;

	}


	vector<string> split(const char* str)
	{
		vector<string> result;
		do
		{
			const char* begin = str;
			int check = 0;
			int hex = 0;
			int binary = 0;
			while (*str != ' ' && *str != '+' && *str != '-' && *str != '/' && *str != '*' && *str != '(' && *str != ')' && *str) {
				if (hex == 1) {
					if (!((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f'))) {
						throw exception("wrong hex input, check plz!");
						return result;
					}
				}
				if (binary == 1) {
					if (!(*str >= '0' && *str <= '1')) {
						throw exception("wrong binary input, check plz!");
						return result;
					}
				}
				
				if (*str == 'x') {
					hex = 1;
				}
				else if (*str == 'b') {
					binary = 1;
				}
				if (hex == 0 && binary == 0) {
					if (!(*str >= '0' && *str <= '9')) {
						throw exception("wrong input, check plz!");
						return result;
					}
				}
				str++;
				check = 1;
			}
			if (check) {
				string num = string(begin, str);
				unsigned long lnum;
				if (hex) {
					if (num[0] != '0') {
						throw exception("wrong hex input, check plz!");
						return result;
					}
					num = num.substr(2);
					lnum = stol(num, NULL, 16);
					num = to_string(lnum);
					hex = 0;
				}
				else if (binary) {
					if (num[0] != '0') {
						throw exception("wrong binary input, check plz!");
						return result;
					}
					num = num.substr(2);
					lnum = stol(num, NULL, 2);
					num = to_string(lnum);
					binary = 0;
				}
				result.push_back(num);
				check = 0;
			}
			if (*str == ' ') {
				str++;
			}
			while (*str == '+' || *str == '-' || *str == '/' || *str == '*' || *str == '(' || *str == ')') {
				string temp;
				temp = *str;
				result.push_back(temp);
				str++;
			}
			if (*str == NULL) {
				break;
			}
		} while (1);

		return result;
	}
};
Calculator* Calculator::calculator = 0;
int main()
{
	cout << "---------------Calculator: write 'end' to stop calculator---------------" << "\n";
	cout << "Binary or hexadecimal numbers can only be entered in lowercase letters" << "\n";
	while (1) {
		string input_string;
		cout << ">> ";
		getline(cin,input_string,'\n');
		char* input = new char[input_string.length()+1];
		strcpy(input, input_string.c_str());
		if (!strcmp(input, "end")) {
			cout << "---------------------------Calculator stop...---------------------------" << endl;
			break;
		}
		try {
			Calculator::instance()->set_input(input);
			cout << Calculator::instance()->get_result() << endl;
		}
		catch (exception& e) {
			cout << "Catch exception!" << "\n";
			cout << e.what() << endl;
		}
	}
	return 0;

}