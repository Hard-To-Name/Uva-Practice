#include<iostream>
using namespace std;

int main() {
	double h, u, d, f;
	while (cin >> h >> u >> d >> f) {
		if (h == 0) break;
		int original = h, day = 0;
		bool success;
		f = u * f / 100;
		while (++day) {
			if (u > 0) h -= u;
			if (h < 0) {
				success = true;
				break;
			}
			h += d;
			if (h > original) {
				success = false;
				break;
			}
			u -= f;
		}
		if (success) cout << "success on day " << day << endl;
		else cout << "failure on day " << day << endl;
	}
}
