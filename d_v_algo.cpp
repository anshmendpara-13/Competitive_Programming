#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

const int inf = INT_MIN;

int main()
{
    int graph[5][5];
    int i, j, k, t;
    int no_of_node;

    cout << "\nEnter Number of Nodes : ";
    cin >> no_of_node;

    for (i = 0; i < no_of_node; i++)
    {
        for (j = 0; j < no_of_node; j++)
        {
            graph[i][j] = -1;
        }
    }

    // cout << endl;
    // for (i = 0; i < no_of_node; i++)
    // {
    //     for (j = 0; j < no_of_node; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    char ch[5] = {'a', 'b', 'c', 'd', 'e'};

    for (i = 0; i < no_of_node; i++)
    {
        for (j = 0; j < no_of_node; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
            }
            if (graph[i][j] == -1)
            {
                cout << "\nEnter Distance between " << ch[i] << " - " << ch[j] << " : ";
                cin >> t;
                graph[i][j] = graph[j][i] = t;
            }
        }
    }

    for (i = 0; i < no_of_node; i++)
    {
        for (j = 0; j < no_of_node; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int via[5][5];
    for (i = 0; i < no_of_node; i++)
    {
        for (j = 0; j < no_of_node; j++)
        {
            via[i][j] = -1;
        }
    }

    int sh[5][5][5];
    for (i = 0; i < no_of_node; i++)
    {
        for (j = 0; j < no_of_node; j++)
        {
            for (k = 0; k < no_of_node; k++)
            {
                if ((graph[i][j] > -1) && (graph[j][k] > -1))
                {
                    sh[i][j][k] = graph[i][j] + graph[j][k];
                }
                else
                {
                    sh[i][j][k] = -1;
                }
            }
        }
    }

    // for (int i = 0; i < no_of_node; i++)
    // {
    //     for (int j = 0; j < no_of_node; j++)
    //     {
    //         for (int k = 0; k < no_of_node; k++)
    //         {
    //             cout << sh[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int final[5][5];
    int flag = 0;
    for (i = 0; i < no_of_node; i++)
    {
        for (j = 0; j < no_of_node; j++)
        {
            final[i][j] = graph[i][j];
            via[i][j] = i;

            for (k = 0; k < no_of_node; k++)
            {

                if ((final[i][j] > sh[i][k][j]) || (final[i][j] == -1))
                {
                    if (sh[i][k][j] > -1)
                    {
                        final[i][j] = sh[i][k][j];
                        via[i][j] = k;
                    }
                }
            }

            if (final[i][j] == -1)
            {
                for (k = 0; k < no_of_node; k++)
                {

                    if ((final[i][k] != -1) && (final[k][j] != -1))
                    {
                        if ((final[i][j] == -1) || ((final[i][j] != -1) && (final[i][j] > final[i][k] + final[k][j])))
                        {
                            if (final[i][k] + final[k][j] > -1)
                            {
                                final[i][j] = final[i][k] + final[k][j];
                                via[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << endl;
    cout << "\nAfter Update :- ";
    cout << endl;
    for (i = 0; i < no_of_node; i++)
    {
        cout << endl;
        cout << "For : " << ch[i];
        cout << "\nDest\tCost\tNext";
        for (j = 0; j < no_of_node; j++)
        {
            cout << "\n"
                 << ch[j] << "\t" << final[i][j] << "\t";
            if (i == via[i][j])
                cout << ch[i];
            else
                cout << ch[via[i][j]];
        }
        cout << endl;
    }

    return 0;
}