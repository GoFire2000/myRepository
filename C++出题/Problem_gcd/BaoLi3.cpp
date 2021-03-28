#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, q;

long long a[maxn];
long long g[maxn];

int main(){
	freopen("test19.in","r",stdin);
	freopen("test.out","w",stdout);
	int i, j;
	long long x, d = 0;
	
	scanf("%d%d", &n, &q);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	
	g[n] = abs(a[n]);
	
	for(i=n-1;i>0;i--){
		g[i] = __gcd(g[i + 1], abs(a[i]));
	}
	
	while(q--){
		scanf("%lld", &x);
		d += x;
		long long ans = abs(a[1] + d);
		
		for(i=2;i<=n;i++){
			ans = __gcd(ans, abs(a[i] + d));
			if(ans and d % ans == 0 and g[i + 1] % ans == 0) break;
		}
		
		printf("%lld\n", ans);
	}
	
	return 0;
}
