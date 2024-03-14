#include<bits/stdc++.h>
using namespace std;

class SimpsonsRule {
private:
    double a, b, h, n;

    // Function to be integrated
    double y(double x) {
        return (1 / (1 + x));
    }

public:
    SimpsonsRule() {
        cout << "Enter lower limit: ";
        cin >> a;
        cout << "Enter upper limit: ";
        cin >> b;
        do {
            cout << "Enter the number of intervals (must be a positive integer): ";
            cin >> n;
        } while (n <= 0); // Input validation for positive integer

        h = (b - a) / (1.0 * n);
    }

    void solve() {
        double in_val = y(a) + y(b); // Integrated value

        // Applying Simpson's Rule
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                in_val += 2 * y(a + h * i);
            } else {
                in_val += 4 * y(a + h * i);
            }
        }

        in_val = (in_val * h) / 3;

        cout << "Integrated value of the function is " << fixed << setprecision(6) << in_val << endl;
    }
};

int main() {
    SimpsonsRule simpson;
    simpson.solve();
    return 0;
}
