#include <iostream>
using namespace std;

int main()
{
    int mode;
    int choice;

    do
    {
        cout << "\n========= Delhi Metro System - Access Mode =========\n";
        cout << "1. Enter as User\n";
        cout << "2. Enter as Admin\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> mode;

        switch (mode)
        {
        case 1:
            do
            {
                cout << "\n========= User Mode =========\n\n";
                cout << "1. Carrying Goods for maximum profit  \n";//Fractional Knapsack (1.cpp)
                cout << "0. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "\nCompiling and running 1.cpp (Fractional Knapsack)...\n";
                    system("g++ P/1.cpp -o a.exe && a.exe");
                    break;
                case 0:
                    cout << "\nReturning to main menu...\n";
                    break;

                default:
                    cout << "\nInvalid choice in User Mode. Try again.\n";
                    break;
                }

            } while (choice != 0);
            break;

            case 2:
            do
            {
                cout << "\n========= Admin Mode =========\n\n";
                cout << "1. Compressing the data\n";       // Huffman Coding (2.cpp)
                cout << "2. Assign trains to mechanics to minimize total maintenance time based on their efficiency ranks.\n"; // Mechanic Repair Time (3.cpp)
                cout << "3. Calculate Minimum Number of Platforms\n";                      // Minimum Number of Platforms (4.cpp)
                cout << "4. Schedule shorter maintenance tasks first to minimize overall delays.\n"; // SJF Shortest Job First (5.cpp)
                cout << "5. Verify metro ticket codes against a stored database during gate scans, ensuring efficient passenger flow\n"; // String Matching (6.cpp)
                cout << "6. Optimize ad scheduling on metro screens to maximize revenue while avoiding consecutive slots\n"; // Advertisement Revenue (7.cpp)
                cout << "7. Optimizing Train Schedules by finding the maximum Flow of Trains\n"; // Network Flow (9.cpp)
                cout << "0. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;
        
                switch (choice)
                {
                case 1:
                    cout << "\nCompiling and running 2.cpp (Huffman Coding)...\n";
                    system("g++ P/2.cpp -o a.exe && a.exe");
                    break;
        
                case 2:
                    cout << "\nCompiling and running 3.cpp (Mechanic Repair Time)...\n";
                    system("g++ P/3.cpp -o a.exe && a.exe");
                    break;
        
                case 3:
                    cout << "\nCompiling and running 4.cpp (Minimum Number of Platforms)...\n";
                    system("g++ P/4.cpp -o a.exe && a.exe");
                    break;
        
                case 4:
                    cout << "\nCompiling and running 5.cpp (SJF Shortest Job First)...\n";
                    system("g++ P/5.cpp -o a.exe && a.exe");
                    break;
        
                case 5:
                    cout << "\nCompiling and running 6.cpp (String Matching)...\n";
                    system("g++ P/6.cpp -o a.exe && a.exe");
                    break;
        
                case 6:
                    cout << "\nCompiling and running 7.cpp (Advertisement Revenue)...\n";
                    system("g++ P/7.cpp -o a.exe && a.exe");
                    break;
        
                case 7:
                    cout << "\nCompiling and running 9.cpp (Network Flow)...\n";
                    system("g++ P/9.cpp -o a.exe && a.exe");
                    break;
        
                case 0:
                    cout << "\nReturning to main menu...\n";
                    break;
        
                default:
                    cout << "\nInvalid choice in Admin Mode. Try again.\n";
                    break;
                }
        
            } while (choice != 0);
            break;
        

        case 0:
            cout << "\nExiting the system. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid mode selected. Try again.\n";
            break;
        }

    } while (mode != 0);

    return 0;
}
