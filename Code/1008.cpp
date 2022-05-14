/*
*	Problem 1008 - Maya Calendar
*	http://poj.org/problem?id=1008
*	Date 4/1/2022
*	Accepted
*	Simulation
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
string habb[] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol",
		"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab",
		"cumhu", "uayet" };
string tzolkin[] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",
		"lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib",
		"caban", "eznab", "canac", "ahau" };
map<string, int> mapHabb;

int main() {
	for(int i = 0; i < 19; ++i)
		mapHabb[habb[i]] = i;
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", n);
	while(n--) {
		int yy, mm, dd;
		char ch;
		string mm_;
		cin >> dd >> ch >> mm_ >> yy;
		mm = mapHabb[mm_];
		int day_cnt = dd + 20 * mm + 365 * yy;
		int tzoyy, tzomm, tzodd;
		tzoyy = day_cnt / 260;
		int day_remain = day_cnt % 260;
		tzodd = day_remain % 13 + 1;
		tzomm = day_remain % 20;
		cout << tzodd << ' ' << tzolkin[tzomm] << ' ' << tzoyy << '\n';
	}
	return 0;
}
