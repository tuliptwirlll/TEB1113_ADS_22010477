#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
  
    // Consider all cycles one by one
    for (int i = 0; i < n / 2; i++) {
        // Consider elements in group of 4 as P1, P2, P3 & P4 in current square
        for (int j = i; j < n - i - 1; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][n - 1 - i];
            mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
            mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
            mat[n - 1 - j][i] = temp;
        }
    }
}

void displayMatrix(const vector<vector<int>> &mat) {
    for (const auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }
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

    // Rotate the matrix
    rotateMatrix(mat);

    // Display the rotated matrix
    cout << "Rotated matrix (90 degrees anticlockwise):\n";
    displayMatrix(mat);

    return 0;
}
