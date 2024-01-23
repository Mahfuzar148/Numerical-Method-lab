#include <bits/stdc++.h>
using namespace std;

class Secant
{
private:
    const double tolerance = 0.0001;

    double functional_value(double x)
    {
        return pow(x, 3) - 2 * x - 5;
    }
    double secant(double a, double b)
    {
        return (a * functional_value(b) - b * functional_value(a)) / (functional_value(b) - functional_value(a));
    }

public:
    double a, b;
    void solve()
    {
        srand(time(0));
        int i = 0;
        while (1)
        {
            a = rand() % 10 - 9;
            b = rand() % 10;
            if (functional_value(a) * functional_value(b) < 0)
            {
                break;
            }
        }

        double root = secant(a, b);
        while (1)
        {
            printf("a = %10f   b = %10f     root = %9f\n", a, b, root);
            
            if (functional_value(root) == 0.0 || abs(root - secant(b, root)) < tolerance)
            {
                break;
            }
            a = b;
            b = root;
            root = secant(a, b);
        }

        printf("a = %10f   b = %10f     root = %9f\n", a, b, root);
        cout << "\nThe root is " << root << " (correct up to 3 decimal places)\n";
    }
};

int main(void)
{
    Secant n = Secant();
    n.solve();
}
