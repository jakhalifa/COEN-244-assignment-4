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

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "invalid input, try again\n";
                continue;
            }
            std::ifstream inFile(file_name);

            if(!inFile){
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
            TA_file = file_name;
            std::cout << "file " << TA_file << " successfully created" << std::endl;

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
    TA_file = file_name;
    populate_list();
}

TA_list::~TA_list(){
}

void TA_list::populate_list(){
    int TA_count;
    std::ifstream inFile(TA_file);
    inFile >> TA_count;


}

void TA_list::AddNewTa(){
    if(list_of_TAs.size()>=100){
        std::cout << "max size of TAs reached\n";
        return;
    } 

    int temp_id = getUniqueID();
    std::string temp_first_name = getValidString("Enter first name: ");
    std::string temp_last_name = getValidString("Enter last name: ");
    int temp_Hire_Year = getValidInt("Enter hire year: ");
    std::string temp_Classification = getValidString("Enter calssification ");
    int temp_number_of_working_hours = getValidInt("Enter number of working hours: ");

    TA temp_TA(temp_id, temp_first_name, temp_last_name, temp_Hire_Year, temp_Classification, temp_number_of_working_hours);
    list_of_TAs.push_back(temp_TA);

}   

void TA_list::clean(){
    list_of_TAs.clear();
}

int TA_list::getUniqueID(){
    int id;

    while(true){
        bool duplicate = false;
        id = getValidInt("Enter student ID: ");

        for(auto& check : list_of_TAs){
            if(check.getID()==id){
                std::cout << "ID already in use, please try again\n";
                duplicate = true;
                break;
            }
        }
        if(duplicate)
            continue;
        return id;
    }
}


int getValidInt(const std::string& prompt){
    int value;

    while(true){
        std::cout << prompt;
        std::cin >> value;

        if(std::cin.fail()){
            std::cout << "Please enter a valid integer\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}


std::string getValidString(const std::string& prompt){
    std::string value;

    while(true){
        std::cout << prompt;
        std::cin >> value;

        if(std::cin.fail() || value.empty()){
            std::cout << "Please enter a valid string\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}