#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

double calculate(string s) {
	int temp = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (!isalpha(s[i])) continue;
		temp += toupper(s[i]) - 'A' + 1;
	}
	while (temp >= 10) {
		int new_temp = 0;
		while (temp > 0) {
			new_temp += temp % 10;
			temp /= 10;
		}
		temp = new_temp;
	}
	return temp;
}

int main() {
	string first, second;
	while (getline(cin, first)) {
		getline(cin, second);
		double n1 = calculate(first);
		double n2 = calculate(second);
		double ans1 = 100 * n2 / n1;
		double ans2 = 100 * n1 / n2;
		if (ans1 >= 100) printf("%.2f %%\n", ans2);
		else {
			printf("%.2f %%\n", ans1);
		}
	}
}
