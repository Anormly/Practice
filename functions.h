#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>


using namespace std;
enum {
	input = 1, output = 2, add = 3, change = 4, del = 5, d_sort = 6, d_save = 7, d_savebin = 8
};
enum {
	surname = 1, name = 2, mName = 3, day = 4, month = 5, year = 6, courses = 7, group = 8
};
enum {
	increase = 1, decrease = 2
};
struct Data {
	char surname[30]{},
		name[30]{},
		mName[30]{};
	int coursenumber = 0;
	char groupName[10]{};
	int year = 0, day = 0, month = 0;
};

void DataInput(Data* (&d), int& n);
void DataPrint(Data* d, int n);
void DataPrintYear(Data* d, int n);
void txtreader(Data* (&d), int& n, char* filename);
void DataSave(Data* d, int n, char* filename);
void BufCopyD(Data* (&d_new), Data* (&d_old), int& n);
void DataAdd(Data* (&d), int& n);
void DataChange(Data* (&d), int& n);
void DeleteData(Data* (&d), int& n);
void CopyOneElement(Data& d_new, Data& d_old);
void Sorting(Data* d, int n, int param, int course);
bool DataInputCheck(Data& element);
void BinaryTranslation(int& n, char* filename1, char* filename2);
void BinaryReader(Data* (&d), int &n,char* filename,const char* filename2);

