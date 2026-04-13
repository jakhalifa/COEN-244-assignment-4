#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <TeachingAssistant.h>

class TA_list {
private:
    std::vector<TA> list_of_TAs;
    std::string TA_file_string;

public:
    TA_list(const std::string&);
    ~TA_list();
    void populate_list();
    void loadFromFile();
    void saveToFile();
    void AddNewTa();
    void clean();
    int getUniqueID();

};

int getValidInt(const std::string&);
std::string getValidString(const std::string&);