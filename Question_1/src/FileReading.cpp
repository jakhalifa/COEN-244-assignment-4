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
                
            } else {
                std::cout << "Invalid input, please input 'y' to continue loop";
                std::cin >> check;
                if(check=='y')
                    continue;
                break;
            }
            

        }
    }

    TA_list::TA_list(std::string){
        populate_list()
    }

    TA_list::~TA_list(){

    }

    void TA_list::populate_list(){

    }

    void TA_list::AddNewTa(){

    }   

    void TA_list::clean(){
        if(){

        }
    }