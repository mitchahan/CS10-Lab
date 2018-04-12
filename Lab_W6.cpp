#include <iostream>
using namespace std;

int minVal(int array[], int n);

int main() {
    int array[] = {-10, 6, 3, 32, 11, 7};
    int n = 6;
    int min = minVal(array, n);
    cout << "The minimum value is: " << min << endl;
    return 0;
}

int minVal(int array[], int n) {
    int min = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}