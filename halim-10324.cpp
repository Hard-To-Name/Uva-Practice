#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string temp;
	int num = 0;
	while (cin >> temp) {
		if (temp.size() == 0) break;
		num++;
		cout << "Case " << num << ":" << endl;
		vector<int> counts(temp.size(), 0);
		int current = temp[0], consecutive = 0;
		for (int i = 0; i < temp.size(); ++i) {
			if (temp[i] == current) consecutive++;
			else {
				current = temp[i];
				consecutive = 1;
			}
			counts[i] = consecutive;
		}

		int queries;
		cin >> queries;
		for (int i = 0; i < queries; ++i) {
			int start, end;
			cin >> start >> end;
			if (end < start) swap(start, end);
			if (counts[end] > end - start)
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}
