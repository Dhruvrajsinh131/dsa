#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumProfit(vector<int> &budgets, int n)
{
    // Step 1: Sort the budgets in ascending order
    sort(budgets.begin(), budgets.end());

    long long maxProfit = 0;

    // Step 2: Calculate profit for each price
    for (int i = 0; i < n; i++)
    {
        long long currentPrice = budgets[i];
        long long buyersCount = n - i; // Buyers who can afford the app
        long long currentProfit = currentPrice * buyersCount;

        // Step 3: Update the maximum profit
        if (currentProfit > maxProfit)
        {
            maxProfit = currentProfit;
        }
    }

    return maxProfit;
}

int main()
{
    int n;
    // Input number of buyers
    cin >> n;
    vector<int> budgets(n);

    // Input budgets of buyers
    for (int i = 0; i < n; i++)
    {
        cin >> budgets[i];
    }

    // Output the maximum profit
    cout << maximumProfit(budgets, n) << endl;

    return 0;
}
