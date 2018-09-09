#include<iostream>
#include<fstream>
#include<string>
#include "Cwords.h"
using namespace std;

Word::Word(string file)
{
	finname = file;
	number = 0;
	foutname = "result.txt";
}

void Word::count()
{
	ifstream fin;
	fin.open(finname);
	if (!fin.is_open())
	{
		cerr << "Could not open" << finname << endl;
		fin.clear();
	}
	string word;
	char c;
	fin >> noskipws; //���Ź�һ���ַ�
	while (!fin.eof())
	{
		fin >> c;
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) //����ĸ����
		{
			if (c >= 65 && c <= 90)
				c += 32;
			word.push_back(c);
		}
		else //�ж��ܷ���ɵ���
		{
			if (word.length() >= 4)
			{
				if ((word[0] >= 97 && word[0] <= 122) && (word[1] >= 97 && word[1] <= 122) && (word[2] >= 97 && word[2] <= 122) && (word[3] >= 97 && word[3] <= 122))
				{
					number++;
					///////////////////////////
					cout << word << endl;
					///////////////////////////
				}
			}
			word = "";
		}
	}
	fin.close();
}

void Word::show()
{
	cout << "words:" << number << endl;
}

void Word::fwrite()
{
	ofstream fout;
	fout.open(foutname, ios::out | ios::app); //׷��
	if (!fout.is_open())
	{
		cerr << "Cant't open" << foutname << endl;
		exit(EXIT_FAILURE);
	}
	fout << "words:" << number << endl;
	fout.close();
}