#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m, fuse, count = 0;
	while (cin >> n >> m >> fuse) {
		if (n == 0) break;
		count += 1;
		vector<int> costs(n + 1, 0);
		vector<bool> on(n + 1, false);
		int current = 0, max_val = 0;
		for (int i = 1; i <= n; ++i) {
			int temp;
			cin >> temp;
			costs[i] = temp;
		}
		for (int i = 1; i <= m; ++i) {
			int temp;
			cin >> temp;
			if (on[temp] == false) {
				on[temp] = true;
				current += costs[temp];
				max_val = max(current, max_val);
			}
			else {
				on[temp] = false;
				current -= costs[temp];
			}
		}
		cout << "Sequence " << count << endl;
		if (max_val > fuse) {
			cout << "Fuse was blown." << endl;
		}
		else {
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max_val << " amperes." << endl;
		}
		cout << endl;
	}
}
