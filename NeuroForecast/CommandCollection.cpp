#include "stdafx.h"
#include "CommandCollection.h"


CommandCollection::CommandCollection()
{
	_commands = new vector<CommandInfo>();
}


CommandCollection::~CommandCollection()
{
	delete _commands;
}

void CommandCollection::Add(CommandInfo item)
{
	_commands->push_back(item);
}

void CommandCollection::Remove(CommandInfo item)
{
	int count = 0;
	for (int i = 0; i < _commands->size(); i++)
	{
		if (_commands->at(i).GetName() == item.GetName())
		{
			RemoveAt(i);
			return;
		}
	}
}

void CommandCollection::RemoveAt(int index)
{
	_commands->erase(_commands->begin()+index);
}

int CommandCollection::Count()
{
	return  _commands->size();

}



CommandInfo & CommandCollection::operator[](unsigned int index)
{
	return _commands->at(index);
}

string CommandCollection::ToString()
{
	string resultString = "";
	for (int i = 0; i < _commands->size(); i++)
	{
		resultString += _commands->at(i).toString();
		resultString += "\n\r";
	}
	return resultString;
}

bool CommandCollection::hasNext()
{
	if (_position > _commands->size() || &_commands[_position] == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

CommandInfo CommandCollection::Next()
{
	throw exception();
}
