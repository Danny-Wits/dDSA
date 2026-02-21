#include <iostream>
using namespace std;

struct dimension
{
    int row;
    int col;
};
typedef int **matrix;

void print(matrix m, dimension d)
{
    cout << "\n-------\n";
    for (int i = 0; i < d.row; i++)
    {
        for (int j = 0; j < d.col; j++)
        {
            cout << m[i][j] << "|";
        }
        cout << endl;
    }
    cout << "------\n";
}
matrix create(dimension d)
{
    matrix m = new int *[d.row];
    for (int i = 0; i < d.row; i++)
    {
        m[i] = new int[d.col];
    }
    return m;
}
matrix create(dimension d, int *array)
{
    matrix m = create(d);
    for (int i = 0; i < d.row; i++)
    {
        for (int j = 0; j < d.col; j++)
        {
            m[i][j] = array[i * d.col + j];
        }
    }
    return m;
}

matrix add(matrix m1, matrix m2, dimension d)
{
    int row = d.row;
    int col = d.col;
    matrix m3 = create(d);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return m3;
}
matrix multipy(matrix m1, matrix m2, dimension d1, dimension d2)
{
    if (d1.col != d2.row)
    {
        cout << "multiplication not allowed ";
        return NULL;
    }

    int row = d1.row;
    int col = d2.col;
    matrix m3 = create({row, col});
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int x = 0;
            for (int k = 0; k < d1.col; k++)
            {
                x += m1[i][k] * m2[k][j];
            }
            m3[i][j] = x;
        }
    }
    return m3;
}

int main()
{
    int x[9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    int y[9] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    dimension d{3, 3};
    matrix m1 = create(d, x);
    matrix m2 = create(d, y);
    print(m1, d);
    print(add(m1, m2, d), d);
    print(multipy(m1, m2, d, d), d);
    return 0;
}