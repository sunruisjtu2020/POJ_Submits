/*
*	Problem 1003 - Hangover
*	http://poj.org/problem?id=1003
*	Date 3/30/2022
* 	Accepted
*	MATH - Floating Numbers
*/

#include <cstdio>
#include <cmath>

int main() {
	double c = 0.0;
	while(true) {
		scanf("%lf", &c);
		if(c == 0)
			break;
		double tot = 0.0;
		int i = 0;
		for(i = 2; tot < c; ++i)
			tot += 1.0 / i;
		printf("%d card(s)\n", i - 2);
	}
	return 0;
}