#include <iostream>
#include <vector>

int main() {
	int n(0), k(0), x(0), players(0);
	std::vector <int> a(51);
	std::cin >> n >> k;
	for (int i(0); i < n; i++) {
		std::cin >> a[i];
	}
	x = a[k - 1];
	for (int i(0); i < n; i++) {
		if (a[i] >= x && a[i] > 0) {
			players++;
		}
	}
	std::cout << players;
}