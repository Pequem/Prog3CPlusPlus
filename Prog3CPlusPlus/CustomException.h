#pragma once
#include <string>
#include <exception>
using namespace std;
class CustomException:exception
{
public:
	CustomException(string msg);
	string what();
	~CustomException();
private:
	string msg;
};

