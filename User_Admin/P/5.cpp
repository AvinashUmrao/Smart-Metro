/*
    Problem Statement:
   /shortest-job-first-or-sjf-cpu-scheduling Algorithm 

    In the Delhi Metro system, several trains require scheduled maintenance work.
    Each maintenance task takes a certain amount of time to complete.

    However, since there are only a limited number of maintenance crews,
    not all tasks can be performed simultaneously. Therefore, it is important
    to determine the optimal order in which to execute these tasks.

    The objective is to complete all tasks efficiently so that the overall
    waiting time is minimized and trains do not experience unnecessary delays.
    To achieve this, we use the strategy of performing shorter tasks first,
    as they finish quickly and reduce the waiting time for subsequent tasks.

    This problem can be modeled using the **Shortest Job First (SJF)**
    scheduling algorithm — a greedy approach that schedules tasks
    in order of increasing duration.

    Input:
        An array of durations representing the time required for each train task.

    Output:
        - Order of execution of train tasks.
        - Individual waiting times for each task.
        - Individual turnaround times for each task.
        - Average waiting time.
        - Average turnaround time.

    Example:

    Input:
        Train Durations: {6, 8, 7, 3}

    Output:
        Order of execution:    4 1 3 2
        Waiting times:         0 3 9 16
        Turnaround times:      3 9 16 24
        Average Waiting Time:  7.0
        Average Turnaround Time: 13.0

    Time Complexity: O(n log n) due to sorting
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Train
{
    int id;         // Train number
    int duration;   // Duration required to execute (like burst time)
};

// Comparison function to sort by duration
bool compareByDuration(Train a, Train b)
{
    return a.duration < b.duration;
}

void scheduleTrains(vector<int> &durations)
{
    int n = durations.size();
    vector<Train> trains(n);

    for (int i = 0; i < n; i++)
    {
        trains[i].id = i + 1;
        trains[i].duration = durations[i];
    }

    // Sort trains by duration (Shortest Job First)
    sort(trains.begin(), trains.end(), compareByDuration);

    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);

    // First train has 0 waiting time
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + trains[i - 1].duration;
    }

    double totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = waitingTime[i] + trains[i].duration;
        totalWaiting += waitingTime[i];
        totalTurnaround += turnaroundTime[i];
    }

    cout << "Order of execution (Train IDs): ";
    for (int i = 0; i < n; i++)
    {
        cout << trains[i].id << " ";
    }
    cout << endl;

    cout << "Waiting Times:      ";
    for (int i = 0; i < n; i++)
    {
        cout << waitingTime[i] << " ";
    }
    cout << endl;

    cout << "Turnaround Times:   ";
    for (int i = 0; i < n; i++)
    {
        cout << turnaroundTime[i] << " ";
    }
    cout << endl;

    cout << "Average Waiting Time: " << totalWaiting / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaround / n << endl;
}



int main()
{
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;

    vector<int> trainDurations(n);
    cout << "Enter the duration of each train task:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> trainDurations[i];
    }

    scheduleTrains(trainDurations);

    return 0;
}

// int main()
// {
//     // Example train durations (in minutes)
//     vector<int> trainDurations = {6, 8, 7, 3};

//     scheduleTrains(trainDurations);

//     return 0;
// }
