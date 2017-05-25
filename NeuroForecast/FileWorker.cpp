#include "stdafx.h"
#include "FileWorker.h"
#include <fstream>

FileWorker::FileWorker()
{
}


FileWorker::~FileWorker()
{
}

void FileWorker::WriteAllText(string path, string text)
{

	ofstream out;
	out.open(path, 0);
	out << text;
	out.close();
}

string FileWorker::ReadAllText(string path)
{
	setlocale(LC_ALL, "rus");
	string resultText;

	ifstream inputStream;
	inputStream.open(path, 0);
	string temp = "";
	while (!inputStream.eof())
	{
		getline(inputStream, temp);
		resultText += temp + "\n";
	}
	resultText = resultText.erase(resultText.size() - 1, 1);
	inputStream.close();
	return resultText;
}

vector<std::string> FileWorker::ReadAllLines(string path)
{
	setlocale(LC_ALL, "rus");
	
	ifstream inputStream;
	inputStream.open(path, 0);
	string temp = "";
	vector<std::string> lines = vector<std::string>();
	while (!inputStream.eof())
	{
		getline(inputStream, temp);
		lines.push_back(temp);
	}
	inputStream.close();
	return lines;
}
