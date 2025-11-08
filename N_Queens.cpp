#include <iostream>
using namespace std;

#define N 8  // You can change this value for different board sizes

// Function to print the solution board
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// Check if placing a queen at board[row][col] is safe
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive backtracking function
bool solveNQueens(int board[N][N], int row) {
    if (row >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            res = solveNQueens(board, row + 1) || res;
            board[row][col] = 0; // Backtrack
        }
    }
    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0))
        cout << "No solution exists";
    else
        cout << "Solutions displayed above." << endl;

    return 0;
}
