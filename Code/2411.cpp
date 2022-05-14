/*
*	Problem 2411 - Mondriaan's Dream
*	http://poj.org/problem?id=2411
*	Date 3/29/2022
*	Accepted
*	Dynamic Planning - Status Compression
*/
#include <cstring>
#include <cstdio>

long long f[15][1 << 12];
int w, h, i, j;

void dfs(int now_grid, int status, int next_row) {
	if(now_grid == h) {
		// go to next row
		f[i + 1][next_row] += f[i][j];
		return;
	}
	if(status & 1<<now_grid) // if current grid is filled
		dfs(now_grid + 1, status, next_row); // go to next grid
	else {
		dfs(now_grid + 1, status | (1<<now_grid), next_row | (1<<now_grid)); // Vertical
		if((status & 1<<(now_grid + 1)) == 0 && now_grid + 1 < h) // if two neighboring grids are empty
			dfs(now_grid + 2, status | (1 << now_grid) | (1 << (now_grid + 1)), next_row); // Horizonal
	}
}

int main() {
	while(~scanf("%d%d", &w, &h) && w != 0) {
		memset(f, 0, sizeof(f));
		f[1][0] = 1;
		for(i = 1; i <= w; ++i)
			for(j = 0; j < 1 << h; ++j)
				if(f[i][j])
					dfs(0, j, 0);
		printf("%lld\n", f[w + 1][0]);
	}
	return 0;
}
