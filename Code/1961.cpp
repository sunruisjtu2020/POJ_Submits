/*
*	Problem 1961 - Period
*	http://poj.org/problem?id=1961
*	Date 3/30/2022
* 	Accepted
*	String - KMP Substring Search
*/

#include <cstdio>
#include <cstring>

const int MAXS = 1 << 20;

char s[MAXS];
int nxt[MAXS], l, t;
int main() {
	while(scanf("%d", &l), l) {
		printf("Test case #%d\n", ++t);
		scanf("%s", s);
		memset(nxt, 0, sizeof(nxt));
		for(int i = 1, j = 0; i <= l; ++i) {
			while(j && s[i] != s[j])
				j = nxt[j];
			if(s[i] == s[j])
				++j;
			nxt[i + 1] = j;
		}
		for(int i = 1; i <= l; ++i)
			if(i % (i - nxt[i]) == 0 && i / (i - nxt[i]) != 1)
				printf("%d %d\n", i, i / (i - nxt[i]));
		printf("\n");
	}
	return 0;
}