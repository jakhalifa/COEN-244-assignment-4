#pragma once
#include <string>

class TA {
private:
    int Student_Id;
    std::string First_Name;
    std::string Last_Name;
    int Hire_Year;
    std::string Classification;
    int number_of_working_hours;

public:
    TA();
    TA(int, std::string, std::string, int, std::string, int);
    ~TA() = default;
    std::string getClassification() const;
    int getID() const;

};