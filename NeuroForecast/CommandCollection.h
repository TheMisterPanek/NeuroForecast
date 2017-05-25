#pragma once

#include <vector>
#include "CommandInfo.h"


using namespace std;

class CommandCollection
{
public:
	CommandCollection();
	~CommandCollection();

	void Add(CommandInfo item);
	void Remove(CommandInfo item);
	void RemoveAt(int index);

	int Count();

	CommandInfo& operator [] (unsigned int index);

	string ToString();

	bool hasNext();
	CommandInfo Next();

private:
	vector<CommandInfo> * _commands;

	int _position;
};

