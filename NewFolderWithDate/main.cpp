#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iomanip>
#include <sstream>
#include <ctime>
using namespace std;

//创建一个以当前年月日命名的文件夹
void newFolderWithDate()
{
	struct tm *pLocal;
	time_t t;
	t = time(NULL);
	pLocal = localtime(&t);
	stringstream strStream;
	strStream << pLocal->tm_year +1900 << "-" << setfill('0') << setw(2) << pLocal->tm_mon +1 << "-" << setfill('0') << setw(2) << pLocal->tm_mday;
	string dirName = strStream.str();
	bool bFlag = CreateDirectory(dirName.c_str(),NULL);
}

void main()
{
	newFolderWithDate();
}