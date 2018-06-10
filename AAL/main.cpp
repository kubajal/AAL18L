// AAL.cpp : Defines the entry point for the console application.
//

#include "Interface.h"

using namespace std;

int main(int argc, char **argv)
{
	Interface userInterface;
	userInterface.prompt(argc, argv);

	return 0;
}