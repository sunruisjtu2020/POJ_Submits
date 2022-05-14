/*
*	Problem 1007 - DNA Sorting
*	http://poj.org/problem?id=1007
*	Date 3/30/2022
*	Accepted
*	Sort - Merge Sort
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

struct gene {
	char str[51];
	int w;
	gene() {
		w = 0;
	}
}a[101];

int rev_cnt, n, m;

void merge_sort(char* s, int l, int r) {
	if(l == r)
		return;
	int mid = (l + r) / 2;
	merge_sort(s, l, mid);
	merge_sort(s, mid + 1, r);
	int tot = r - l + 1;
	char tmp[tot];
	int x = l, y = mid + 1, i = 0;
	while(x <= mid || y <= r) {
		if(y > r || (x <= mid && s[x] <= s[y]))
			tmp[i++] = s[x++];
		else
			tmp[i++] = s[y++], rev_cnt += mid - x + 1;
	}
	x = l;
	for(int i = 0; i < tot; ++i)
		s[x++] = tmp[i];
}

void get_w(gene& t) {
	char str[51];
	memcpy(str, t.str, sizeof(t.str));
	rev_cnt = 0;
	merge_sort(str, 0, n - 1);
	t.w = rev_cnt;
}

bool cmp(const gene& a, const gene& b) {
	return a.w < b.w;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%s", a[i].str);
	for(int i = 1; i <= m; ++i)
		get_w(a[i]);
	std::sort(a + 1, a + m + 1, cmp);
	for(int i = 1; i <= m; ++i)
		printf("%s\n", a[i].str);
	return 0;
}
