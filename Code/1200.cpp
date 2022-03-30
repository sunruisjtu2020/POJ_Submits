/*
*	Problem 1200 - Crazy Search
*	http://poj.org/problem?id=1200
*	Date 3/30/2022
* 	Accepted
*	String - Hash
*/

#include <cstdio>
#include <cstring>

#define ull unsigned long long

const int MAXH = 16e6 + 1;
const int MAXS = 1e6 + 1;

bool isExist[MAXH];
int v[257], n, nc, ans, k;
char s[MAXS];

int main() {
	while(scanf("%d%d%s", &n, &nc, s) != EOF) {
		memset(isExist, 0, sizeof(isExist));
		ans = k = 0;
		int len = strlen(s);
		for(int i = 0; i < len; ++i)
			v[s[i]] = 1;
		for(int i = 0; i < 256; ++i)
			if(v[i])
				v[i] = k++;
		for(int i = 0; i + n <= len; ++i) {
			int hashCode = 0;
			for(int j = i; j < i + n; ++j)
				hashCode = hashCode * nc + v[s[j]];
			if(!isExist[hashCode]) {
				++ans;
				isExist[hashCode] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}