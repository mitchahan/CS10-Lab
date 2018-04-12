#include <iostream>
using namespace std;

void factarr(int a[], bool fact[], int size);
bool isfact(int n);

int main() {
    int array[6] = {6, 10, 36, 9, 13, 26};
    bool fact[6];
    
    factarr(array, fact, 6);
    
    
    return 0;
}

void factarr(int a[], bool fact[], int size) {
    for (int i = 0; i < size; i++) {
        bool facts = isfact(a[i]);
        fact[i] = facts;
    }
    
    for (int x = 0; x < size; x++) {
        cout << fact[x] << " ";
        cout << a[x] << endl;
    }
}

bool isfact(int n) {
    bool is = false;
    int fact = 1;
    
    for (int i = 1; i < n + 2; i++) {
        if (fact == n) {
            is = true;
        }
        fact *= i;
    }
    
    return is;
}