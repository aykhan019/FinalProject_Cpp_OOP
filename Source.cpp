#include "Start.h"
#include "FileHelper.h"

void Run()
{
	try
	{
		Start();
	}
	catch (const Exception& ex)
	{
		ExceptionWriteToFile("ErrorFile.txt", ex);
	}
}

int main() {
	Run();
	return 0;
}