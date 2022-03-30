/*
*	Problem 1006 - Biorhythms
*	http://poj.org/problem?id=1006
*	Date 3/30/2022
* 	Accepted
*	Math - China Remaining Theory
*/

#include <cstdio>

#define ll long long

ll exgcd(ll a, ll b, ll& x, ll& y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll r = exgcd(b, a % b, x, y);
	ll t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int c;
int m[3] = {23, 28, 33};
ll M = 1, r[3];

int main() {
	for(int i = 0; i < 3; ++i)
		M *= m[i];
	while(1) {
		++c;
		long long d, ans = 0;
		for(int i =0; i < 3; ++i)
			scanf("%lld", r + i);
		scanf("%lld", &d);
		if(d == -1)
			return 0;
		for(int i = 0; i < 3; ++i) {
			ll n = M / m[i], x = 0, y = 0;
			exgcd(n, m[i], x, y);
			x *= n;
			x %= M;
			ans += x * r[i];
			ans %= M;
		}
		ans -= d;
		ans %= M;
		ans += M;
		ans %= M;
		ans = ans == 0 ? M : ans;
		printf("Case %d: the next triple peak occurs in %lld days.\n", c, ans);
	}
	return 0;
}