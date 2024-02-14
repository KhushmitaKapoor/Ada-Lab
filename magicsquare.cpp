#include <iostream>
using namespace std;
void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        cout << "Magic square can only be generated for odd order" <<endl;
        return;
    }
    int magicSquare[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            magicSquare[i][j] = 0;

    int num = 1;
    int i = n / 2;
    int j = n - 1;
    while (num <= n * n) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) {
                j = 0;
            }
            if (i < 0) {
                i = n - 1;
            }
        }
        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }
        j++;
        i--;
    }
    cout << "The Magic Square for n=" << n << " is:" <<endl;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << magicSquare[i][j] << " ";
        }
        cout <<endl;
    }
}
int main() {
    int n;
    cout << "Enter the order of magic square (odd number): ";
    cin >> n;
    generateMagicSquare(n);
    return 0;
}

