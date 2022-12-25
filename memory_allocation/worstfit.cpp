#include <iostream>
using namespace std;
void worstFit(int *prSize, int *holes, int n, int m)
{
    int wfit[n];
    for (int i = 0; i < n; i++)
    {
        int space = -1;
        for (int j = 0; j < m; j++)
        {
            if (prSize[i] <= holes[j] && (space == -1 || holes[j] > holes[space]))
            {
                space = j;
            }
        }
        if (space == -1)
        {
            wfit[i] = -1;
        }
        else
        {
            wfit[i] = space;
            holes[space] -= prSize[i];
        }
    }
    cout << "Worst fit\n";
    for (int i = 0; i < n; i++)
    {
        cout << wfit[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    int prsize[n];
    for (int i = 0; i < n; i++)
    {
        cin >> prsize[i];
    }
    int m;
    int holes[m];
    for (int i = 0; i < m; i++)
    {
        cin >> holes[i];
    }
    int tPrSize[n], tHoles[m];
    for (int i = 0; i < n; i++)
    {
        tPrSize[i] = prsize[i];
    }
    for (int i = 0; i < m; i++)
    {
        tHoles[i] = holes[i];
    }
    worstFit(tPrSize, tHoles, n, m);
    return 0;
}