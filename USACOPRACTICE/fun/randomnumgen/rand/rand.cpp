#include <random>
#include <iostream>
#include <functional>
using namespace std;
default_random_engine re;   // the default engine
normal_distribution<int> nd(31 /* mean */, 8 /* sigma */);

auto norm = std::bind(nd, re);

vector<int> mn(64);

int main()
{
	for (int i = 0; i < 1200; ++i) ++mn[round(norm())]; // generate

	for (int i = 0; i < mn.size(); ++i) {
		cout << i << '\t';
		for (int j = 0; j < mn[i]; ++j) cout << '*';
		cout << '\n';
	}
}