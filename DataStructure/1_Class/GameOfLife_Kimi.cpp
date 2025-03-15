#include <iostream>
using namespace std;

const int ROWS = 20;
const int COLS = 60;

int Neighbors(int now[ROWS][COLS], int i, int j)
{
    int count = 0;
    for (int di = -1; di <= 1; ++di)
    {
        for (int dj = -1; dj <= 1; ++dj)
        {
            if (di == 0 && dj == 0)
                continue;
            int ni = i + di, nj = j + dj;
            if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLS && now[ni][nj] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int getNextState(int currentState, int neighbors)
{
    if (currentState == 1 && (neighbors < 2 || neighbors > 3))
        return 0;
    if (currentState == 0 && neighbors == 3)
        return 1;
    return currentState;
}

void Life(int now[ROWS][COLS])
{
    int change[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            int neighbors = Neighbors(now, i, j);
            change[i][j] = getNextState(now[i][j], neighbors);
        }
    }

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            now[i][j] = change[i][j];
        }
    }
}

void Print(int now[ROWS][COLS])
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << (now[i][j] == 1 ? '*' : '-');
        }
        cout << endl;
    }
}

int main()
{
    int now[ROWS][COLS] = {0};
    int i, j;
    while (cin >> i >> j && i != -1 && j != -1)
    {
        if (i >= 1 && i <= ROWS && j >= 1 && j <= COLS)
        {
            now[i - 1][j - 1] = 1;
        }
    }

    int generation;
    cin >> generation;

    for (int gen = 0; gen < generation; ++gen)
    {
        Life(now);
    }

    Print(now);
    return 0;
}