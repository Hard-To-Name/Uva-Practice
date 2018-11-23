#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int height, width;
	while (cin >> height >> width) {
		if (height == 0) break;
		int count = 0, h, temp;
		cin >> h;
		for (int i = 1; i < width; ++i) {
			cin >> temp;
			if (temp > h) count += temp - h;
			h = temp;
		}
		count += height - h;
		cout << count << endl;
	}
}
