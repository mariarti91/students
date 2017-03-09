#include "format.h"

Base::Base()
	: lineLength(10), text("")
{}

Base::Base(const unsigned int& lineLength)
	: lineLength(lineLength), text("")
{}

string Base::getText()
{
	return text;
}

Left::Left()
	: Base()
{}

Left::Left(const unsigned int& lineLength)
	: Base(lineLength)
{}

Left::Left(const string& text)
	: Base(10)
{
	setText(text);
}

Left::Left(const unsigned int& lineLength, const string& text)
	: Base(lineLength)
{
	setText(text);
}

void Left::setText(const string& text)
{
	this->text = text;
	for(int i = lineLength; i < this->text.length(); i += (lineLength + 1))
		this->text.insert(i, "\n");
	if(text.length() % lineLength) this->text += string(lineLength - text.length() % lineLength, '_');
}

Right::Right()
	: Base()
{}

Right::Right(const unsigned int& lineLength)
	: Base(lineLength)
{}

Right::Right(const string& text)
	: Base(10)
{
	setText(text);
}

Right::Right(const unsigned int& lineLength, const string& text)
	: Base(lineLength)
{
	setText(text);
}

void Right::setText(const string& text)
{
	this->text = text;
	for(int i = lineLength; i < this->text.length(); i += (lineLength + 1))
		this->text.insert(i, "\n");
	if(text.length() % lineLength) this->text.insert(this->text.rfind('\n')+1, string(lineLength - text.length() % lineLength, '_'));
}

Center::Center(const unsigned int& lineLength)
	: Base(lineLength)
{}

Center::Center(const string& text)
	: Base(10)
{
	setText(text);
}

Center::Center(const unsigned int& lineLength, const string& text)
	: Base(lineLength)
{
	setText(text);
}

void Center::setText(const string& text)
{
	this->text = text;
	for(int i = lineLength; i < this->text.length(); i += (lineLength + 1))
		this->text.insert(i, "\n");
	if(text.length() % lineLength)
	{
		int padLength = (lineLength - text.length() % lineLength);
		string buf(padLength/2, '_');
		this->text.insert(this->text.rfind('\n')+1, buf);
		this->text += buf;
		if(padLength % 2) this->text += '_';
	}
}
