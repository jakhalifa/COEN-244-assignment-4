#pragma once
#include <fstream>
#include <iostream>
#include <TeachingAssistant.h>

class TA_list {
private:
    TA *list_of_TAs[100];
    std::fstream TA_file;

public:
    TA_list();
    TA_list(std::string);
    ~TA_list();
    void populate_list();
    void AddNewTa();
    void clean();
    
};