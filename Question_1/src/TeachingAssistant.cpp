#include "../include/TeachingAssistant.h"
#include <string.h>
#include <stdlib.h>

TA::TA(){}

TA::TA(int addStudent_Id, std::string addFirst_Name, std::string addLast_Name, int addHire_Year, std::string addClassification, int addnumber_of_working_hours)
    : Student_Id(addStudent_Id), First_Name(addFirst_Name), Last_Name(addLast_Name), Hire_Year(addHire_Year), Classification(addClassification), number_of_working_hours(addnumber_of_working_hours) {}

std::string TA::getClassification() const {
    return Classification;
}

int TA::getID() const {
    return Student_Id;
}
