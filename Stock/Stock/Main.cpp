# include <iostream>
# include <fstream>
# include <string>
# include <vector>

int Menu(int _Val);
int Input(int _Min, int _Max);
void MasterFile();
void ReadFile();
void WriteFile();
void InputStock();
void ReadStockFile();
void ShowStock();

class Stock
{
public:
	std::string m_partnumber;
	std::string m_name;
	int m_quantity;
};


std::string fileName = "MasterFile.txt";
std::string stockFileName = "StockFile.txt";
std::vector<std::string> m_MasterList;
std::vector<Stock> m_stock;



int main()
{
	MasterFile();
	ReadStockFile();
	do {
		switch (Menu(0))
		{
		case 1: InputStock();
			break;
		case 2:
			break;
		case 3: ShowStock();
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
	case 1:	std::cout << "1 - UK 4 Gang 1 Meter\n";
		break;
	}
	return Input(m_min, m_max);
}

void MasterFile()
{
	/*The master file holds all the file names of the build files*/
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
				if ((currentChar != '\n') && (!file.eof()))
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

void ReadStockFile()
{

	std::ifstream file(stockFileName);

	if (file.is_open())
	{
		Stock stock;
		while (file >> stock.m_partnumber >> stock.m_name >> stock.m_quantity)
		{
			m_stock.push_back(stock);
		}
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

void InputStock()
{
	Menu(1);
}

void ShowStock()
{
	std::cout << "|Part Numbers\t|Name\t|Qty" << std::endl;
	for (auto it = m_stock.begin(); it != m_stock.end(); it++)
	{
		std::cout << it->m_partnumber << "\t" << it->m_name << "\t" << it->m_quantity << std::endl;
	}

}


/*Notes

find a way to break up the chars and ints from the stock file.


*/





/*
//////////Creating an empty file and populating it /////////
// using ofstream constructors.
#include <iostream>
#include <fstream>

std::ofstream outfile ("test.txt");

outfile << "my text here!" << std::endl;

outfile.close();
*/