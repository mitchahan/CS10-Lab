#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    srand (time(0));
    
    string spanish[] = {"gato", "perro", "uno", "dos", "tres"};
    string english[] = {"cat", "dog", "one", "two", "three"};
    int score[] = {0, 0, 0, 0, 0};
    
    string answer;
    int correct = 0;
    while (correct < 10) {
        int index = rand() % 5;
        if (score[index] < 2) {
            cout << "What is the English of " << spanish[index] << "?" << endl;
            cin >> answer;
            if (answer == english[index]) {
                correct++;
                score[index] = score[index] + 1;
            } else {
                cout << "The right answer is: " << english[index] << endl;
            }
        }
    }
    
    cout << "Number of correct answers: " << correct << endl;
    
    return 0;
}