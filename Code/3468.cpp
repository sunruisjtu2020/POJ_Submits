/*
*	Problem 3468 - A Simple Problem with Integers
*	http://poj.org/problem?id=3468
*	Date 3/29/2022
* 	Accepted
*	Data Structure - Simple Segment Tree
*/

#include <cstdio>
#include <algorithm>

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
#define ll long long

const int MAX = 1e6 + 5;

ll add[MAX << 2], sum[MAX << 2], val;

void push_up(int rt) {
	sum[rt] = sum[ls] + sum[rs];
}

void push_down(int rt, int m) {
	// push tag to sons
	if(add[rt]) {
		add[ls] += add[rt];
		add[rs] += add[rt];
		sum[ls] += add[rt] * (m - (m >> 1));
		sum[rs] += add[rt] * (m >> 1);
		add[rt] = 0;
	}
}

void build_tree(int l, int r, int rt) {
	add[rt] = 0;
	if(l == r) {
		scanf("%lld", &sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build_tree(lson);
	build_tree(rson);
	push_up(rt);
}

void update(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		add[rt] += c;
		sum[rt] += (ll)c * (r - l + 1);
		return;
	}
	push_down(rt, r - l + 1);
	int m = (l + r) >> 1;
	if(L <= m) update(L, R, c, lson);
	if(m < R) update(L, R, c, rson);
	push_up(rt);
}

ll query(int L, int R, int l, int r, int rt) {
	if(L <= l && r <= R)
		return sum[rt];
	push_down(rt, r - l + 1);
	int m = (l + r) >> 1;
	ll res = 0;
	if(L <= m) res += query(L, R, lson);
	if(m < R) res += query(L, R, rson);
	return res;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	build_tree(1, n, 1);
	while(q--) {
		char op[2];
		int a, b, c;
		scanf("%s", op);
		if(op[0] == 'Q') {
			scanf("%d%d", &a, &b);
			printf("%lld\n", query(a, b, 1, n, 1));
		} else {
			scanf("%d%d%d", &a, &b, &c);
			update(a, b, c, 1, n, 1);
		}
	}
	return 0;
}