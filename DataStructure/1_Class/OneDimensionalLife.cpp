#include <iostream>
#include <cstdlib>

using namespace std;
#define LEN 60

int Neighbors(int now[LEN+4], int i, int j);
void Life(int now[LEN+4]);
void Print(int now[LEN+4]);

int main()
{
    int now[LEN+4] = {0};
    int i;
    while (cin >> i && i != -1)
    {
        now[i+1] = 1;
    }
    int generation = 0;
    cin >> generation;
    for (int i = 0; i < generation; i++)
    {
        Life(now);
    }
    Print(now);
    return 0;
}

int Neighbors(int now[LEN+4], int i)
{
    int count = 0;
    for (int j = i-2; j <= i+2; j++){
        if (j==i) continue;
        else if (now[j]==1) count++;
    }
    return count;
}

void Life(int now[LEN+4])
{
    int next[LEN+4] = {0};
    for (int j = 2; j < LEN + 2; j++)
    {
        int count = Neighbors(now, j);
        if (count == 0 || count == 1)
        {
            next[j] = 0;
        }
        else if (count == 2)
        {
            next[j] = 1;
        }
        else if (count == 3)
        {
            next[j] = abs(now[j] - 1);
        }
        else
        {
            next[j] = now[j];
        }
    }
    for (int j = 0; j < LEN + 4; j++)
    {
        now[j] = next[j];
    }
}
    
void Print(int now[LEN+4])
{
    int i;
    for (i = 2; i < LEN+2; i++)
    {
        
            if (now[i] == 1)
            {
                cout << "*";
            }
            else
            {
                cout << "-";
            }
    }
}