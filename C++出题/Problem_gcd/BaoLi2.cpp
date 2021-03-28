#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1110000;
long long a[maxn];
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	freopen("test19.in","r",stdin);
	freopen("test.out","w",stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	random_shuffle(a + 1, a + n + 1);
	map<long long, long long> ans;
	long long t = 0;
	while (m--) {
		long long d;
		scanf("%lld", &d);
		t += d;
		if (ans.count(t)) {
			printf("%lld\n", ans[t]);
			continue;
		}
		long long r = abs(a[1] + t);
		for (int i = 2; i <= n && r != 1; ++i) if (a[i] + t != 0) {
			r = gcd(r, abs(a[i] + t));
		}
		ans[t] = r;
		printf("%lld\n", r);
	}
	return 0;
}
