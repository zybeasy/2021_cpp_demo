#include <iostream>

#include <iomanip>

using namespace std;

void print_matrix(int **data, unsigned int rows, unsigned int cols) {
    if (!data || !(*data) || (rows == 0 && cols == 0))
        return;
    
    int count = (min(rows, cols) + 1) / 2;
    for(int i = 0; i < count; ++i) {
        int r = cols - 2 * i;
        int c = rows - 2 * i - 2;

        for(int j = 0; j < r; j++)
            cout << data[i][i+j] << " ";
        for(int j = 0; j < c; j++)
            cout << data[i+1+j][i+r-1] << " ";
        if (c >= 0) {
        for(int j = 0; j < r; j++)
            cout << data[i+c+1][i+r-1-j] << " ";
        }
        if (r >= 2) {
            for(int j = 0; j < c; ++j) {
                cout << data[i+c-j][i] << " ";
            }
        }
    }

    cout << endl;
}

int** _make_matrix(int rows, int cols) {
    int **temp = new int*[rows];
    for(int i=0; i<rows; ++i)
        temp[i] = new int[cols];
    for (int i=0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = i * cols + j + 1;
            cout << setw(2) << setiosflags(ios::left) << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return temp;
}

void test_print_matrix() {
    int rows = 2, cols = 3;
    rows = 1, cols = 1;
    rows = 4, cols = 5;
    int **data = _make_matrix(rows, cols);
    print_matrix(data, rows, cols);
}