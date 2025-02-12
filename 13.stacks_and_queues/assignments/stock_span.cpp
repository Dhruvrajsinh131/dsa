#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(vector<int> &prices, int n)
{
    vector<int> span(n, 1);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && prices[s.top()] < prices[i])
        {
            s.pop();
        }

        span[i] = (s.empty()) ? (i + 1) : (i - s.top());
        s.push(i);
    }
    return span;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    vector<int> result = calculateSpan(prices, n);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
