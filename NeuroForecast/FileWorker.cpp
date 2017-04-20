#include "stdafx.h"
#include "FileWorker.h"
#include <fstream>

FileWorker::FileWorker()
{
}


FileWorker::~FileWorker()
{
}

string FileWorker::ReadAllText(string path)
{
	setlocale(LC_ALL, "rus");
	string resultText;
	ifstream inputStream(path);
	inputStream >> resultText;
	return inputStream;
}
