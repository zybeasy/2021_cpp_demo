#include <iostream>
#include <cstring>

using namespace std;

/* 输入二维数组，查找是否有指定序列

A B T G 
C F C S 
J D E H

BFCE
 */

void output_result(char *data, int rows, int cols, bool *visited) {
    for(int row=0; row<rows; ++row) {
        for(int col=0; col<cols; ++col) {
            if (visited[row*cols+col])
                cout << "\033[42m" << data[row*cols+col] << "\033[0m" << " ";
            else
                cout << data[row*cols+col] << " ";
        }
        cout << endl;
    }
}

bool _get_path(char *data, int rows, int cols, int row, int col, char *str, int index, bool *visited) {
    if (str[index] == '\0')
        return true;
    
    bool result = false;
    if (row >=0 && row < rows && col >=0 && col < cols && 
        data[cols*row + col] == str[index] && !visited[cols*row+col]) {
            visited[cols*row+col] = true;
            result = _get_path(data, rows, cols, row-1, col, str, index+1, visited) || 
                     _get_path(data, rows, cols, row+1, col, str, index+1, visited) ||
                     _get_path(data, rows, cols, row, col-1, str, index+1, visited) ||
                     _get_path(data, rows, cols, row, col+1, str, index+1, visited);

            if (!result) {
                visited[cols*row+col] = false;
            }
    }
    return result;
}

bool get_path(char *data, int rows, int cols, char *str) {

    if (data == NULL || rows < 1 || cols < 1 || str == NULL)
        return false;
    
    bool *visited = new bool[rows * cols];
    memset(visited, 0, sizeof(bool)*rows*cols);

    for(int row=0; row<rows; ++row) {
        for(int col=0; col<cols; ++col) {
            if (_get_path(data, rows, cols, row, col, str, 0, visited)) {
                output_result(data, rows, cols, visited);
                return true;
            }
        }
    }

    output_result(data, rows, cols, visited);
    cout << "FILED TO FIND PATH \"" << "\033[32m" << str << "\033[0m\"" << endl;
    return false;
}

void test_get_path() {
    cout << "============ test_get_path ===========" << endl;

    char data1[] = "ABTGCFCSJDEH";
    char str1[] = "BFCE";
    // cout << "get_path: " << data1 << " " << str1 << " " << get_path(data1, 3, 4, str1) << endl;
    get_path(data1, 3, 4, str1);

    cout << "***********************************" << endl;

    char data2[] = "ABCESFCSADEE";
    char str2[] = "SEE";
    get_path(data2, 3, 4, str2);

    cout << "***********************************" << endl;

    char matrix[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char str[] = "SGGFIECVAASABCEHJIGQEM";
    get_path(matrix, 5, 8, str);

    cout << "***********************************" << endl;
    char data4[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char str4[] = "SLHECCEIDEJFGGFIE";
    get_path(data4, 5, 8, str4);

    cout << "***********************************" << endl;
    char data5[] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char str5[] = "SGGFIECVAASABCEHJIGQEMS";
    get_path(data5, 5, 8, str5);

    cout << "***********************************" << endl;
    char data6[] = "AAAAAAAAAAAA";
    char str6[] = "AAAAAAAAAAAA";
    get_path(data6, 3, 4, str6);

    cout << "***********************************" << endl;
    char data7[] = "AAAAAAAAAAAA";
    char str7[] = "AAAAAAAAAAAAA";
    get_path(data7, 3, 4, str7);

    cout << "***********************************" << endl;
    char data8[] = "A";
    char str8[] = "A";
    get_path(data8, 1, 1, str8);

    cout << "***********************************" << endl;
    char data9[] = "A";
    char str9[] = "B";
    get_path(data9, 1, 1, str9);
}