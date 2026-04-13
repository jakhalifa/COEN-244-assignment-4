#include "../include/FileReading.h"

using namespace std;

TA_list::TA_list()
{
    bool loop_uphold(true);
    char check;
    string file_name;

    while (loop_uphold)
    {
        cout << "Please input the name of the TA file: ";
        cin >> file_name;
        TA_file.open(file_name, ios::in | ios::out);
        if (!TA_file)
        {
            cout << "TA file not found, try again." << endl;
            continue;
        }
        loop_uphold = false;
        populate_list();
        cout << "file opened succesfully and TA list populated." << endl;
    }
}

TA_list::TA_list(std::string &file_name)
{
    TA_file.open(file_name, std::ios::in | std::ios::out);
    populate_list();
}

TA_list::~TA_list()
{
    TA_file.close();
}

void TA_list::populate_list()
{
    int TA_count;
    TA_file >> TA_count;
}

/* the logic here allows for loops of specific questions if input is invalid */
void TA_list::AddNewTa()
{
    if (list_of_TAs.size() >= 100)
    {
        std::cout << "max size of TAs reached." << endl;
        return;
    }
    bool loop_uphold(true);
    int temp_switch(1);

    string temp_First_Name, temp_Last_Name, Classification;
    int temp_ID, temp_Hire_Year, temp_number_of_working_hours;

    while (loop_uphold)
    {
        switch (temp_switch)
        {
            case 1:
                cout << "Please input the student ID: ";
                cin >> temp_ID;

                // check if ID already in use
                if (find(TA_IDs.begin(), TA_IDs.end(), temp_ID) != TA_IDs.end())
                {
                    char check_loop;
                    cout << "student ID already in use, please input 'y' to continue loop." << endl;
                    cin >> check_loop;
                    if (check_loop != 'y')
                        loop_uphold = false;
                    continue;
                }
                temp_switch = 2;
                continue;
            case 2:
                cout << "Please input the student first name: ";
                cin >> temp_First_Name;

                if (temp_First_Name.empty())
                {
                    char check_loop;
                    cout << "name cannot be empty, please input 'y' to continue loop." << endl;
                    cin >> check_loop;
                    if (check_loop != 'y')
                        loop_uphold = false;
                    continue;
                }
                temp_switch = 3;
                continue;
            case 3:
                cout << "Please input the student last name: ";
                cin >> temp_Last_Name;

                if (temp_Last_Name.empty())
                {
                    char check_loop;
                    cout << "last name cannot be empty, please input 'y' to continue loop." << endl;
                    cin >> check_loop;
                    if (check_loop != 'y')
                        loop_uphold = false;
                    continue;
                }
                temp_switch = 4;
                continue;
            case 4:
                cout << "Please input the hire year: ";
                cin >> temp_Hire_Year;
                temp_switch = 5;
                continue;
            case 5:
                cout << "Assumed to be a current student and not alum..." << endl;
                temp_switch = 6;
                continue;
            case 6:
                cout << "Please input the number of working hours: ";
                cin >> temp_number_of_working_hours;
                loop_uphold = false;
                break;
        default:
            break;
        }
    }
    char new_row[256] = { 0 };
    snprintf(new_row, sizeof(new_row), "%u %s %s %u Grad %u\n", temp_ID, temp_First_Name.c_str(), temp_Last_Name.c_str(), temp_Hire_Year, temp_number_of_working_hours);
    cout << "Adding...: " << new_row;
    /*
        Add it here....
    */
}

void TA_list::clean()
{
    list_of_TAs.clear();
}