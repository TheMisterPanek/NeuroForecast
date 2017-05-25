#pragma once

#include <string>
#include <vector>

using namespace std;

class FileWorker
{
public:
	FileWorker();
	~FileWorker();
	
	static string ReadAllText(string path);
	static vector<std::string> ReadAllLines(string path);
	
	static void WriteAllText(string path,string text);
	
};

