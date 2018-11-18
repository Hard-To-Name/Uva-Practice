#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	bool flag = false;
	while (cin >> num) {
		map<string, int> list;
		vector<string> names;
		string name;
		int money, people;
		for (int i = 0; i < num; ++i) {
			cin >> name;
			list[name] = 0;
			names.push_back(name);
		}
		for (int i = 0; i < num; ++i) {
			cin >> name;
			cin >> money >> people;
			list[name] -= money;
			if (people == 0) {
				list[name] += money;
			}
			else {
				list[name] += money % people;
				for (int j = 0; j < people; ++j) {
					cin >> name;
					list[name] += money / people;
				}
			}
		}
		if (flag) cout << endl;
		for (int i = 0; i < num; ++i) {
			cout << names[i] << " " << list[names[i]] << endl;
		}
		flag = true;
	}
}
