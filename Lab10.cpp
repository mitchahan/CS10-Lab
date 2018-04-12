#include <iostream>
#include <string>
#include <vector>
//using namespace std;


struct Transcript
{
    double grades[100];
    std :: string classes[100];
    std :: size_t num;
};

struct Student
{
		typedef int i1;
		typedef std :: string s1;
    s1 name;
    i1 idNumber;
    i1 year;
    Transcript t;
};

void initializeStudent(Student& s);
Student initializeStudent();
Student initializeStudent(std :: string n);
Student initializeStudent(std :: size_t i);

void fillTranscript(Transcript& t);
void printStudent(const Student& s);
void printTranscript(const Transcript& t);

int main()
{
    Student me;
    initializeStudent(me);
    printStudent(me);
    return 0;
}

void initializeStudent(Student& s)
{
    std :: string dummy;
    std :: cout << "please enter a name"<<std :: endl;
    getline(std :: cin, s.name);
    std :: cout << "please enter an ID number"<<std :: endl;
    std :: cin >>s.idNumber;
    std :: cout<<"Please enter your year as a number 1-4"<<std :: endl;
    std :: cin>>s.year;
    getline(std :: cin, dummy);
    fillTranscript(s.t);
}

Student initializeStudent() {
	Student st1 = {" ", 0, -1, {}};
	return st1;
}

Student initializeStudent(std :: string n) {
	Student st1 = {n, 0, -1, {}};
	return st1;
}

Student initializeStudent(std :: size_t i) {
	Student st1 = {" ", i, -1, {}};
	return st1;
}

void fillTranscript(Transcript& t)
{
    std :: string course;//note - class is a reserved word
    double grade = 0;
    std :: string dummy;

    std :: cout << "Please enter the name of the next class, done when done"<<std :: endl;
    getline(std :: cin, course);
    t.num = 0;
    while(course != "done")
    {
        std :: cout<<"Please enter your grade in "<<course<<std :: endl;
        std :: cin >>grade;
        getline(std :: cin, dummy);//consume


        t.classes[t.num] = course;
        t.grades[t.num] = grade;
        t.num++;
        std :: cout << "Please enter the name of the next class, done when done"<<std :: endl;
        getline(std :: cin, course);
    }

}

void printStudent(const Student& s)
{
    std :: cout << "Name:"<<s.name<<std :: endl;
    std :: cout << "ID number:"<<s.idNumber<<std :: endl;
    std :: cout << "year:"<<s.year<<std :: endl;
    printTranscript(s.t);
}

void printTranscript(const Transcript& t){
    std :: cout<<"Transcript: "<<std :: endl;
    for(std :: size_t i=0; i<t.num; i++){
        std :: cout<<t.classes[i]<<": "<<t.grades[i]<<std :: endl;
    }
}