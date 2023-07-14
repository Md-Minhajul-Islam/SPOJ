// Q: https://www.spoj.com/problems/MPOW/
#include <iostream>
using namespace std;
#define n 50
long long mod = 1000000007;
// using Matrix Exponential algorithm
void multiplyMatrix(long long a[][n], long long b[][n], int size)
{
    long long r[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            r[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                long long x = (a[i][k] * b[k][j]);
                r[i][j] = (r[i][j] + x) % mod;
            }
        }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a[i][j] = r[i][j];
}
void calculatePower(long long m[][n], int size, int power)
{
    long long result[n][n];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                result[i][j] = 1;
            else
                result[i][j] = 0;
        }
    while (power)
    {
        if (power % 2 == 1)
        {
            multiplyMatrix(result, m, size);
            power--;
        }
        else
        {
            multiplyMatrix(m, m, size);
            power /= 2;
        }
    }
    // ans is in result matrix. so, transferring it to m matrix
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            m[i][j] = result[i][j];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long m[n][n];
        int size, power;
        cin >> size >> power;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                cin >> m[i][j];

        calculatePower(m, size, power);

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}