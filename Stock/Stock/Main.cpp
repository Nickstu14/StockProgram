# include <iostream>
# include <fstream>
# include <string>
#include <conio.h>
# include <vector>

class Stock
{
public:
	std::string m_partnumber;
	std::string m_name;
	int m_quantity;
	int m_LowLimit;
};


int Menu(int _Val);
int Input(int _Min, int _Max);
void Clearscreen();
void MasterFile();
std::vector<Stock> ReadBuildFile(std::string _val);
void InputStock(int _val);
void ReadStockFile();
void WriteStock();
void ShowStock();
void Builds(int _val);
void Damages(int _val);
void CheckStock();




std::string fileName = "MasterFile.txt";
std::string stockFileName = "StockFile.txt";
std::vector<std::string> m_MasterList;
std::vector<Stock> m_stock;



int main()
{
	Clearscreen();
	MasterFile();
	ReadStockFile();

	do {
		CheckStock(); //always check for low stock

		switch (Menu(0))
		{
		case 1: InputStock(Menu(1));
			WriteStock();
			break;
		case 2: Builds(Menu(2));
			WriteStock();
			break;
		case 3: ShowStock();
			break;
		case 4: Damages(Menu(1));
			WriteStock();
			break;
		case 5: exit(0);
			break;
		}
		


	} while (1);


}



int Input(int _Min, int _Max)
{
	int val;
	std::cout << "Choice: ";
	std::cin >> val;
	do
	{
		if (std::cin.fail())
		{
			std::cout << "Please enter an number value: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			if ((val < _Min) || (val > _Max))
			{
				//print error
				std::cout << "\nPlease enter between " << _Min << " & " << _Max << ": ";
			}
		}
	} while ((val < _Min) || (val > _Max));
	Clearscreen();
	return val;
}

void Clearscreen()
{
	for (int i = 0; i < 50; i++)
		std::cout << std::endl;
}

int Menu(int _val)
{
	int m_min = 0, m_max = 0;
	int i = 0;
	switch (_val)
	{
	case 0: std::cout << "1 - Input Stock\n2 - Quantity Build\n3 - Stock Levels\n4 - Damages\n5 - Quit\n"; //Main Menu
		m_min = 1;
		m_max = 5;
		break;
	case 1:

		for (auto it = m_stock.begin(); it != m_stock.end(); it++)
		{
			std::cout << i++ << " " << it->m_name << std::endl;
		}

		m_min = 0;
		m_max = m_stock.size();
		break;
	case 2:
		for (int i = 0; i < m_MasterList.size(); i++)
		{
			std::cout << i << " " << m_MasterList[i] << std::endl;
		}

		m_min = 0;
		m_max = m_MasterList.size();
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
		std::string m_name;
		while (file >> m_name)
		{
			m_MasterList.push_back(m_name);
		}
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
		while (file >> stock.m_partnumber >> stock.m_name >> stock.m_quantity >> stock.m_LowLimit)
		{
			m_stock.push_back(stock);
		}
	}
	else
	{
		std::cout << "Can't find file: " << fileName << std::endl;
		//Create New masterFile?	add Y/N		if Y create if N Exit program
	}
	file.close();
}
void WriteStock()
{
	std::ofstream file(stockFileName);

	if (file.is_open())
	{
		for (auto it = m_stock.begin(); it != m_stock.end(); it++)
		{
			file << it->m_partnumber << " " << it->m_name << " " << it->m_quantity << it->m_LowLimit << std::endl;
		}
	}
	else
	{
		std::cout << "Can't find file: " << fileName << std::endl;
		//Create New masterFile?	add Y/N		if Y create if N Exit program
	}
	file.close();
}

void Builds(int _val)
{
	std::vector<Stock> m_tempstocks;
	m_tempstocks = ReadBuildFile(m_MasterList[_val]);

	int m_val;
	std::cout << "\nQuantity: ";
	std::cin >> m_val;
	//Find temp name with stock name
	for (int i = 0; i < m_val; i++)
	{

		for (auto it = m_stock.begin(); it != m_stock.end(); it++)
		{
			for (auto is = m_tempstocks.begin(); is != m_tempstocks.end(); is++)
			{
				if (it->m_name == is->m_name)
					it->m_quantity -= is->m_quantity;
			}
		}
	}
}

std::vector<Stock> ReadBuildFile(std::string _val)
{
	std::vector<Stock> m_tempvector;
	Stock m_tempStock;
	std::ifstream file(_val + ".txt");

	if (file.is_open())
	{

		while (file >> m_tempStock.m_partnumber >> m_tempStock.m_name >> m_tempStock.m_quantity)
		{
			m_tempvector.push_back(m_tempStock);
		}
	}
	else
	{
		std::cout << "Can't find file: " << fileName << std::endl;
		//Create New masterFile?	add Y/N		if Y create if N Exit program
	}
	file.close();
	return m_tempvector;
}

void InputStock(int _val)
{
	int m_Val;
	std::cout << "Please enter Quantity for " << m_stock[_val].m_name << ": ";
	std::cin >> m_Val;
	m_stock[_val].m_quantity += m_Val;
}

void ShowStock()
{
	//std::cout << "Part Name\t|Qty" << std::endl;
	for (auto it = m_stock.begin(); it != m_stock.end(); it++)
	{
		std::cout << /*it->m_partnumber << "\t" <<*/ it->m_name << "\t" << it->m_quantity << std::endl;
	}
	std::cout << std::endl << std::endl;

	char val;
	std::cout << "Press any button to continue: ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getchar();
}

void Damages(int _val)
{
	int m_val;
	std::cout << "Please enter the quantity for " << m_stock[_val].m_name << ": ";
	std::cin >> m_val;
	m_stock[_val].m_quantity -= m_val;
}

void CheckStock()
{
	//Clearscreen();
	std::cout << "\nStock Levels Low" << std::endl << "================" << std::endl;
	for (auto it = m_stock.begin(); it != m_stock.end(); it++)
	{
		
		if (it->m_LowLimit >= it->m_quantity)
		{
			std::cout << it->m_partnumber << "\t" << it->m_name << "\t" << it->m_quantity << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

/*Notes

Read and wrte to the stock file is done
Show stock is done
add stock is done but with no validation



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