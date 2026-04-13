#include "../include/FileReading.h"
#include <iostream>

int main()
{
    std::string temp_name = getValidString("input the txt file name: ");
    TA_list my_list(temp_name);

    my_list.AddNewTa();
}
