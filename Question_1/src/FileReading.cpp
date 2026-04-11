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
        bool loop_uphold(true);
        int temp_switch(1);

        while(loop_uphold){
            std::string temp_First_Name, temp_Last_Name, Classification;
            int temp_ID, temp_Hire_Year, temp_number_of_working_hours;

            switch (temp_switch)
            {
                case 1:
                    std::cout << "Please input the student ID";
                    std::cin >> temp_ID;

                    //check if ID already in use
                    if(std::cin.fail()){
                        std::cout << "Invalid input";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        continue;
                    } else if(std::find(TA_IDs.begin(), TA_IDs.end(), temp_ID) != TA_IDs.end()){
                        char check_loop;
                        std::cout << "student ID already in use, please input 'y' to continue loop";
                        std::cin >> check_loop;
                        if(check_loop!='y')
                            loop_uphold = false;
                        continue;
                    }   
                    break;
            
                default:
                    
                    break;
            }
            
       }
        
    }   

    void TA_list::clean(){
        list_of_TAs.clear();
    }