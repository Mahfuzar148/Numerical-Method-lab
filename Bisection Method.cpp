
#include<bits/stdc++.h>
using namespace std;

class BisectionMethod {
private:
    double a, b;
    double tolerance = 0.0001;
    int maxIterations = 1000;  // Set a maximum number of iterations

    double Function(double x) {
        return (pow(x, 3) - 2 * x - 5);
    }

public:
    void solve() {
        srand(time(0));

        // Initialize a and b with random values ensuring Function(a) * Function(b) < 0
        while (1) {
            a = -9999 + rand() % 1000;
            b = rand() % 1000;

            if (Function(a) * Function(b) < 0) {
                break;
            }
        }

        double root;

        for (int iteration = 1; iteration <= maxIterations; ++iteration) {
            root = (a + b) / 2;
            printf("Iteration %d: a = %9f b = %9f root = %9f\n", iteration, a, b, root);

            if (Function(root) == 0 || abs(Function(root)) < tolerance) {
                break;
            }

            if (Function(root) * Function(a) < 0) {
                b = root;
            } else {
                a = root;
            }
        }

        cout << fixed << setprecision(9) << endl;
        cout << "The root is " << root << " (correct up to 3 decimal places)" << endl;
    }
};

int main() {
    BisectionMethod bisectionMethod;
    bisectionMethod.solve();

    return 0;
}

