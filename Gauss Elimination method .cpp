#include <iostream>
#include <iomanip>

#define MAX_SIZE 10

using namespace std;

class GaussElimination {
private:
    float coefficients[MAX_SIZE][MAX_SIZE];
    float solutions[MAX_SIZE];
    float ratio;
    int numUnknowns;

public:
    void setPrecision() {
        cout << setprecision(6) << fixed;
    }

    void readInput() {
        cout << "Enter the number of unknowns: ";
        cin >> numUnknowns;

        cout << "Enter coefficients of the Augmented Matrix:" << endl;
        for (int i = 1; i <= numUnknowns; i++) {
            for (int j = 1; j <= numUnknowns + 1; j++) {
                cout << "coefficients[" << i << "][" << j << "] = ";
                cin >> coefficients[i][j];
            }
        }
    }

    void gaussElimination() {
        for (int i = 1; i <= numUnknowns - 1; i++) {
            if (coefficients[i][i] == 0.0) {
                // Perform row exchange with the row having a non-zero element in the i-th column
                for (int k = i + 1; k <= numUnknowns; k++) {
                    if (coefficients[k][i] != 0.0) {
                        // Exchange rows i and k
                        for (int j = 1; j <= numUnknowns + 1; j++) {
                            swap(coefficients[i][j], coefficients[k][j]);
                        }
                        break;  // Exit the loop once the exchange is done
                    }
                }
            }

            // Continue with Gaussian elimination as before
            for (int j = i + 1; j <= numUnknowns; j++) {
                ratio = coefficients[j][i] / coefficients[i][i];
                for (int k = 1; k <= numUnknowns + 1; k++) {
                    coefficients[j][k] = coefficients[j][k] - ratio * coefficients[i][k];
                }
            }
        }
    }

    void backSubstitution() {
        solutions[numUnknowns] = coefficients[numUnknowns][numUnknowns + 1] / coefficients[numUnknowns][numUnknowns];

        for (int i = numUnknowns - 1; i >= 1; i--) {
            solutions[i] = coefficients[i][numUnknowns + 1];
            for (int j = i + 1; j <= numUnknowns; j++) {
                solutions[i] = solutions[i] - coefficients[i][j] * solutions[j];
            }
            solutions[i] = solutions[i] / coefficients[i][i];
        }
    }

    void displaySolution() {
        cout << endl << "Solution:" << endl;
        for (int i = 1; i <= numUnknowns; i++) {
            cout << "x[" << i << "] = " << solutions[i] << endl;
        }
    }
};

int main() {
    GaussElimination linearSystemSolver;
    linearSystemSolver.setPrecision();
    linearSystemSolver.readInput();
    linearSystemSolver.gaussElimination();
    linearSystemSolver.backSubstitution();
    linearSystemSolver.displaySolution();

    return 0;
}
