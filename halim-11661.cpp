#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int length;
	while (cin >> length) {
		if (length == 0) break;
		char temp;
		getchar();
		int r = -1e9, d = -1e9, count = -1, minimum = 1e9;
		while (temp = getchar()) {
			count++;
			if (temp == 'R') {
				r = count;
				minimum = min(minimum, abs(r - d));
			}
			else if (temp == 'D') {
				d = count;
				minimum = min(minimum, abs(r - d));
			}
			else if (temp == 'Z') {
				minimum = 0;
			}
			else if (temp == '\n') {
				cout << minimum << endl;
				break;
			}
		}
	}
}
