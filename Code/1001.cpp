/*
*	Problem 1001 - Exponentiation
*	http://poj.org/problem?id=1001
*	Date 3/29/2022
* 	Accepted
*	High precision calculations
*/
#include <cstdio>
#include <iostream>

char real[7];
int n, dot, len, r;
int a[160];

int main() {
	while(std::cin >> real >> n) {
		dot = -1;
		len = r = 0;
		int j = 4;
		for(int i = 0; i <= 5; ++i) {
			if(real[i] != '.')
				a[j--] = real[i] - '0'; // save base
			else
				dot = 5 - i; // mark the position of dot
		}
		len = 5;
		r = 0;
		for(int i = 4; i >= 0; --i)
			r = r * 10 + a[i];
		for(int i = 1; i < n; ++i) {
			int val = 0;
			for(int j = 0; j < len; ++j) {
				a[j] *= r;
				a[j] += val;
				val = a[j] / 10;
				a[j] %= 10;
			}
			for(; val != 0; val /= 10)
				a[len++] = val % 10;
		}
		int start = 0, dotn = dot * n;
		// Remove Leading Zeros
		for(int i = 0; i < len; ++i) {
			if(dotn == start || a[i] != 0)
				break;
			++start;
		}
		// Remove Backward Zeros
		for(int i = len - 1; i >= 0; --i) {
			if(a[i] != 0)
				break;
			--len;
		}
		while(dotn > len)
			a[len++] = 0;
		for(int i = len - 1; i >= start; --i) {
			if(dotn - 1 == i)
				std::cout << '.';
			std::cout << a[i];
		}
		std::cout << '\n';
	}
	return 0;
}