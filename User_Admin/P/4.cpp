/*

Minimum number of platforms required for a railway

    Problem Statement:
    The metro system operates several trains that arrive and depart at different times. 
    We are given two arrays representing arrival and departure times of N trains. 
    We need to calculate the minimum number of platforms required at the station 
    so that no train has to wait for a platform to become free.

    Example 1:
    Input:
        N = 6
        Arrival Times:    {900, 945, 955, 1100, 1500, 1800}
        Departure Times:  {920, 1200, 1130, 1150, 1900, 2000}
    Output:3

    Explanation:
        At 11:00 AM, the train arrives but the ones that came at 9:45 and 9:55 haven't yet departed. 
        Hence, we need at least 3 platforms at that moment.


The first train departs before the second one arrives. Only one platform is sufficient.
Do you want to enter custom values? Enter 1 for Yes or 0 for No: 1
Enter the number of trains: 6
Enter the arrival times: 900 945 955 1100 1500 1800
Enter the departure times: 920 1200 1130 1150 1900 2000
Minimum number of platforms required = 3

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Function to count minimum number of platforms required
int countPlatforms(int n, int arr[], int dep[])
{
    int ans = 1; // Final answer
    for (int i = 0; i < n; i++)
    {
        int count = 1; // Count overlapping intervals
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] >= arr[j] && arr[i] <= dep[j]) ||
                (arr[j] >= arr[i] && arr[j] <= dep[i]))
            {
                count++;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}


int main()
{
    int choice;
    cout << "Do you want to enter custom values? Enter 1 for Yes or 0 for No: ";
    cin >> choice;

    if (choice == 1)
    {
        int n;
        cout << "Enter the number of trains: ";
        cin >> n;

        int arr[n], dep[n];

        cout << "Enter the arrival times: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << "Enter the departure times: ";
        for (int i = 0; i < n; i++)
        {
            cin >> dep[i];
        }

        int result = countPlatforms(n, arr, dep);
        cout << "Minimum number of platforms required = " << result << endl;
    }
    else
    {
        // Default values
        int arr[] = {900, 945, 955, 1100, 1500, 1800};
        int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
        int n = sizeof(arr) / sizeof(arr[0]);

        int result = countPlatforms(n, arr, dep);
        cout << "Minimum number of platforms required = " << result << endl;
    }

    return 0;
}
