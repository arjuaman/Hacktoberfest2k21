#include <iostream>
#include <string>
#include <climits>
using namespace std;
int rodCut(int price[], int n)
{
    if (n == 0) {
        return 0;
    }
    int maxValue = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int cost = price[i - 1] + rodCut(price, n - i);
        if (cost > maxValue) {
            maxValue = cost;
        }
    }
    return maxValue;
}
int main()
{
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = 4;
    cout << "Profit is " << rodCut(price, n);
    return 0;
}
