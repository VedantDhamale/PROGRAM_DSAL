// You have a business with several offices; you want to lease phone lines to connect
// them up with each other; and the phone company charges different amounts of money to
// connectdifferent pairs of cities. You want a set of lines that connects all your offices
// with a minimum total cost. Solve the problem bysuggesting appropriate data structures

#include <iostream>
using namespace std;
class Graph
{
    int ne, m, n, w;
    int cost[10][10];
    // Adjlist variable
public:
    int nv;
    void create();
    void prims(int v, int visit[10]);
};
void Graph::create()
{
    int r, c; // r=row c=column
    cout << "Enter a no of vertices\t:";
    cin >> nv;
    cout << "\nEnter a no of edges \t:";
    cin >> ne;
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            cost[i][j] = 0;
        }
    }
    for (int i = 0; i < ne; i++)
    {
        cout << "\nEnter the start and end vertex and weight:";
        cin >> m >> n >> w;
        cost[m][n] = w;
    }
    cout << "\n---------Adjacency matrix-------" << endl;
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::prims(int v, int visit[10])
{
    int sum = 0, p, temp, min, m;
    visit[v] = 1;
    for (int k = 0; k < nv - 1; k++)
    {
        temp = 999;
        for (int i = 0; i < nv; i++)
        {
            if (visit[i] == 1)
            {
                min = 999;
                for (int j = 0; j < nv; j++)
                {
                    if (cost[i][j] != 0)
                    {
                        if (min >= cost[i][j] && visit[j] == 0)
                        {
                            min = cost[i][j];
                            p = j;
                        }
                    }
                }
                if (min < temp)
                {
                    temp = min;
                    m = i;
                    n = p;
                }
            }
        }
        sum = sum + cost[m][n];
        cout << "\nselected edge is between " << m << " to " << n << endl
             << endl;
        visit[m] = 1;
        visit[n] = 1;
    }
    cout << "minimum weight is:\t" << sum;
}

int main()
{
    Graph g1;
    int ch;
    int visit[10];

    while (1)
    {
        cout << "\n-------MENU---------\n";
        cout << "\n1-Create";
        cout << "\n2-prims";
        cout << "\n3-Exit";
        cout << "\n---------------------";

        cout << endl
             << "enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            g1.create();
            break;
        case 2:
            int v;
            for (int i = 0; i < g1.nv; i++)
            {
                visit[i] = 0;
            }
            cout << "Enter the starting vertex:";
            cin >> v;
            g1.prims(v, visit);
            break;

        case 3:
            exit(0);
            break;
        default:
            cout << "INVALID CHOICE:" << endl;
        }
    }
}
