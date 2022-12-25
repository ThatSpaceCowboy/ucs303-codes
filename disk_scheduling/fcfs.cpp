#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int head;
    cin >> head;
    int ent;
    cin >> ent;
    int arr[ent];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int t = 0;
    t = abs(head - arr[0]);
    for (int i = 1; i < ent; i++)
    {
        t = t + abs(arr[i] - arr[i - 1]);
    }
    cout << t;
}
