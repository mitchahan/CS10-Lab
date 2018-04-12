#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double g = 9.81, angle, speed, height, y; 
    int x;
    
    cout << "Enter the angle of the projectile: " << endl;
    cin >> angle;
    
    cout << "Enter the speed of the projectile: " << endl;
    cin >> speed;
    
    cout << "Enter the initial height of the projectile: " << endl;
    cin >> height;
    
    y = height + (x * tan(angle)) - ((g * pow(x, 2)) / (2 * pow(speed * cos(angle), 2)));
    for (x = 0; y >= 0;) {
        cout << "X: " << x << " Y: " << y << endl;
        x++;
        y = height + (x * tan(angle)) - ((g * pow(x, 2)) / (2 * pow(speed * cos(angle), 2)));
    }
    
}