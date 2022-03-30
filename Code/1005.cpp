/*
*	Problem 1005 - I Think I Need a Houseboat
*	http://poj.org/problem?id=1005
*	Date 3/30/2022
* 	Accepted
*	MATH - Floating Numbers
*/

#include <cstdio>
#include <cmath>

const double pi = 3.14159265358979;

int n;
double x, y;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &x, &y);
		double r2 = x * x + y * y;
		double area = pi * r2 / 2;
		int ans = ceil(area / 50);
		printf("Property %d: This property will begin eroding in year %d.\n", i, ans);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}