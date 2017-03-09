#ifndef __FORMAT_H__
#define __FORMAT_H__

#include <string>

using namespace std;

class Base
{
public:
	Base();
	Base(const unsigned int& lineLength);

	virtual void setText(const string& text) = 0;
	string getText();

protected:
	unsigned int lineLength;
	string text;
};

class Left : public Base
{
public:
	Left();
	Left(const unsigned int& lineLength);
	Left(const string& text);
	Left(const unsigned int& lineLength, const string& text);
	virtual void setText(const string& text);
};

class Right : public Base
{
public:
	Right();
	Right(const unsigned int& lineLength);
	Right(const string& text);
	Right(const unsigned int& lineLength, const string& text);
	virtual void setText(const string& text);
};

class Center : public Base
{
public:
	Center();
	Center(const unsigned int& lineLength);
	Center(const string& text);
	Center(const unsigned int& lineLength, const string& text);
	virtual void setText(const string& text);
};

#endif//__FORMAT_H__
