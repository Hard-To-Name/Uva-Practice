#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; ++i) {
		char temp;
		int f = 0, m = 0;
		while (temp = getchar()) {
			if (temp == 'F') f++;
			else if (temp == 'M') m++;
			else if (temp == '\n') {
				if (f == m && f > 1) printf("LOOP\n");
				else printf("NO LOOP\n");
				break;
			}
		}
	}
}
