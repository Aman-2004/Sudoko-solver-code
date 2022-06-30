#include <iostream>
using namespace std;
int board[9][9];
int f[9][10];
/* Checks whether it will be able to assign num to the
given row, col,cell of(3X3)*/
bool check(int row, int col, int val)
{
    for (int x = 0; x < 9; x++)
    {
        // Check if we find the same val in current row
        if (board[row][x] == val)
        {
            return 0;
        }

        // Check if we find the same val in current row
        if (board[x][col] == val)
        {
            return 0;
        }
    }

    // Check if we find the same val in current cell
    int nR = row - row % 3;
    int nC = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i + nR][j + nC] == val)
            {
                return 0;
            }
        }
    }
    return 1;
}

// recurrsion
bool rec(int row, int col)
{
    // base case
    if (row == 8 && col == 9)
    {
        return 1;
    }

    /* Check if column value becomes 9 , we move to next row and
     column start from 0*/
    if (col == 9)
    {
        row++;
        col = 0;
    }

    // if that cell already contains something then move to next cell
    if (board[row][col] != 0)
    {
        return rec(row, col + 1);
    }

    for (int ch = 1; ch <= 9; ch++)
    {

        // checking if we can place 1-9 any one in current cell
        if (check(row, col, ch))
        {

            // setting current cell to our choice
            board[row][col] = ch;

            // Checking for next possibility with next column
            if (rec(row, col + 1))
            {
                return 1;
            }
            // setting back to previous value as our assumption was wrong
            board[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    // int board[9][9];
    // type 0 for unassigned cell
    int flag = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            f[i][board[i][j]]++;
            if (f[i][board[i][j]] > 1 && board[i][j] != 0)
            {
                flag = 1;
            }
        }
    }

    if (flag == 1)
    {
        cout << "WRONG SUDOKO ENTERED";
    }
    else if (rec(0, 0))
    {
        // printing the board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NOT POSSIBLE " << endl;
    }

    return 0;
}
// sample input and output
// // q1
// 0 0 0 3 0 0 0 7 0
// 7 3 4 0 8 0 1 6 2
// 2 0 0 0 0 0 0 3 8
// 5 6 8 0 0 4 0 1 0
// 0 0 2 1 0 0 0 0 0
// 0 0 7 8 0 0 2 5 4
// 0 7 0 0 0 2 8 9 0
// 0 5 1 4 0 0 7 2 6
// 9 0 6 0 0 0 0 4 5

// sol

// 6 8 5 3 2 1 4 7 9 
// 7 3 4 9 8 5 1 6 2 
// 2 1 9 6 4 7 5 3 8 
// 5 6 8 2 7 4 9 1 3 
// 3 4 2 1 5 9 6 8 7 
// 1 9 7 8 3 6 2 5 4 
// 4 7 3 5 6 2 8 9 1 
// 8 5 1 4 9 3 7 2 6 
// 9 2 6 7 1 8 3 4 5
