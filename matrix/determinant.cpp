#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the determinant of a square matrix of any size.
double determinant(vector<vector<double>> &matrix)
{
    int size = matrix.size();

    // Base case: If the matrix is 1x1, return its only element.
    if (size == 1)
    {
        return matrix[0][0];
    }

    // Base case: If the matrix is 2x2, calculate the determinant directly.
    if (size == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0.0;
    // Iterate through the first row to expand along the elements of the first row.
    for (int i = 0; i < size; i++)
    {
        // Calculate the minor matrix by excluding the current row and column.
        vector<vector<double>> minor(size - 1, vector<double>(size - 1));
        for (int j = 1; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (k < i)
                {
                    minor[j - 1][k] = matrix[j][k];
                }
                else if (k > i)
                {
                    minor[j - 1][k - 1] = matrix[j][k];
                }
            }
        }

        cout << "DETERMINANT : " << endl;
        for (int i = 0; i < size - 1; i++)
            det += matrix[0][i] * pow(-1, i) * determinant(minor);
            // Recursively calculate the determinant of the minor matrix and accumulate.
        cout << det << " ";
    }

    return det;
}

int main()
{
    vector<vector<double>> matrix = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}};

    try
    {
        double det = determinant(matrix);
        cout << "Determinant: " << det << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
