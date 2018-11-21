#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct proposal {
	string name;
	double price;
	int met_req;
	proposal(string n, double p, int m) {
		name = n;
		price = p;
		met_req = m;
	}
	bool operator < (proposal other) {
		return price < other.price;
	}
	bool operator == (proposal other) {
		return price == other.price;
	}
	bool operator > (proposal other) {
		return price > other.price;
	}
};

int main() {
	int r, n, count = 0;
	while (cin >> r >> n) {
		count++;
		if (r == 0) break;
		if (count > 1) cout << endl;
		string temp;
		for (int i = 0; i < r; ++i) {
			getline(cin, temp);
			if (temp == "") i--;
		}
		vector<proposal> ps;
		for (int i = 0; i < n; ++i) {
			getline(cin, temp);
			double money;
			int met;
			cin >> money >> met;
			ps.push_back(proposal(temp, money, met));
			for (int i = 0; i < met; ++i) {
				getline(cin, temp);
				if (temp == "") i--;
			}
		}

		sort(ps.begin(), ps.end());

		int max_idx = 0, max_met = ps[0].met_req;
		for (int i = 1; i < n; ++i) {
			if (max_met >= r) break;
			int cur_met = ps[i].met_req;
			if (cur_met > max_met) {
				max_idx = i;
				max_met = cur_met;
			}
		}
		cout << "RFP #" << count << endl;
		cout << ps[max_idx].name << endl;
	}
}
