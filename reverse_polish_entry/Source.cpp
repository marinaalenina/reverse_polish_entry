#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


class my_PAW {
private:
	char* symbol;
public:
	my_PAW(char* s) {
		cout << "Constructor: " << endl;
		symbol = new char[strlen(s) + 1];
		strcpy(symbol, s);
	}

	void show() {
		cout << symbol << endl;
	}

	char* postfix() {
		int len = strlen(symbol);
		char* stroka = new char[len + 1];
		char* tmp = new char[len + 1];
		int istroka = 0, itmp = 0;
		for (int i = 0; i < len; i++) {
			if (symbol[i] >= '0' && symbol[i] <= '9') {
				stroka[istroka++] = symbol[i];
			}
			else {
				if (symbol[i] == ')') {
					stroka[istroka++] = tmp[--itmp];
				}
				else if (symbol[i] != '(') {
					tmp[itmp++] = symbol[i];
				}
			}
		}
		stroka[istroka] = '\0';
		return stroka;
	}
};

int calculate(string str) {
	vector<int> val_vect;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i]))
			val_vect.push_back((int)(str[i] - '0'));
		else {
			int el = val_vect[val_vect.size() - 1];
			val_vect.pop_back();
			switch (str[i]) {
			case '+': val_vect[val_vect.size() - 1] += el;
				break;
			case '-': val_vect[val_vect.size() - 1] -= el;
				break;
			case '*': val_vect[val_vect.size() - 1] *= el;
				break;
			case '/': val_vect[val_vect.size() - 1] /= el;
				break;
			default:cout << "Error" << endl;
			}
		}
	}
	return val_vect[0];
}


int main() {
	char* stroka = new char[128];

	cout << "Input PAW:" << endl;
	cin >> stroka;

	my_PAW str1(stroka);
	str1.show();

	stroka = str1.postfix();
	cout << "Reverse polish entry:\t" << stroka << endl;

	int res = calculate(stroka);
	cout << "Result:\t" << res << endl;

	return 0;
}
