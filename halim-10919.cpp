#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main() {
	int cor_num, cat_num;
	while (cin >> cor_num >> cat_num) {
		bool ans = true;
		unordered_set<string> courses;
		string temp;
		for (int i = 0; i < cor_num; ++i) {
			cin >> temp;
			courses.insert(temp);
		}
		int max_num, req_num;
		for (int i = 0; i < cat_num; ++i) {
			cin >> max_num >> req_num;
			for (int j = 0; j < max_num; ++j) {
				cin >> temp;
				if (ans && courses.find(temp) != courses.end())
					req_num--;
			}
			if (ans && req_num > 0) {
				ans = false;
			}
		}
		if (ans) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
