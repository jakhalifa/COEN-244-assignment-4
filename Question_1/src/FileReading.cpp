#include "../include/FileReading.h"

TA_list::TA_list(const std::string &file_name)
{
    TA_file_string = file_name;
    populate_list();
}

TA_list::~TA_list()
{
}

void TA_list::populate_list()
{
    loadFromFile();
    saveToFile();
}

void TA_list::loadFromFile()
{
    std::ifstream inFile(TA_file_string);

    if (!inFile)
    {
        list_of_TAs.clear();
        return;
    }

    int file_TA_count;
    inFile >> file_TA_count;
    if (file_TA_count > 100)
    {
        std::cout << "limit exceeded, only registering first 100 TAs";
        list_of_TAs.clear();
        int temp_id, temp_Hire_Year, temp_number_of_working_hours;
        std::string temp_first_name, temp_last_name, temp_Classification;
        for (int i = 0; i < 100; i++)
        {
            inFile >> temp_id >> temp_first_name >> temp_last_name >> temp_Hire_Year >> temp_Classification >> temp_number_of_working_hours;
            if (temp_Classification != "Alum")
                list_of_TAs.emplace_back(temp_id, temp_first_name, temp_last_name, temp_Hire_Year, temp_Classification, temp_number_of_working_hours);
        }
        return;
    }

    list_of_TAs.clear();
    int temp_id, temp_Hire_Year, temp_number_of_working_hours;
    std::string temp_first_name, temp_last_name, temp_Classification;

    while (inFile >> temp_id >> temp_first_name >> temp_last_name >> temp_Hire_Year >> temp_Classification >> temp_number_of_working_hours)
    {
        if (temp_Classification != "Alum")
            list_of_TAs.emplace_back(temp_id, temp_first_name, temp_last_name, temp_Hire_Year, temp_Classification, temp_number_of_working_hours);
    }
    return;
}

void TA_list::saveToFile()
{
    std::ofstream outFile(TA_file_string);
    outFile << list_of_TAs.size() << "\n";

    for (const auto &temp_TA : list_of_TAs)
    {
        outFile << temp_TA.getall();
    }
}

void TA_list::AddNewTa()
{
    if (list_of_TAs.size() >= 100)
    {
        std::cout << "max size of TAs reached\n";
        return;
    }

    int temp_id = getUniqueID();
    std::string temp_first_name = getValidString("Enter first name: ");
    std::string temp_last_name = getValidString("Enter last name: ");
    int temp_Hire_Year = getValidInt("Enter hire year: ");
    std::string temp_Classification;
    while (true)
    {
        std::string temp_str = getValidString("Enter classification ");
        if (temp_str != "Grad")
            continue;
        temp_Classification = temp_str;
        break;
    }
    int temp_number_of_working_hours = getValidInt("Enter number of working hours: ");

    list_of_TAs.emplace_back(temp_id, temp_first_name, temp_last_name, temp_Hire_Year, temp_Classification, temp_number_of_working_hours);
    saveToFile();
}

void TA_list::clean()
{
    list_of_TAs.clear();
}

int TA_list::getUniqueID()
{
    int id;

    while (true)
    {
        bool duplicate = false;
        id = getValidInt("Enter student ID: ");

        for (const auto &check : list_of_TAs)
        {
            if (check.getID() == id)
            {
                std::cout << "ID already in use, please try again\n";
                duplicate = true;
                break;
            }
        }
        if (duplicate)
            continue;
        return id;
    }
}

int getValidInt(const std::string &prompt)
{
    int value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "Please enter a valid integer\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else if (value < 0)
        {
            std::cout << "negative values not accepted for this field\n";
            continue;
        }
        return value;
    }
}

std::string getValidString(const std::string &prompt)
{
    std::string value;

    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value.empty())
        {
            std::cout << "Please enter a valid string\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}