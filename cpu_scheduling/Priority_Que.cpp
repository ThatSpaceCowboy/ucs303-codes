#include <iostream>
//#include<conio.h>
using namespace std;
int isempty();
int isfull();
void insert(int, int);
int gethighestpriority();
int deletehighestpriority();
void disp();

struct priorityqueue
{
    int ele;
    int priority;
} pq[5];
int rear = -1;

int main()
{
    int ch, p, ele;
    do
    {
        cout << "\n1.Insert\n2.Get Highest Priority\n3.Delete Highest Priority\n4.Display\n5.Exit\n";
        cout << "\nEnter Your Choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (isfull())
                cout << "\n Priority Queue Is Full";
            else
                cout << "\n Enter the element to Insert\n";
            cin >> ele;
            cout << "\n Enter the priority\n";
            cin >> p;
            insert(ele, p);
            break;
        case 2:
            if (isempty())
                if (isempty())

                    cout << "\n Priority Queue is empty";

                else

                    p = gethighestpriority();
            cout << "\n Highest Priority";

            break;
        case 3:
            if (isempty())
                cout << "\n Priority Queue is empty\n";
            else
                p = gethighestpriority();
            cout << "\n Highest Priority = " << p;
            break;
        case 4:
            if (isempty())

                cout << "\n Priority Queue is Empty";

            else

                disp();

            break;
        }
    } while (ch != 5);
    return 0;
}
int isempty()
{
    if (rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if (rear == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(int ele, int p)
{
    rear = rear + 1;
    pq[rear].ele = ele;
    pq[rear].priority = p;
}
int gethighestpriority()
{
    int i, p = -1;
    if (!isempty())
    {
        for (i = 0; i <= rear; i++)
        {
            if (pq[i].priority > p)
            {
                p = pq[i].priority;
            }
        }
        return p;
    }
}
int deletehigherpriority()
{
    int i, j, p, ele;
    p = gethighestpriority();
    for (i = 0; i <= rear; i++)
    {
        ele = pq[i].ele;
        break;
    }
    if (i < rear)
    {
        for (j = i; j < rear; j++)
        {
            pq[j].ele = pq[j + 1].ele;
            pq[j].priority = pq[j + 1].priority;
        }
        rear = rear - 1;
        return ele;
    }
}
void disp()
{
    int i;
    cout << "\n Priority Queue = " << endl;
    for (i = 0; i <= rear; i++)
    {
        cout << "|ele = " << pq[i].ele << " - priority = " << pq[i].priority << "|" << endl
             << endl;
    }
}
