#include "../include/FileReading.h"

    TA_list::TA_list(){
        bool loop_uphold(true);
        char check;
        std::string file_name;

        while (loop_uphold){
            std::cout << "Is there already a TA file? (y/n)";
            std::cin >> check;
            if(check=='y'){
                std::cout << "Please input the name of the TA file";
                std::cin >> file_name;
                TA_file.open(file_name, std::ios::in | std::ios::out);

                if(!TA_file){
                    std::cout << "TA file not found, try again";
                    continue;
                }

                populate_list();
                std::cout << "file opened succesfully and TA list populated";

            } else if(check=='n'){
                std::cout << "Please input the name of your TA file";
                std::cin >> file_name;
                std::ofstream temp(file_name);
                temp << "0" << std::endl;
                temp.close();
                TA_file.open(file_name, std::ios::in | std::ios::out);

            } else {
                std::cout << "Invalid input, please input 'y' to continue loop";
                std::cin >> check;
                if(check=='y')
                    continue;
                break;
            }
            

        }
    }

    TA_list::TA_list(std::string &file_name){
        TA_file.open(file_name, std::ios::in | std::ios::out);
        populate_list();
    }

    TA_list::~TA_list(){
        TA_file.close();
    }

    void TA_list::populate_list(){
        int TA_count;
        TA_file >> TA_count;
    }

    void TA_list::AddNewTa(){
        if(list_of_TAs.size()>=100){
            std::cout << "max size of TAs reached";
            return;
        }
        
    }   

    void TA_list::clean(){
        list_of_TAs.clear();
    }