#include <iostream>
using namespace std;

class ForwardInterpolation
{
public:
    int n;
    double x[10], y[10][10];
    double ans = 0, given_x;

    ForwardInterpolation()
    {
        cout << "Enter the value of n: ";
        cin >> n;
        cout << "Enter the values of x and y:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i][0];
        }
        cout << "Enter the value of x for interpolation: ";
        cin >> given_x;

        // Check if values of x are equally spaced
        double h = x[1] - x[0];
        for (int i = 2; i < n; i++)
        {
            if (x[i] - x[i - 1] != h)
            {
                cout << "Warning: Values of x are not equally spaced. Results may not be accurate." << endl;
                break;
            }
        }
    }

    double factorial(int i)
    {
        if (i)
        {
            return i * factorial(i - 1);
        }
        else
        {
            return 1;
        }
    }

    double multiply(double p, int i)
    {
        double value = p;
        for (int j = 1; j < i; j++)
        {
            value *= (p - j);
        }
        return value;
    }

    void solve()
    {
        //calculating table
        for (int col = 1; col < n; col++)
        {
            for (int row = 0; row < n - col; row++)
            {
                y[row][col] = y[row + 1][col - 1] - y[row][col - 1];
            }
        }

        ans = y[0][0];
        double h = x[1] - x[0];
        double p = (given_x - x[0]) / h;

        for (int i = 1; i < n; i++)
        {
            ans += (multiply(p, i) * y[0][i]) / factorial(i);
        }

        cout << "The value of " << given_x << " is " << ans << endl;
    }
};

int main()
{
    ForwardInterpolation f;
    f.solve();
    return 0;
}
/**
5
1891 46
1901 66
1911 81
1921 93
1931 101
1895
*/
