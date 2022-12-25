#include <iostream>
using namespace std;
void bestFit(int *prSize, int *holes, int n, int m)
{
    int bfit[n];
    for (int i = 0; i < n; i++)
    {
        int space = -1;
        for (int j = 0; j < m; j++)
        {
            if (prSize[i] <= holes[j] && (space == -1 || holes[j] < holes[space]))
            {
                space = j;
            }
        }
        if (space == -1)
        {
            bfit[i] = -1;
        }
        else
        {
            bfit[i] = space;
            holes[space] -= prSize[i];
        }
    }
    cout << "Best fit\n";
    for (int i = 0; i < n; i++)
    {
        cout << bfit[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int prSize[n];
    cout << "Enter process size: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prSize[i];
    }
    int m;
    cout << "Enter number of holes: ";
    cin >> m;
    int holes[m];
    for (int i = 0; i < m; i++)
    {
        cin >> holes[i];
    }
    int tPrSize[n], tHoles[m];
    for (int i = 0; i < n; i++)
    {
        tPrSize[i] = prSize[i];
    }
    for (int i = 0; i < m; i++)
    {
        tHoles[i] = holes[i];
    }
    bestFit(tPrSize, tHoles, n, m);
    return 0;
}