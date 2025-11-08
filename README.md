# 🧠 N-Queens Problem using Backtracking

## 📘 Overview
The **N-Queens Problem** is a classic example of the **backtracking algorithm**.  
The challenge is to place **N queens** on an **N×N chessboard** such that **no two queens attack each other**, i.e.,
- No two queens are in the same row  
- No two queens are in the same column  
- No two queens are on the same diagonal  

This project demonstrates how to solve this problem programmatically using **C++** and the **backtracking approach**.

---

## ⚙️ Algorithm Used
**Backtracking Algorithm**  

The algorithm explores placing a queen in each row, one by one, and checks if it is safe to place it at a given position:
1. Place a queen in the current row.
2. Check if the position is safe using column and diagonal checks.
3. If safe → move to the next row.
4. If not safe → backtrack and try another column.
5. Continue until all queens are placed successfully.

---

## 🧩 Pseudocode
```text
function solveNQueens(board, row, N):
    if row >= N:
        printSolution(board)
        return true

    for col = 0 to N-1:
        if isSafe(board, row, col, N):
            board[row][col] = 1
            solveNQueens(board, row + 1)
            board[row][col] = 0  // backtrack
```

---

## 💻 Code
The main implementation file is [`nqueens.cpp`](./code/nqueens.cpp):

```cpp
#include <iostream>
using namespace std;

#define N 8  // You can change this value for different board sizes

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++)
        if (board[i][col]) return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) return false;
    return true;
}

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
            board[row][col] = 0;
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
```

---

## 🧮 Sample Output (for N = 4)
```
. Q . .
. . . Q
Q . . .
. . Q .

. . Q .
Q . . .
. . . Q
. Q . .

Solutions displayed above.
```

---

## ⏱️ Time & Space Complexity

| Type | Complexity | Explanation |
|------|-------------|--------------|
| Time Complexity | O(N!) | For each row, you try all columns recursively |
| Space Complexity | O(N²) | To store the chessboard configuration |

---

## 🧠 Key Concepts Demonstrated
- Backtracking  
- Recursion  
- Constraint satisfaction  
- Problem-solving using pruning  

---

## 🚀 How to Run the Code

### Using Terminal / Command Prompt
```bash
g++ nqueens.cpp -o nqueens
./nqueens
```

### Using VS Code
1. Open the folder in VS Code.  
2. Create a new file → `nqueens.cpp` and paste the code.  
3. Open the terminal → run:
   ```bash
   g++ nqueens.cpp -o nqueens
   ./nqueens
   ```

---

## 📂 Project Structure
```
N_Queens_Problem/
│
├── code/
│   └── nqueens.cpp
│
├── output/
│   └── output_example.txt
│
├── report/
│   └── N_Queens_Report.pdf
│
└── README.md
```

---

## 👩🏻‍💻 Author
**Name:** Alina Kaushar Mansuri  
**Course:** B.Tech in Computer Science (2nd Year)  
**Lab:** Design and Analysis of Algorithms  
**College Hours:** 8:30 AM – 4:30 PM  
