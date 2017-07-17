#include "CustomException.h"



CustomException::CustomException(string msg):exception()
{
	this->msg = msg;
}

string CustomException::what() {
	return this->msg;
}

CustomException::~CustomException()
{
}
