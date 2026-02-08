#include <iostream>
#include <iomanip>
using namespace std;

class MagicSquare
{

    int **array;
    int size;

    int bound(int num)
    {
        return (num + size) % size;
    }
    int get(int i, int j)
    {
        return array[bound(i)][bound(j)];
    }
    void construct()
    {
        int i = 0;
        int j = size / 2;
        int limit = size * size;
        array[i][j] = 1;
        for (int n = 2; n <= limit; n++)
        {
            // default move
            if (get(i - 1, j + 1) == -1)
            {
                i = bound(i - 1);
                j = bound(j + 1);
                // diag right up
            }
            else
            {
                i = i + 1; // down one
            }
            array[i][j] = n;
        }
    }

public:
    MagicSquare(int size) : size(size)
    {
        array = new int *[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = new int[size]{};
            for (int j = 0; j < size; j++)
            {
                array[i][j] = -1;
            }
        }
        if (size % 2 == 0)
        {
            cout << "\nCan't Create a Magic Sqaure of Even number of sides : " << size << endl;
            this->size = -1;
        }
        else
        {
            construct();
            cout << "\nSquare of size : " << size << endl;
        }
    }

    void print()
    {
        if (size == -1)
            return;
        int colSum[size]{0};
        int rowSum;
        for (int i = 0; i < size; i++)
        {
            cout << "| ";
            rowSum = 0;
            for (int j = 0; j < size; j++)
            {
                rowSum += array[i][j];
                colSum[j] += array[i][j];
                cout << setw(3) << array[i][j] << " ";
            }
            cout << "| " << rowSum << "\n";
        }
        cout << "  ";
        for (auto &&s : colSum)
        {
            cout << setw(3) << s << " ";
        }
        cout << "  ";
        int diagSum = 0;
        for (int i = 0; i < size; i++)
        {
            diagSum += array[i][i];
        }
        cout << diagSum;
        cout << "\nSuccess : " << (diagSum == rowSum && rowSum == colSum[0] ? " YES" : " NO") << endl;
    }
};

int main()
{

    for (int i = 1; i <= 8; i++)
    {
        MagicSquare s(i);
        s.print();
    }

    return 0;
}