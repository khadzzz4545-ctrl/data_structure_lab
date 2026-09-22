#include <iostream>
using namespace std;

int main()
{
    int parking[4][5] =
    {
        {1, 0, 1, 0, 1},
        {0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int occupied = 0;
    int empty = 0;

    cout << "Parking Layout:\n\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << parking[i][j] << " ";

            if (parking[i][j] == 1)
                occupied++;
            else
                empty++;
        }

        cout << endl;
    }

    cout << "\nTotal Occupied Spaces: " << occupied << endl;
    cout << "Total Empty Spaces: " << empty << endl;

    int row, column;

    cout << "\nEnter row number (1-4): ";
    cin >> row;

    cout << "Enter column number (1-5): ";
    cin >> column;

    if (row >= 1 && row <= 4 && column >= 1 && column <= 5)
    {
        if (parking[row - 1][column - 1] == 0)
        {
            cout << "The selected parking space is AVAILABLE.\n";
        }
        else
        {
            cout << "The selected parking space is OCCUPIED.\n";
        }
    }
    else
    {
        cout << "Invalid row or column number.\n";
    }

    cout << "\nTotal Parking Capacity: " << 4 * 5 << endl;
    cout << "Current Occupancy: " << occupied << endl;

    return 0;
}