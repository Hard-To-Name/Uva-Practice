#include<stdio.h>
#include<string>
using namespace std;

int main() {
	int num;
	scanf("%d\n", &num);
	for (int i = 1; i <= num; ++i) {
		int memory[100] = { 0 };
		char temp;
		int cursor = 0;
		while (temp = getchar()) {
			if (temp == '+') {
				memory[cursor]++;
				memory[cursor] %= 256;
			}
			else if (temp == '-') {
				memory[cursor]--;
				if (memory[cursor] < 0) memory[cursor] = 255;
			}
			else if (temp == '>') {
				cursor++;
				cursor %= 100;
			}
			else if (temp == '<') {
				cursor--;
				if (cursor < 0) cursor = 99;
			}
			else if (temp == '\n') break;
		}
		printf("Case %d:", i);
		for (int j = 0; j < 100; ++j) {
			printf(" %02X", memory[j]);
		}
		printf("\n");
	}
}
