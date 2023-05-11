#include <iostream>
#include "car.h"
#include <fstream>
#include <map>

using namespace std;

class Data {
	private:
		string curentFilename;
	public:
		map <string, Car> carData;
		
		void loadData(string filename){
			carData.clear();

			ifstream file;
			file.open(filename);
			string tempString;
			while (!file.eof()) {
				getline(file, tempString);
				Car tempCar(tempString);
				carData.insert({ tempCar.getId(),tempCar });
			}

			file.close();
		}
		void saveData(string filename){
			if (filename == "") filename = curentFilename;
			ofstream file;
			file.open(filename);
			for (pair<string, Car> x : carData) {
				file << x.second.dataToString() << endl;
			}
			file.close();
		}
};

int main()
{
}