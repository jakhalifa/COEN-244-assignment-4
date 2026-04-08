#pragma once

class TA {
private:
    int Student_Id;
    char *First_Name;
    char *Last_Name;
    int Hire_Year;
    char *Classification;
    int number_of_working_hours;

public:
    TA(int, char*, char*, int, char*, int);
    ~TA() = default;
    char* getClassification() const;

};