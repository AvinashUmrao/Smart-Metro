// knapsack problem 

/*
Problem Title: Maximizing Metro Profit - Fractional Knapsack Problem (Greedy Approach)

Problem Statement:
------------------
You are in charge of a particular sector in the metro logistics system, responsible for 
sending goods from one location to another. You are provided with a transport bag that 
has a fixed weight capacity.

Each good has a specific weight and associated profit. Your task is to choose which goods 
to carry in the bag such that the **total profit is maximized**, keeping in mind that you 
can carry **fractions of goods** if needed.

Objective:
Maximize the total profit carried in the bag using a greedy method.

Approach:
---------
1. Calculate the profit-to-weight ratio for each good.
2. Sort the goods in decreasing order of this ratio.
3. Pick goods fully if possible.
4. If a good cannot be picked completely due to limited remaining capacity, take a fraction of it.

Example:
--------
Enter the number of goods: 3
Enter the capacity of the transport bag: 50
Enter the profit and weight of each good (profit weight):
Good 1: 100 20
Good 2: 60 10
Good 3: 120 30
Do you want to allow goods to be divided into fractions? (y/n): n
The maximum profit that can be obtained is: 160.00


Option "y" (Allow fractions): 
- Solves the fractional knapsack problem. 
- Goods can be divided into fractions to maximize profit. 
- The solution takes parts of goods if the remaining capacity doesn't fit the whole item, resulting in higher profit.

Option "n" (No fractions): 
- Solves the 0/1 knapsack problem. 
- You can only take whole goods. If an item can't fit entirely, it is excluded from the selection. 
- This results in a lower profit as compared to allowing fractions.
*/




#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
class Solution
{
public:
    static bool comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n, bool allowFraction)
    {
        sort(arr, arr + n, comp);

        int currentWeight = 0;
        double finalValue = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (currentWeight + arr[i].weight <= W)
            {
                currentWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else
            {
                int remain = W - currentWeight;

                if (allowFraction)
                {
                    finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                }

                // In 0/1 case, do not pick partially — just break.
                break;
            }
        }

        return finalValue;
    }
};

int main()
{
    int n;
    int capacity;

    cout << "Enter the number of goods: ";
    cin >> n;

    cout << "Enter the capacity of the transport bag: ";
    cin >> capacity;

    Item* items = new Item[n];

    cout << "Enter the profit and weight of each good (profit weight):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Good " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    char choice;
    cout << "Do you want to allow goods to be divided into fractions? (y/n): ";
    cin >> choice;

    bool allowFraction = (choice == 'y' || choice == 'Y');

    Solution obj;
    double maxValue = obj.fractionalKnapsack(capacity, items, n, allowFraction);

    cout << fixed << setprecision(2);
    cout << "The maximum profit that can be obtained is: " << maxValue << endl;

    delete[] items;

    return 0;
}



