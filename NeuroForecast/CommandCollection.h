#pragma once

#include <vector>;
#include "CommandInfo.h"

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


private:
	vector<CommandInfo> * _commands;
};

