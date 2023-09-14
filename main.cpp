#include<iostream>
#include<climits>

using namespace std;

#define lli unsigned long long int

lli b = 0, s = 0, c = 0, nb, ns, nc, pb, ps, pc;

lli P(lli n) {
	return 	  (n * b > nb) * (n * b - nb) * pb 
			+ (n * c > nc) * (n * c - nc) * pc 
			+ (n * s > ns) * (n * s - ns) * ps;
}
int main() {
	char p;
	while (cin.get(p) && p != '\n') {
		(p == 'B') ? b++ : ((p == 'S') ? s++ : c++);
	}

	cin >> nb >> ns >> nc >> pb >> ps >> pc;

	lli r;
	cin >> r;

	lli low = 0;
	lli hi = LLONG_MAX;

	while (low <= hi) {
		lli mid = (low + hi) >> 1;
		lli pr = P(mid);

		if (pr == r) {
			cout << mid;
			return 0;
		}
		if (pr < r) {
			low = mid + 1;
		}
		else {
			hi = mid - 1;
		}

		cerr << r << ' ' << pr << ' ' << low << ' ' << hi << '\n';
	}
	cout << hi;
}
