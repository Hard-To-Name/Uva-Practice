#include<cstdio>

int prime[169] = { 0 };

bool is_prime(int n) {
	for (int i = 3; i * i <= n; i = i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}

void find_prime() {
	prime[0] = 1;
	prime[1] = 2;
	int cur = 2;
	for (int i = 3; i < 1000; i = i + 2) {
		if (is_prime(i)) {
			prime[cur] = i;
			cur++;
		}
	}
}

int binary_search(int val, int l, int r) {
	if (r >= l) {
		int mid = (l + r) / 2;
		if (prime[mid] == val) {
			return mid;
		}
		if (prime[mid] > val) {
			return binary_search(val, l, mid - 1);
		}
		return binary_search(val, mid + 1, r);
	}
	if (prime[r] > val) return r - 1;
	else return r;
}

int main() {
	find_prime();
	int n, c;
	while (scanf("%d%d", &n, &c) == 2) {
		int index = binary_search(n, 0, 168);
		int start = index / 2, end;
		if (index % 2 == 0) {
			end = start;
		}
		else end = start + 1;
		start -= c - 1;
		end += c - 1;
		if (start < 0) start = 0;
		if (end > index) end = index;
		printf("%d %d:", n, c);
		for (int i = start; i <= end; ++i) {
			printf(" %d", prime[i]);
		}
		printf("\n\n");
	}
}
