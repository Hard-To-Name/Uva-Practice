#include<cstdio>
#include<cstring>
using namespace std;

struct Array {
	char name[10];
	int base;
	int size;
	int D;
	int upper[11];
	int lower[11];
	int C[11];
};

Array arrs[1000];
char name[10];

int main() {
	int n, r;
	scanf("%d%d\n", &n, &r);
	// read n array definitions
	for (int i = 0; i < n; ++i) {
		scanf("%s%d%d%d", &arrs[i].name, &arrs[i].base, &arrs[i].size, &arrs[i].D);
		for (int j = 1; j <= arrs[i].D; ++j) {
			scanf("%d%d", &arrs[i].lower[j], &arrs[i].upper[j]);
		}
		arrs[i].C[arrs[i].D] = arrs[i].size;
		int base = arrs[i].base - arrs[i].C[arrs[i].D] * arrs[i].lower[arrs[i].D];
		for (int j = arrs[i].D - 1; j > 0; --j) {
			arrs[i].C[j] = arrs[i].C[j + 1] * (arrs[i].upper[j + 1] - arrs[i].lower[j + 1] + 1);
			base -= arrs[i].C[j] * arrs[i].lower[j];
		}
		arrs[i].C[0] = base;
	}
	// read r array references
	for (int i = 0; i < r; ++i) {
		scanf("%s", &name);
		printf("%s[", name);
		int index = 0;
		while (index < 1000) {
			if (strcmp(arrs[index].name, name) == 0) break;
			index++;
		}
		int address = arrs[index].C[0];
		int temp;
		for (int j = 1; j <= arrs[index].D; ++j) {
			scanf("%d", &temp);
			address += temp * arrs[index].C[j];
			if (j != arrs[index].D) printf("%d, ", temp);
			else printf("%d] = %d\n", temp, address);
		}
	}
}
