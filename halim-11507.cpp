#include<iostream>
#include<string>
using namespace std;

int main() {
	int length;
	string temp;
	while (cin >> length) {
		if (length == 0) break;
		int y = 0, z = 0;
		char current = 'x';
		for (int i = 1; i < length; ++i) {
			cin >> temp;
			if (temp == "+z" && current != 'y') {
				z++;
				if (z % 2 == 0) current = 'x';
				else current = 'z';
			}
			else if (temp == "-z" && current != 'y') {
				z--;
				if (z % 2 == 0) current = 'x';
				else current = 'z';
			}
			else if (temp == "+y" && current != 'z') {
				y++;
				if (y % 2 == 0) current = 'x';
				else current = 'y';
			}
			else if (temp == "-y" && z % 2 == 0) {
				y--;
				if (y % 2 == 0) current = 'x';
				else current = 'y';
			}
		}
		if (current == 'x') {
			if ((y + z) % 4 == 0)
				cout << "+x" << endl;
			else cout << "-x" << endl;
		}
		else if (current == 'y') {
			if ((y + z) % 4 == 1 || (y + z) % 4 == -3)
				cout << "+y" << endl;
			else cout << "-y" << endl;
		}
		else if (current == 'z') {
			if ((y + z) % 4 == 1 || (y + z) % 4 == -3)
				cout << "+z" << endl;
			else cout << "-z" << endl;
		}
	}
}
