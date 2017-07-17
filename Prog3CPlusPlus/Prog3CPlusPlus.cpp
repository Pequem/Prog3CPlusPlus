// Prog3CPlusPlus.cpp : Define o ponto de entrada para a aplicação de console.
//

#include <iostream>
#include <string>
#include <cstring>
#include "Controller.h"
#include "CustomException.h"
int main(int argc, char **argv)
{
	using namespace std;
	if (argc == 0) {
		cout << "No Command Line arguments" << endl;
		return 0;
	}
	string d, v, p, q, r, a;
	for (int i = 0; i < argc; i++) {
		if (strcmp("-d", argv[i]) == 0) {
			d = argv[++i];
		}
		else if (strcmp("-v", argv[i]) == 0) {
			v = argv[++i];
		}
		else if (strcmp("-p", argv[i]) == 0) {
			p = argv[++i];
		}
		else if (strcmp("-q", argv[i]) == 0) {
			q = argv[++i];
		}
		else if (strcmp("-r", argv[i]) == 0) {
			r = argv[++i];
		}
		else if (strcmp("-a", argv[i]) == 0) {
			a = argv[++i];
		}
		else {
			//cout << "Comando " << argv[i] << " invalido." << endl;
		}
	}
	try {
		Controller(d, v, p, q, r, a);
	}
	catch (CustomException e) {
		cout << e.what() << endl;
	}
	system("Pause");
}

