#include "Functions.h"

using namespace std;

void DataInput(Data* (&d), int& n)
{
	setlocale(LC_ALL, "ru");
	cout << "введите количество студентов, которых вы хотите внести в список" << endl;
	cin >> n;

	d = new Data[n];
	for (int i = 0; i < n; i++) {

		cout << "¬ведите ‘»ќ студента" << endl;
		cin >> d[i].surname;
		cin >> d[i].name;
		cin >> d[i].mName;


		cout << "¬ведите дату рождени€ (день, мес€ц, год)" << endl;
		cin >> d[i].day;
		cin >> d[i].month;
		cin >> d[i].year;

		cout << "¬ведите курс студента" << endl;
		cin >> d[i].coursenumber;


		cout << "¬ведите группу студента" << endl;
		cin >> d[i].groupName;
		if (!DataInputCheck(d[i])) { cout << "ƒанные введены некорректно\n"; }
		cout << "______________________________" << endl;
	}
}

void DataPrint(Data* d, int n)
{
	cout << " ___________________________________________________________________________________________________________________________________________________" << endl;
	for (int i = 0; i < n; i++) {
		cout << "|" << setw(10) << "Student є" << i + 1 << '|' << setw(30) << d[i].surname << "|" << setw(30) << d[i].name << "|" << setw(30) << d[i].mName << "|";
		if (d[i].month < 10) {
			cout << setw(4) << d[i].day << ".0" << d[i].month << "." << setw(4) << d[i].year << "|" << setw(5) << d[i].coursenumber << " year" << "|" << setw(10) << "group " << setw(8) << d[i].groupName << "|" << setw(2) << "\n";
		}
		else {
			cout << setw(4) << d[i].day << "." << d[i].month << "." << setw(4) << d[i].year << "|" << setw(5) << d[i].coursenumber << " year" << "|" << setw(10) << "group " << setw(8) << d[i].groupName << "|" << setw(2) << "\n";
		}
		cout << "|___________|______________________________|______________________________|______________________________|____________|__________|__________________|" << endl;
	}
}

void DataPrintYear(Data* d, int n)
{
	int year = 0, course = 0;
	cout << "введите, студентов какого года рождени€ и какого курса вы хотите вывести\nгод - ";
	cin >> year;
	cout << "курс - ";
	cin >> course;
	cout << " ___________________________________________________________________________________________________________________________________________________" << endl;
	for (int i = 0; i < n; i++) {
		if (d[i].year == year && d[i].coursenumber == course) {
			cout << "|" << setw(10) << "Student є" << i + 1 << '|' << setw(30) << d[i].surname << "|" << setw(30) << d[i].name << "|" << setw(30) << d[i].mName << "|";
			if (d[i].month < 10) {
				cout << setw(4) << d[i].day << ".0" << d[i].month << "." << setw(4) << d[i].year << "|" << setw(5) << d[i].coursenumber << " year" << "|" << setw(10) << "group " << setw(8) << d[i].groupName << "|" << setw(2) << "\n";
			}
			else {
				cout << setw(4) << d[i].day << "." << d[i].month << "." << setw(4) << d[i].year << "|" << setw(5) << d[i].coursenumber << " year" << "|" << setw(10) << "group " << setw(8) << d[i].groupName << "|" << setw(2) << "\n";
			}
			cout << "|___________|______________________________|______________________________|______________________________|____________|__________|__________________|" << endl;
		}
	}
}

void txtreader(Data* (&d), int& n, char* filename)
{
	ifstream reader(filename);

	if (reader)
	{
		reader >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++)
		{
			reader >> d[i].surname;
			reader >> d[i].name;
			reader >> d[i].mName;

			reader >> d[i].day;
			reader >> d[i].month;
			reader >> d[i].year;

			reader >> d[i].coursenumber;

			reader >> d[i].groupName;
		}
		cout << "ƒанные занесены в список" << endl;
	}
	else
	{
		cout << "ошибка считывани€ данных файла";
	}
	reader.close();
}

void DataSave(Data* d, int n, char* filename)
{
	ofstream saver(filename, ios::out);

	if (saver) {
		saver << n << endl;

		for (int i = 0; i < n; i++)
		{
			saver << d[i].surname << endl;
			saver << d[i].name << endl;
			saver << d[i].mName << endl;

			saver << d[i].day << endl;
			saver << d[i].month << endl;
			saver << d[i].year << endl;

			saver << d[i].coursenumber << endl;

			saver << d[i].groupName << endl;
		}
	}
	else
	{
		cout << "ошибка открыти€ файла";
	}
}

void BufCopyD(Data* (&d_new), Data* (&d_old), int& n)
{
	for (int i = 0; i < n; i++)
	{
		d_new[i] = d_old[i];
	}
}

void DataAdd(Data* (&d), int& n)
{
	Data* buf;
	buf = new Data[n];

	BufCopyD(buf, d, n);

	n += 1;

	d = new Data[n];

	BufCopyD(d, buf, n -= 1);

	cout << "¬ведите ‘»ќ студента" << endl;
	cin >> d[n].surname;
	cin >> d[n].name;
	cin >> d[n].mName;

	cout << "¬ведите дату рождени€ (день, мес€ц, год)" << endl;
	cin >> d[n].day;
	cin >> d[n].month;
	cin >> d[n].year;

	cout << "¬ведите курс студента" << endl;
	cin >> d[n].coursenumber;

	cout << "¬ведите группу студента" << endl;
	cin >> d[n].groupName;

	cout << "______________________________" << endl;
}

void DataChange(Data* (&d), int& n)
{
	int number = 0;
	cout << "введите номер записи которую хотите изменить (от 1 до " << n << ")\n";
	cin >> number;
	number--;

	system("cls");

	for (int i = 0; i < n; i++)
	{
		if (i == number)
		{
			cout << "¬ведите ‘»ќ студента" << endl;
			cin >> d[i].surname;
			cin >> d[i].name;
			cin >> d[i].mName;

			cout << "¬ведите дату рождени€ (день, мес€ц, год)" << endl;
			cin >> d[i].day;
			cin >> d[i].month;
			cin >> d[i].year;

			cout << "¬ведите курс студента" << endl;
			cin >> d[i].coursenumber;

			cout << "¬ведите группу студента" << endl;
			cin >> d[i].groupName;

			cout << "______________________________" << endl;
		}
	}
}

void DeleteData(Data* (&d), int& n)
{
	int number = 0;
	cout << "введите номер студента, данные которого хотите удалить (от 1 до " << n << ")" << endl;
	cin >> number;
	number--;
	system("cls");
	Data* buf = new Data[n];

	BufCopyD(buf, d, n);
	n--;
	d = new Data[n];

	int j = 0;
	n++;
	for (int i = 0; i < n; i++)
	{
		if (i != number)
		{
			d[j] = buf[i];
			++j;
		}
	}
	cout << "данные удалены";
	delete[]buf;
}

void CopyOneElement(Data& d_new, Data& d_old) {
	strcpy_s(d_new.surname, d_old.surname);
	strcpy_s(d_new.name, d_old.name);
	strcpy_s(d_new.mName, d_old.mName);
	d_new.day = d_old.day;
	d_new.month = d_old.month;
	d_new.year = d_old.year;
	d_new.coursenumber = d_old.coursenumber;
	strcpy_s(d_new.groupName, d_old.groupName);
}

void Sorting(Data* d, int n, int param, int course)
{
	Data transp;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			switch (param) {
			case surname:
				if (course == increase) {
					if (strcmp(d[i].surname, d[j].surname) > 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (strcmp(d[i].surname, d[j].surname) < 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case name:
				if (course == increase) {
					if (strcmp(d[i].name, d[j].name) > 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (strcmp(d[i].name, d[j].name) < 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case mName:
				if (course == increase) {
					if (strcmp(d[i].mName, d[j].mName) > 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (strcmp(d[i].mName, d[j].mName) < 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case day:
				if (course == increase) {
					if (d[i].day > d[j].day) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (d[i].day < d[j].day) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case month:
				if (course == increase) {
					if (d[i].month > d[j].month) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (d[i].month < d[j].month) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case year:
				if (course == increase) {
					if (d[i].year > d[j].year) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (d[i].year < d[j].year) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case courses:
				if (course == increase) {
					if (d[i].coursenumber > d[j].coursenumber) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (d[i].coursenumber < d[j].coursenumber) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			case group:
				if (course == increase) {
					if (strcmp(d[i].groupName, d[j].groupName) > 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				else if (course == decrease) {
					if (strcmp(d[i].groupName, d[j].groupName) < 0) {
						CopyOneElement(transp, d[j]);
						CopyOneElement(d[j], d[i]);
						CopyOneElement(d[i], transp);
					}
				}
				break;
			default: cout << "ƒействие выбрано некорректно\n"; break;
			}
		}
	}
}

bool DataInputCheck(Data& element)
{
	bool flag = true;
	for (int i = 0; i < strlen(element.surname); i++) {
		if (isdigit(element.surname[i]) || element.surname[i] == ' ' || element.surname[i] == '.' || element.surname[i] == ',') {
			flag = false;
		}
	}
	for (int i = 0; i < strlen(element.name); i++) {
		if (isdigit(element.name[i]) || element.name[i] == ' ' || element.name[i] == '.' || element.name[i] == ',') {
			flag = false;
		}
	}
	for (int i = 0; i < strlen(element.mName); i++) {
		if (isdigit(element.mName[i]) || element.mName[i] == ' ' || element.mName[i] == '.' || element.mName[i] == ',') {
			flag = false;
		}
	}
	for (int i = 0; i < strlen(element.mName); i++) {
		if (isdigit(element.groupName[0]) || isdigit(element.groupName[1]) || element.groupName[i] == ' ' || element.groupName[i] == '.' || element.groupName[i] == ',') {
			flag = false;
		}
	}
	return flag;
}

void BinaryTranslation(int& n, char* filename1, char* filename2)
{
	ifstream reader(filename1);
	ofstream BinRecord(filename2, ios::binary);
	Data d;
	if (reader) {
		reader >> n;
		for (int i = 0; i < n; i++) {
			reader >> d.surname;
			reader >> d.name;
			reader >> d.mName;

			reader >> d.day;
			reader >> d.month;
			reader >> d.year;

			reader >> d.coursenumber;

			reader >> d.groupName;
			BinRecord.write((char*)&d, sizeof(Data));
		}
		BinRecord.close();
		reader.close();
	}
}

void BinaryReader(Data* (&d),int &n, char* filename, const char* filename2)
{
	ifstream BinaryRead(filename);
	ifstream TxtRead(filename2);
	TxtRead >> n;
	if (BinaryRead) {
		d = new Data[n];
		for (int i = 0; i < n; i++) {
		BinaryRead.read((char*)&d[i], sizeof Data);
		}
		BinaryRead.close();
	}
	else cout << "ќшибка открыти€ файла";
}





