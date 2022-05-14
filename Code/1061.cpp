/*
*	Problem 1061 - The Date of Frogs
*	http://poj.org/problem?id=1061
*	Date 3/29/2022
*	Accepted
*	Math - Extended GCD
*/
#include <cstdio>

typedef long long ll;

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

int main() {
	ll x, y, m, n, l, x0, y0, gcd, r;
	while(scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l) != EOF) {
		gcd = exgcd(n - m, l, x0, y0);
		r = l / gcd;
		if((x - y) % gcd != 0) {
			printf("Impossible\n");
			break;
		} else {
			printf("%lld\n", ((x - y) / gcd * x0 % r + r) % r);
		}
	}
	return 0;
}
