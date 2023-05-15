#include "CommandReader.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

CommandReader::CommandReader()
{
    string path = "mojaWymarzonaStajnia.txt";
    this->data.loadData(path);
}

CommandReader::~CommandReader()
{

}

int CommandReader::ReadNextLine()
{
	string line;

    cout << "Wpisz komende: \n";

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
    switch (this->CheckCommand())
    {
    case 1:
        this->Add();
        break;

    case 2:
        this->Remove(this->command[1]);
        break;

    case 3:
        this->Search(this->command[1]);
        break;

    case 4:
        break;

    case 5:
        break;

    case 0:
        break;

    case -1:
        break;

    }

    return 0;
}


int CommandReader::CheckCommand()
{
    if (this->command[0] == "add")
    {
        return 1;
    }

    if (this->command[0] == "remove")
    {
        if (this->command.size() > 1)
        {
            return 2;
        }
        
        cout << "Invalid ID number";
        return 0;
    }

    if (this->command[0] == "search")
    {
        if (this->command.size() > 1)
        {
            return 3;
        }

        cout << "Invalid ID number";
        return 0;
    }

    if (this->command[0] == "rent")
    {
        if (this->command.size() > 1)
        {
            return 4;
        }

        cout << "Invalid ID number";
        return 0;
    }

    if (this->command[0] == "unrent")
    {
        if (this->command.size() > 1)
        {
            return 5;
        }

        cout << "Invalid ID number";
        return 0;
    }

    cout << "Invalid command or argument";
    return -1;
}


void CommandReader::Add()
{
    string arg = InputCarData();

    //string arg = "321abc;12;Mustang;konikWodny;czarny;2skowile;7litr;brak;";
    auto newCar = new Car(arg);

    this->data.carData.insert({ newCar->getId(), *newCar });

    delete(newCar);
}

void CommandReader::Remove(string id)
{

}

void CommandReader::Search(string id)
{
    if (id == "-all")
    {
        this->data.printData();
        return;
    }

    if (this->data.carData.find(id) == this->data.carData.end())
    {
        cout << "Nie znaleziono aut" << endl;
        return;
    }

    auto car = this->data.carData[id];

    cout << car.dataToString() << endl;
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
    arg += line + ";";

    cout << endl << "Model: ";
    cin >> line;
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

