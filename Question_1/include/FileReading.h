#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <TeachingAssistant.h>

class TA_list {
private:
    std::vector<TA*> list_of_TAs;
    std::fstream TA_file;

public:
    TA_list();
    TA_list(std::string &);
    ~TA_list();
    void populate_list();
    void AddNewTa();
    void clean();
    
};