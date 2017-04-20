#pragma once

#include <string>

using namespace std;

class FileWorker
{
public:
	FileWorker();
	~FileWorker();
	
	static string ReadAllText(string path);
};

