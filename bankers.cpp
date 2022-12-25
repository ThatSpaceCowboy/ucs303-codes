#include <iostream>
using namespace std;
// Bankers algo consists of Safety Algo + Resource allocation algo
int main()
{
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;
    int available[m], max[n][m], allocation[n][m], need[n][m];
    cout << "\nEnter available array\n";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    cout << "\nEnter max matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }
    cout << "\nEnter allocation matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    cout << "\nNeed Matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }
    // Safety algorithm: Whether a system is in safe state or not
    // checking safe state
    int work[m], finish[n], safeSequence[n], idx = 0;
    for (int i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }
    while (true)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool flag = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                    safeSequence[idx++] = i;
                    break;
                }
            }
        }
        if (!found)
        {
            break;
        }
    }
    bool safe = true;
    for (int i = 0; i < m; i++)
    {
        if (!finish[i])
        {
            safe = false;
            break;
        }
    }
    if (safe)
    {
        cout << "\nSafe state\n";
        for (idx = 0; idx < n; idx++)
        {
            cout << safeSequence[idx] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "\nUnsafe state\n";
    }
    return 0;
}