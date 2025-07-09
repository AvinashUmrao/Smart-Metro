


#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
Given a list of ad revenues for each time slot on a metro platform,
select non-consecutive slots to maximize total ad revenue.
You cannot select two consecutive slots.
Use in Metro System	Select optimal ad slots to prevent screen damage and maximize profit 
we cant play 2 ad one after the other 

Example:
Input:  {5, 1, 1, 5}
Output: 10  // slots 0 and 3 selected


*/

int maxAdRevenue(vector<int> &revenue)
{
    int n = revenue.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return revenue[0];

    vector<int> dp(n);
    dp[0] = revenue[0];
    dp[1] = max(revenue[0], revenue[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + revenue[i]);
    }

    return dp[n - 1];
}

int main()
{
    int n;
    cout << "Enter number of ad time slots: ";
    cin >> n;

    vector<int> revenue(n);
    cout << "Enter revenue for each time slot:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> revenue[i];
    }

    int maxRevenue = maxAdRevenue(revenue);
    cout << "Maximum revenue by scheduling ads: " << maxRevenue << endl;

    return 0;
}


/*
Enter number of ad time slots: 6
Enter revenue for each time slot:
3 2 7 10 12 7

Optimal Slot Selection:
Choose slot 0 → revenue = 3

Skip 1

Choose slot 2 → +7 = 10

Skip 3

Choose slot 4 → +12 = 22

Slots selected: 0, 2, 4 (all non-adjacent)
Total revenue: 3 + 7 + 12 = 22
*/