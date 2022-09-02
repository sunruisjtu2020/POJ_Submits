/*
*	Problem 1067 - 取石子游戏
*	http://poj.org/problem?id=1067
*	Date 9/2/2022
*	Accepted
*   Wythoff Game
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

int a, b;

int main(int argc, char* argv[]) {
    while(scanf("%d%d", &a, &b) != EOF) {
        if(a > b)
            std::swap(a, b);
        int k = b - a;
        int c = (int)((1 + sqrt(5.0)) / 2 * k);
        printf("%d\n", c == a ? 0 : 1);
    }
    return 0;
}
