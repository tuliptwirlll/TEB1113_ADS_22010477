#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to display the matrix
void displayMatrix(const vector<vector<int>> &mat) {
    for (const auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }
}

// Function to find the maximum value in the matrix
int findMaxValue(const vector<vector<int>> &mat) {
    int maxValue = numeric_limits<int>::min(); // Initialize to the smallest integer
    for (const auto& row : mat) {
        for (int x : row) {
            maxValue = max(maxValue, x);
        }
    }
    return maxValue;
}

// Function to find the minimum value in the matrix
int findMinValue(const vector<vector<int>> &mat) {
    int minValue = numeric_limits<int>::max(); // Initialize to the largest integer
    for (const auto& row : mat) {
        for (int x : row) {
            minValue = min(minValue, x);
        }
    }
    return minValue;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    // Input the matrix elements
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    // Display the original matrix
    cout << "Original matrix:\n";
    displayMatrix(mat);

    // Ask user for minimum or maximum
    char choice;
    cout << "Do you want to find the minimum (m) or maximum (M) number? ";
    cin >> choice;

    if (choice == 'm' || choice == 'M') {
        int minValue = findMinValue(mat);
        cout << "Minimum Value is: " << minValue << endl;
    } else if (choice == 'M' || choice == 'm') {
        int maxValue = findMaxValue(mat);
        cout << "Maximum Value is: " << maxValue << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
