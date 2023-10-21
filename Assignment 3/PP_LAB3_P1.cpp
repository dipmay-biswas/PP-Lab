#include <iostream>
#include <string>
#include <iomanip>

class Student{
private:
    std::string name;
    int age;
    std::string department;
    int year;

public:
    void PrintStudentData(){
        std::cout << std::setw(12) << "Name:  " << name << std::endl;
        std::cout << std::setw(12) << "Age:  " << age << std::endl;
        std::cout << std::setw(12) << "Department:  " << department << std::endl;
        std::cout << std::setw(12) << "Year:  " << year << std::endl;
        
    }

    void ReadStudentData(){
        std::cout << "Enter name of the student: ";
        std::getline(std::cin >> std::ws, name);

        std::cout << "Enter the age of the student: ";
        std::cin >> age;

        std::cout << "Enter the department of the student: ";
        std::getline(std::cin >> std::ws, department);

        std::cout << "Enter the year of the student: ";
        std::cin >> year;
    }
};

int main()
{   
    short n = 0;
    std::cout << "Enter the number of students: ";
    std::cin >> n;
    Student reg[n];

    for(int i = 0; i < n; i++){
        reg[i].ReadStudentData();
    }

    for(int i = 0; i < n; i++){
        reg[i].PrintStudentData();
    }
}