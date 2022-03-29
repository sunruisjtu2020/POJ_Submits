/*
*	Problem 3461 - Oulipo
*	http://poj.org/problem?id=3461
*	Date 3/29/2022
* 	Accepted
*	Strings - KMP Substring Search
*/

#include <cstdio>
#include <cstring>

const int MAX = 1e6 + 5;

int n, ans;
int nxt[MAX];
char str[MAX], pat[MAX];

int main() {
	scanf("%d", &n);

	while(n--) {
		scanf("%s%s", pat, str);
		memset(nxt, 0, sizeof(nxt));
		int j = 0, lstr = strlen(str), lpat = strlen(pat);

		for(int i = 1; i <= lpat; ++i) {
			while(j != 0 && pat[i] != pat[j])
				j = nxt[j];
			if(pat[i] == pat[j])
				++j;
			nxt[i + 1] = j;
		}

		j = ans = 0;

		for(int i = 0; i <= lstr; ++i) {
			while(j != 0 && str[i] != pat[j])
				j = nxt[j];
			if(str[i] == pat[j])
				++j;
			if(j == lpat)
				++ans; // Find a match
		}

		printf("%d\n", ans);
	}
	return 0;
}