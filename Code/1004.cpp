/*
*	Problem 1004 - Financial Management
*	http://poj.org/problem?id=1004
*	Date 3/30/2022
* 	Accepted
*	MATH - Floating Numbers
*/

#include <cstdio>
#include <iostream>

int main() {
	double sum = 0, x;
	int cnt = 0;
	while(std::cin >> x) {
		++cnt;
		sum += x;
	}
	printf("$%.2f\n", sum / cnt);
	return 0;
}