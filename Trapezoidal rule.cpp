#include<bits/stdc++.h>
using namespace std;

class TrapezoidalRule {
public:
    double s = 0, a, b, x, h;
    int n;

    // Function to calculate the integrand
    double y(double x) {
        return (1 / (1 + x));
    }

    // Constructor to initialize lower limit, upper limit, and number of intervals
    TrapezoidalRule() {
        cout << "Enter the value of lower limit : ";
        cin >> a;
        cout << "Enter the value of upper limit : ";
        cin >> b;
        cout << "Enter the number of intervals : ";
        cin >> n;
    }

    // Function to solve using the Trapezoidal Rule
    double solve() {
        h = (b - a) / (n * 1.0);

        s = y(a) + y(b);

        for(int i = 1; i < n; i++) {
            x = a + i * h;
            s += 2 * y(x);
        }
        s = (s * h) / 2;

        return s;
    }
};

int main() {
    // Create an instance of the TrapezoidalRule class
    TrapezoidalRule trapezoidal;

    // Calculate the result of integration
    double result = trapezoidal.solve();

    // Print the result
    cout << "Result of integration : " << fixed << setprecision(6) << result << endl;

    return 0;
}
