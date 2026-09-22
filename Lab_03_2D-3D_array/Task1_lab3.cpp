#include <iostream>
using namespace std;

int main()
{
    int marks[6][4] =
    {
        {78, 85, 90, 88},
        {65, 75, 80, 70},
        {90, 92, 87, 95},
        {55, 60, 72, 68},
        {82, 79, 85, 80},
        {88, 91, 89, 86}
    };

    int total[6];
    float average[6];

    cout << "Complete Marks Table:\n\n";
    cout << "Student\tEnglish\tMath\tProgramming\tAI\n";

    for (int i = 0; i < 6; i++)
    {
        cout << i + 1 << "\t";

        for (int j = 0; j < 4; j++)
        {
            cout << marks[i][j] << "\t";
        }

        cout << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        total[i] = 0;

        for (int j = 0; j < 4; j++)
        {
            total[i] = total[i] + marks[i][j];
        }

        average[i] = total[i] / 4.0;
    }

    cout << "\nStudent Totals and Averages:\n";

    for (int i = 0; i < 6; i++)
    {
        cout << "Student " << i + 1
             << ": Total = " << total[i]
             << ", Average = " << average[i] << endl;
    }
    cout << "\nHighest Marks in Each Subject:\n";

    for (int j = 0; j < 4; j++)
    {
        int highest = marks[0][j];

        for (int i = 1; i < 6; i++)
        {
            if (marks[i][j] > highest)
            {
                highest = marks[i][j];
            }
        }

        cout << "Subject " << j + 1
             << ": " << highest << endl;
    }
    int highestTotal = total[0];
    int bestStudent = 0;

    for (int i = 1; i < 6; i++)
    {
        if (total[i] > highestTotal)
        {
            highestTotal = total[i];
            bestStudent = i;
        }
    }

    cout << "\nStudent with Highest Total Marks: Student "
         << bestStudent + 1 << endl;

    cout << "Highest Total: " << highestTotal << endl;

    return 0;
}