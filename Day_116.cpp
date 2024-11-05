#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> s = matrix;  // Copy the matrix to s

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[j][n - 1 - i] = s[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    // Define a sample 3x3 matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    // Rotate the matrix
    rotate(matrix);

    cout << "\nRotated matrix by 90 degrees clockwise:" << endl;
    printMatrix(matrix);

    return 0;
}
