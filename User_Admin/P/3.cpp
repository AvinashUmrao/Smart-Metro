/*
Problem Statement:
You are given an integer array ranks representing the ranks of some mechanics. ranks[i] is the rank of the ith mechanic. A mechanic with a rank r can repair n trains in r * n² minutes.
You are also given an integer trains representing the total number of trains waiting in the garage to be repaired.
Return the minimum time taken to repair all the trains.
Note: All the mechanics can repair the trains simultaneously.



Example 1:
Enter the number of mechanics: 4
Enter the ranks of the mechanics: 4 2 3 1
Enter the total number of trains: 10
//1-> least time , 2-> more time 3-> more then 2nd one similarly 4-> more then 3rd one 


Input: ranks = [4, 2, 3, 1]    trains = 10

Output:16

Explanation:
The first mechanic will repair two trains. The time required is 4 * 2 * 2 = 16 minutes.
The second mechanic will repair two trains. The time required is 2 * 2 * 2 = 8 minutes.
The third mechanic will repair two trains. The time required is 3 * 2 * 2 = 12 minutes.
The fourth mechanic will repair four trains. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the trains cannot be repaired in less than 16 minutes.

*/

#include <bits/stdc++.h>
using namespace std;

class TrainMaintenance
{
public:
    typedef long long ll;

    // Check if it's possible to fix all trains within 'mid' time
    bool isPossible(vector<int> &ranks, ll mid, int totalTrains)
    {
        ll trainsMaintained = 0;

        for (int i = 0; i < ranks.size(); i++)
        {
            // Max trains a crew of rank r can maintain within 'mid' time
            // Time = r * t^2 => t = sqrt(mid / r)
            trainsMaintained += (ll)sqrt(mid / (long double)ranks[i]);
        }

        return trainsMaintained >= totalTrains;
    }

    // Binary search to find minimum time to maintain all trains
    ll minimumTimeToMaintain(vector<int> &ranks, int trains)
    {
        ll left = 1;
        ll right = 1LL * (*min_element(ranks.begin(), ranks.end())) * trains * trains;
        ll result = right;

        while (left <= right)
        {
            ll mid = left + (right - left) / 2;

            if (isPossible(ranks, mid, trains))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }
};

int main()
{
    int totalTrains;
    int n;

    // Input the number of mechanics
    cout << "Enter the number of mechanics: ";
    cin >> n;

    vector<int> crewRanks(n);

    // Input the ranks of the mechanics
    cout << "Enter the ranks of the mechanics: ";
    for (int i = 0; i < n; i++)
    {
        cin >> crewRanks[i];
    }

    // Input the total number of trains to be maintained
    cout << "Enter the total number of trains: ";
    cin >> totalTrains;

    TrainMaintenance metro;
    long long minTime = metro.minimumTimeToMaintain(crewRanks, totalTrains);

    cout << "Minimum time to maintain all trains: " << minTime << endl;

    return 0;
}
