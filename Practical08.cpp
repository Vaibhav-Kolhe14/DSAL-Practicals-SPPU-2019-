#include <iostream>
#include <queue>
using namespace std;
#define max 10
class obst
{
    int w[max][max], r[max][max], c[max][max], a[max], p[max], q[max];
    int m, n, i, j, k;

public:
    void accept()
    {
        cout << "Enter the total no keys :";
        cin >> n;

        for (i = 0; i < n; i++)
        {
            cout << "\nEnter key :";
            cin >> a[i];
        }
        cout << "Enter probabilities of successful search :";
        for (i = 1; i <= n; i++)
        {
            cout << "\nEnter probability :";
            cin >> p[i];
        }
        cout << "Enter probabilities of unsuccessful search :";
        for (i = 0; i <= n; i++)
        {
            cout << "\nEnter probability :";
            cin >> q[i];
        }
    }
    int find(int i, int j)
    {
        int m, k;
        int min = 32000; // or any other value
        for (k = i + 1; k <= j; k++)
        {
            if ((c[i][k - 1] + c[k][j]) < min)
            {
                min = c[i][k - 1] + c[k][j];
                m = k;
            }
        }
        return m;
    }

    void build_obst()
    {
        // j-i=0
        for (i = 0; i < n; i++)
        {
            w[i][i] = q[i];
            c[i][i] = r[i][i] = 0;
        }
        // j-i=1
        for (i = 0; i < n; i++)
        {
            w[i][i + 1] = p[i + 1] + q[i + 1] + w[i][i];
            c[i][i + 1] = w[i][i + 1];
            r[i][i + 1] = i + 1;
        }
        // j-i=2,3,4
        for (m = 2; m <= n; m++)
        {
            for (i = 0; i <= n - m; i++)
            {
                j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                k = find(i, j);
                c[i][j] = c[i][k - 1] + c[k][j] + w[i][j];
                r[i][j] = k;
            }
        }
    }
    void display()
    {
        queue<int> queue;
        int i, j, k;
        cout << "The Optimal Binary Search Tree For The Given Nodes is ....\n";
        cout << "\n The Root of this OBST is :: " << r[0][n];
        cout << "\n The Cost Of this OBST is :: " << c[0][n];
        cout << "\n\n\t  NODE\t  LEFT CHILD\t   RIGHT CHILD";
        cout << "\n -------------------------------------------------------";
        queue.push(0);
        queue.push(n);

        while (!queue.empty())
        {
            i = queue.front();
            queue.pop();
            j = queue.front();
            queue.pop();
            k = r[i][j];
            cout << "\n         " << k;
            if (r[i][k - 1] != 0)
            {
                cout << "              " << r[i][k - 1];
                queue.push(i);
                queue.push(k - 1);
            }
            else
                cout << "              -";

            if (r[k][j] != 0)
            {
                cout << "              " << r[k][j];
                queue.push(k);
                queue.push(j);
            }
            else
                cout << "              -";
        }
        cout << "\n";
    }
};
int main()
{
    obst o;
    o.accept();
    o.build_obst();
    o.display();
    return 0;
}
