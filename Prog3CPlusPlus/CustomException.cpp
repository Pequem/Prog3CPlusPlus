#include "CustomException.h"


/*O contrutor de CustomException recebe a mensagem que vai ser mandanda na tela*/
CustomException::CustomException(string msg):exception()
{
	this->msg = msg;
}
/*O método what retorna a mensagem*/
string CustomException::what() {
	return this->msg;
}
/*O destrutor de CustomException destroi o objeto CustomException*/
CustomException::~CustomException()
{
}
