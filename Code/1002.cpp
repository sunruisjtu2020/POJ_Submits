/*
*	Problem 1002 - 487-3279
*	http://poj.org/problem?id=1002
*	Date 3/29/2022
* 	Accepted
*	Sort - Bucket Sorting
*/

#include <cstdio>
#include <cstring>
#include <iostream>

const int MAX = 1e7;

int n, buc[MAX];
char str[233], len;

char convert(char ch) {
	if((ch >= '0' && ch <= '9') || ch == '-')
		return ch;
	if(ch >= 'A' && ch <= 'P')
		return (ch - 'A') / 3 + 2 + '0';
	if(ch >= 'R' && ch <= 'Y')
		return (ch - 'Q') / 3 + 7 + '0';
	return '!';
}

int main() {
	std::cin >> n;
	for(int i = 1; i <= n; ++i) {
		scanf("%s", str);
		int val = 0;
		len = strlen(str);
		for(int j = 0; j < len; ++j) {
			char ch = convert(str[j]);
			if(ch == '!' || ch == '-') continue;
			val = val * 10 + ch - '0';
		}
		++buc[val];
	}
	int tot = 0;
	for(int i = 0; i < MAX; ++i) {
		if(buc[i] > 1) {
			printf("%.3d-%.4d %d\n", i / 10000, i % 10000, buc[i]);
			++tot;
		}
	}
	if(tot == 0)
		printf("No duplicates.");
	return 0;
}