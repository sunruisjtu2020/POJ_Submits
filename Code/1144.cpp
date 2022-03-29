/*
*	Problem 1144 - Network
*	http://poj.org/problem?id=1144
*	Date 3/29/2022
* 	Accepted
*	Graph Theory - Tarjan Algorithm
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 105;

int n, m, top, tot, ans;
int dfn[MAX], low[MAX], f[MAX], h[MAX], fuc[MAX];

struct edge {
	int nxt, to;
}e[MAX * MAX];

inline void add_edge(int u, int v) {
	e[++tot] = (edge){h[u], v};
	h[u] = tot;
	e[++tot] = (edge){h[v], u};
	h[v] = tot;
}

void dfs(int x) {
	int rec = 0;
	dfn[x] = low[x] = ++dfn[0]; // dfn[0] works as a clock
	for(int i = h[x]; i; i = e[i].nxt) {
		if(!dfn[e[i].to]) {
			f[e[i].to] = f[x];
			dfs(e[i].to);
			low[x] = std::min(low[x], low[e[i].to]);
			if(low[e[i].to] >= dfn[x] && x != f[x])
				fuc[x] = 1;
			if(x == f[x])
				++rec;
		}
		low[x] = std::min(low[x], dfn[e[i].to]);
	}
	if(x == f[x] && rec >= 2)
		fuc[f[x]] = 1;
}

int main() {
	while(scanf("%d", &n) && n) {
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(h, 0, sizeof(h));
		memset(fuc, 0, sizeof(fuc));
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= tot; ++i)
			e[i] = (edge) {0, 0};
		tot = ans = 0;
		for(int i = 1; i <= n; ++i)
			f[i] = i;
		int x, y;
		while(scanf("%d", &x) && x)
			while(getchar() != '\n') {
				scanf("%d", &y);
				add_edge(x, y);
			}
		for(int i = 1; i <= n; ++i)
			if(!dfn[i])
				dfs(i);
		for(int i = 1; i <= n; ++i)
			if(fuc[i])
				++ans;
		printf("%d\n", ans);
	}
}