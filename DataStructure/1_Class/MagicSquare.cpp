#include <iostream>
#include <vector>

using namespace std;

class MagicSquare
{
public:
    MagicSquare(int n) : size(n), square(n, vector<int>(n, 0))
    {
        Generate();
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
        {
            cout << square[i][0];
            for (int j = 1; j < size; ++j)
            {
                cout << "  " << square[i][j];
            }
            cout << endl;
        }
    }

    void Generate()
    {
        int row = 0;
        int col = size / 2;

        for (int num = 1; num <= size * size; num++)
        {
            square[row][col] = num;
            //真的 so 巧妙
            int nextRow = (row - 1 + size) % size;
            int nextCol = (col + 1) % size;
            if (square[nextRow][nextCol] != 0){
                row = (row + 1) % size;
            }
            else{
                row = nextRow;
                col = nextCol;
            }
        }
    }

private:
    int size;
    vector<vector<int>> square;
};

int main()
{
    int n;
    cin >> n;

    MagicSquare magicSquare(n);
    magicSquare.print();

    return 0;
}