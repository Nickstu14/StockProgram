# include <iostream>
# include <fstream>
# include <string>
# include <vector>

int Menu(int _Val);
int Input(int _Min, int _Max);
void MasterFile();
void ReadFile();
void WriteFile();

std::string fileName = "MasterFile.txt";
std::vector<std::string> m_MasterList;

int main()
{
	MasterFile();

	do {
		switch (Menu(0))
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: exit(0);
			break;
		}



	} while (1);


}



int Input(int _Min, int _Max)
{
	int val;
	std::cout << "Choice: ";
	do
	{
		std::cin >> val;
		if ((val < _Min) || (val > _Max))
		{
			//print error
			std::cout << "\nPlease enter between " << _Min << " & " << _Max << ": ";
		}
	} while ((val < _Min) || (val > _Max));

	return val;
}

int Menu(int _val)
{
	int m_min = 0, m_max = 0;

	switch (_val)
	{
	case 0: std::cout << "1 - Input Stock\n2 - Quantity Build\n3 - Stock Levels\n4 - Quit\n"; //Main Menu
		m_min = 1;
		m_max = 4;
		break;
	case 1:	//Sub Menu
		break;
	}
	return Input(m_min, m_max);
}

void MasterFile()
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		do
		{
			char currentChar;
			std::string m_FileName;
			do
			{
				file >> currentChar;
				std::cout << file.eof();
				if ((currentChar != '\n')&&(!file.eof()))
				{
					//populate the file string
					m_FileName += currentChar;
				}
					
			} while ((currentChar != '\n') && (!file.eof()));
			//add the file name to the Master list
			m_MasterList.push_back(m_FileName);
		} while (!file.eof());
	}
	else
	{
		std::cout << "Can't find file: " << fileName << std::endl;
		//Create New masterFile?	add Y/N		if Y create if N Exit program
	}
}

void ReadFile()
{

}

void WriteFile()
{

}







/*
//////////Creating an empty file and populating it /////////
// using ofstream constructors.
#include <iostream>
#include <fstream>

std::ofstream outfile ("test.txt");

outfile << "my text here!" << std::endl;

outfile.close();
*/