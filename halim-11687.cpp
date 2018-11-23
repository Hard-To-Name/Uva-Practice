#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		if (s == "END") break;
		int index = 1;
		while (s != "1") {
			int temp = s.size();
			s = to_string(temp);
			index++;
		}
		cout << index << endl;
	}
}
