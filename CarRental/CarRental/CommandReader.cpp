#include "CommandReader.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

CommandReader::CommandReader()
{
    string path = "data.txt";
    this->data.loadData(path);
}

CommandReader::~CommandReader()
{
    string path = "data.txt";
    this->data.saveData(path);
}

int CommandReader::ReadNextLine()
{
    string line;

    cout << "\n# ";

    cin.clear();
    cin.sync();
    getline(cin >> ws, line);

    if (line == "")
    {
        return -1;
    }

    this->command = this->Split(line, ' ');
    return 0;
}


int CommandReader::ExecuteCommand(bool isAdmin)
{
    switch (this->CheckCommand(isAdmin))
    {
    case 1:
        this->Add();
        break;

    case 2:
        this->Remove();
        break;

    case 3:
        this->Search();
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        return -1;  // exit from program

    case 7:
        this->AdminHelp();
        break;

    case 8:
        this->UserHelp();
        break;

    case 0:
        cout << "Brak dostepu" << endl;
        break;

    case -1:
        cout << "Niepoprawna komenda" << endl;
        break;

    case -2:
        cout << "Niepoprawny argument" << endl;
        break;
    }

    return 0;
}


int CommandReader::CheckCommand(bool isAdmin)
{
    // Check Add command arguments
    if (this->command[0] == "add")
    {
        if (isAdmin)
            return 1;
        return 0;
    }

    // Check remove command arguments
    if (this->command[0] == "remove")
    {
        if (isAdmin)
            return 2;
        return 0;
    }

    // Check search command arguments
    if (this->command[0] == "search")
    {
        if (this->command.size() > 1)
        {
            if (this->command[1] != "-all" && this->command[1][0] == '-')       // search -sortBy
            {
                this->command.insert(this->command.begin() + 1, "-all");        // convert to: search -all -sortBy

                if (this->command[2] != "-id" && this->command[2] != "-brand" && this->command[2] != "-color")
                {
                    return -2;                                                  // invalid sortBy argument
                }

                return 3;
            }
            else
            {
                if (this->command.size() == 2)      // search _id_
                {
                    this->command.push_back("-id"); // convert to: search _id_ -id
                    return 3;
                }

                if (this->command.size() > 2)       // search _id_ -sortBy
                {
                    if (this->command[2] != "-id" && this->command[2] != "-brand" && this->command[2] != "-color")
                    {
                        return -2;                  // invalid sortBy argument
                    }
                    return 3;
                }
            }

        }
        else
        {
            this->command.push_back("-all");
            this->command.push_back("-id");
            return 3;
        }

    }

    if (this->command[0] == "rent")
    {
        return 4;
    }

    if (this->command[0] == "unrent")
    {
        return 5;
    }

    if (this->command[0] == "exit")
    {
        return 6;
    }

    if (this->command[0] == "adminhelp")
    {
        if (isAdmin)
            return 7;
        return 0;
    }

    if (this->command[0] == "userhelp")
    {
        return 8;
    }

    return -1;
}


void CommandReader::Add()
{
    string arg = InputCarData();

    //string arg = "321abc;12;Mustang;konikWodny;czarny;2skowile;7litr;brak;";

    this->data.addCar(arg);

    cout << endl << "Dodano pomyslnie" << endl;
}

void CommandReader::Remove()
{
    string id;
    if (this->command.size() > 1)
    {
        id = this->command[1];
    }
    else
    {
        cout << endl << "Podaj numer rejestracyjny samochodu: " << endl;
        cin >> id;
    }

    if (data.find(id) == *new Car())
    {
        cout << endl << "Nie znaleziono samochodu" << endl;
        return;
    }
    data.removeCar(id);
    cout << endl << "Usunieto pomyslnie" << endl;

}

void CommandReader::Search()
{
    string id = this->command[1];
    string sortby = this->command[2];

    if (id != "-all")
    {
        if (data.find(id) != *new Car())
        {
            Car::printHeadLine();
            data.find(id).printData();
            return;
        }

        cout << "Nie znaleziono auta o numerze rejestracyjnym: " << id << endl;
        return;
    }
    else
    {
        if (sortby == "-id")
        {
            data.printData(1);
            return;
        }

        if (sortby == "-brand")
        {
            data.printData(2);
            return;
        }

        if (sortby == "-color")
        {
            data.printData(3);
            return;
        }
    }
}


void CommandReader::Rent()
{
    string id;
    if (this->command.size() > 1)
    {
        id = this->command[1];
    }
    else
    {
        cout << endl << "Podaj numer rejestracyjny samochodu: " << endl;
        cin >> id;
    }

    if (data.find(id) == *new Car())
    {
        cout << endl << "Nie znaleziono samochodu" << endl;
        return;
    }
    
    // rent
}


void CommandReader::Unrent()
{
    string id;
    if (this->command.size() > 1)
    {
        id = this->command[1];
    }
    else
    {
        cout << endl << "Podaj numer rejestracyjny samochodu: " << endl;
        cin >> id;
    }

    if (data.find(id) == *new Car())
    {
        cout << endl << "Nie znaleziono samochodu" << endl;
        return;
    }

    // unrent
}

void CommandReader::AdminHelp() {
    ifstream file("AdminHelp.txt");
    string line;
    while (file.eof() == 0) {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

void CommandReader::UserHelp() {
    ifstream file("UserHelp.txt");
    string line;
    while (file.eof() == 0) {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

string CommandReader::InputCarData()
{
    string arg = "", line;
    cout << endl << "Numer rejestracyjny: ";
    cin >> line;
    arg += line + ";";

    cout << endl << "Koszt: ";
    cin >> line;
    arg += line + ";";

    cout << endl << "Marka: ";
    cin >> line;
    line[0] = toupper(line[0]);
    arg += line + ";";

    cout << endl << "Model: ";
    cin >> line;
    line[0] = toupper(line[0]);
    arg += line + ";";

    cout << endl << "Kolor: ";
    cin >> line;
    arg += line + ";";

    cout << endl << "Moc: ";
    cin >> line;
    arg += line + ";";

    cout << endl << "Pojemnosc: ";
    cin >> line;
    arg += line + ";";

    cout << endl << "Ilosc cylindrow: ";
    cin >> line;
    arg += line + ";";

    return arg;
}


vector<string> CommandReader::Split(string arg, char space)
{
    std::string line;
    std::vector<std::string> vec;
    std::stringstream ss(arg);
    while (std::getline(ss, line, space))
    {
        vec.push_back(line);
    }

    return vec;
}