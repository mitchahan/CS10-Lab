#include <iostream>
#include <string>
using namespace std;

struct Date {
    int month, day, year;
};

struct Item {
    string name;
    string artist;
    double price;
    string tracks[100];
    int used;
    Date d;
};

void printItem(Item it);
void initializeItem(Item & it);
double fillCart(Item a[], int size);

int main() {
    Item amazon[3] = {{"Slaughterhouse 5", "Kurt Vonnegut", 7.99},
    {"Let it Be", "The Replacements", 11.49,{"I Will Dare", "Favorite Thing", "We're Comin' Out",
            "Tommy Gets His Tonsils Out","Androgynous","Black Diamond","Unsatisfied",
            "Seen Your Video","Gary's Got","Sixteen Blue","Answering Machine"}, 11, {10, 2, 1984}},
    {"Let it Be", "The Beatles", 16.29, {"Two Of Us", "Dig A Pony","Across The Universe",
            "I Me Mine","Dig It","Let It Be","Maggie Mae","I've Got A Feeling","One After 909",
            "The Long And Winding Road","For You Blue","Get Back"}, 12, {5, 11, 1970}}};

    cout << "Total cost: " << fillCart(amazon, 3) << endl;
    return 0;
}

void printItem(Item it) {
    cout << "Item: " << it.name << ", by " << it.artist << " for $" << it.price << endl;
    cout << "Release Date: " << it.d.month << "/" << it.d.day << "/" << it.d.year << endl;
    cout << "Contents: ";
    for (int i = 0; i < it.used - 1; i++) {
        cout << it.tracks[i] << endl;
    }
}

void initializeItem(Item & it) {
    string dummy, track;
    int count = 0;
    cout << "Enter Item Name: " << endl;
    getline(cin, it.name);
    getline(cin, dummy);
    cout << "Enter Author/Artist: " << endl;
    getline(cin, it.artist);
    cout << "Enter the Price: " << endl;
    cin >> it.price;
    cout << "Enter the tracks/chapters: (enter -1 when done)" << endl;
    while (track != "-1") {
        getline(cin, it.tracks[count]);
        track = it.tracks[count];
        count++;
    }
    it.used = count;
    cout << "Enter Release Date: (Month Day Year)" << endl;
    cin >> it.d.month >> it.d.day >> it.d.year;
}

double fillCart(Item a[], int size) {
    string answer;
    double count = 0;
    for (int i = 0; i < size; i++) {
        cout << "Item: " << a[i].name << ", by " <<  a[i].artist << " for $" << a[i].price << endl;
        cout << "Would you like to \"purchase\", see more \"details\", or \"pass\"?" << endl;
        cin >> answer;
        if (answer == "purchase") {
            count += a[i].price;
        } else if (answer == "details") {
            printItem(a[i]);
            cout << "Would you like to purchase or pass?" << endl;
            cin >> answer;
            if (answer == "purchase") {
                count += a[i].price;
            }
        }
    }
    return count;
}