#include <iostream>
using namespace std;

double maxAvg(double& avg);

int main() {
    double avg = 0, max;
    max = maxAvg(avg);
    cout << "Max: " << max << " average: " << avg << endl;
    return 0;
}

double maxAvg(double& avg) {
    double val = 0, total = 0, count = 0, max = -1;
    cout << "Enter a value: (-1 to quit) " << endl;
    cin >> val;
    
    while(val != -1) {
        if (val > max) {
            max = val;
        }
        total += val;
        count++;
        
        cout << "Enter a value: (-1 to quit) " << endl;
        cin >> val;
    }
    avg = total / count;
    return max;
}