#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <map>


using namespace std;



void main()
{
	setlocale(LC_ALL, "");

	fstream f_files;
	fstream t_files;
	string s_from;
	string s_where;

	cout << "Nazwa pliku normalnego" << endl;
	cin >> s_from;
	cout << "Nazwa pliku zaszyfrowanego" << endl;
	cin >> s_where;
	

	f_files.open(s_from);
	t_files.open(s_where);

	string f_string;
	string line;

	if (f_files.good())
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		while (getline(f_files, line))
		{

			f_string += line + '\n';
		}
	}
	else
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
	}

	for (auto& i : f_string)
	{
		if (i > 95) i -= 32;
	}

	string t_string;


	if (t_files.good())
	{
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		while (getline(t_files, line))
		{

			t_string += line + '\n';
		}
	}
	else
	{
		cout << "Dostep do pliku zostal zabroniony!" << endl;
	}


	for (auto& i : t_string)
	{
		if (i > 95) i -= 32;
	}
	
	map<char, int> t_map;
	auto t_all = 0;
	for (auto& i : t_string)
	{
		if(65 <= i && i <= 90)
		{
			t_all++;
			t_map[i]++;
		}
	}
	auto f_all = 0;
	map<char, int> f_map;
	for( auto& i:f_string)
	{
		if (65 <= i && i <= 90)
		{
			f_all++;
			f_map[i]++;
		}
	}


	cout << "Plik niezaszyfrowany" << endl;
	for (auto& i : f_map)
	{
		double wynik = (double)i.second / t_all;
		cout << i.first << " = " << wynik << endl;
	}
	cout << endl << "Plik zaszyfrowany" << endl;
	for (auto& i : t_map)
	{
		double wynik = (double)i.second / t_all;
		cout << i.first << " = " << wynik << endl;

	}

	
	f_files.close();
	t_files.close();
}