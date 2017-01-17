#define _CRTDB_MAP_ALLOC
#include <iostream>
using std::cout;

#include "Exception.h"
#include "Array2D.h"
#include "Row.h"
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 140;

	Array2D<int> tryconstructor(5, 3);
	int n = 0;
	for (int i = 0; i < tryconstructor.getRow(); ++i)
	{
		for (int j = 0; j < tryconstructor.getColumn(); ++j)
		{
			tryconstructor[i][j] = n;
			++n;
		}
	}

	Array2D<int> comonsubscript;
	comonsubscript = tryconstructor;

	try
	{
		cout << tryconstructor[5][3];
	}
	catch (Exception &exception)
	{
		cout << exception;
	}


	for (int i = 0; i < tryconstructor.getRow(); ++i)
	{
		for (int j = 0; j < tryconstructor.getColumn(); ++j)
		{
			cout << tryconstructor[i][j] << ' ';
		}
		cout << '\n';
	}
	
	Array2D<int> trycpyctor(tryconstructor);

	tryconstructor.setRow(4);

	for (int i = 0; i < tryconstructor.getRow(); ++i)
	{
		for (int j = 0; j < tryconstructor.getColumn(); ++j)
		{
			cout << tryconstructor[i][j] << ' ';
		}
		cout << '\n';
	}

	tryconstructor.setColumn(2);

	for (int i = 0; i < tryconstructor.getRow(); ++i)
	{
		for (int j = 0; j < tryconstructor.getColumn(); ++j)
		{
			cout << tryconstructor[i][j] << ' ';
		}
		cout << '\n';
	}

	tryconstructor.setColumn(4);

	for (int i = 0; i < tryconstructor.getRow(); ++i)
	{
		for (int j = 0; j < tryconstructor.getColumn(); ++j)
		{
			cout << tryconstructor[i][j] << ' ';
		}
		cout << '\n';
	}

	tryconstructor.setColumn(1);

	for (int i = 0; i < tryconstructor.getRow(); ++i)
	{
		for (int j = 0; j < tryconstructor.getColumn(); ++j)
		{
			cout << tryconstructor[i][j] << ' ';
		}
		cout << '\n';
	}


	tryconstructor.setColumn(2);
	try
	{
		cout << tryconstructor[2][2];
	}
	catch (Exception &exception)
	{
		cout << exception;
	}

	return 0;
}