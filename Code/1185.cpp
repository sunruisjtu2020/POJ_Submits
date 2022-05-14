/*
*	Problem 1185 - Artillery Positions
*	http://poj.org/problem?id=1185
*	Date 3/29/2022
*	Accepted
*	Dynamic Planning - Status Compression
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

#define lbt(i) ((i) & (-(i)))
#define cbit(i) (1<<(i))
#define NUM 101
#define NUM2 80

int g[NUM], s[NUM], boom[NUM], f[NUM][NUM2][NUM2];
char str[12];
int n, m, ans;

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		memset(g, 0, sizeof(g));
		memset(s, 0, sizeof(s));
		memset(boom, 0, sizeof(boom));
		memset(f, 0, sizeof(f));

		for(int i = 1; i <= n; ++i) {
			scanf("%s", str);
			for(int j = 0; j < m; ++j) {
				g[i] *= 2;
				if(str[j] == 'H')
					++g[i];
			}
		}

		int bits = cbit(m), len = 1;

		for(int i = 0; i < bits; ++i) {
			if(!(i & (i << 1)) && !(i & (i << 2))) {
				int k = i, cnt = 0;
				for(; k > 0; k >>= 1)
					if(k & 1)
						++cnt;
				boom[len] = cnt;
				s[len++] = i;
			}
		}

		for(int i = 1; i < len; ++i) {
			if(!(g[1] & s[i]))
				f[1][i][1] = boom[i];
		}

		for(int i = 2; i <= n; ++i) {
			for(int j = 1; j < len; ++j) {
				if(s[j] & g[i])
					continue;
				for(int k = 1; k < len; ++k) {
					if(s[j] & s[k] || s[k] & g[i - 1])
						continue;
					for(int t = 1; t < len; ++t) {
						if(s[t] & s[j] || s[t] & s[k] || s[t] & g[i - 2])
							continue;
						f[i][j][k] = std::max(f[i][j][k], f[i - 1][k][t] + boom[j]);
					}
				}
			}
		}

		ans = -1;
		for(int i = 1; i < len; ++i)
			for(int j = 1; j < len; ++j)
				ans = std::max(ans, f[n][i][j]);

		printf("%d\n", ans);

	}

	return 0;
}
