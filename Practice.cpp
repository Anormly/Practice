#include "functions.h"

using namespace std;

int menu = 0;

void Menu() {
    cout << "МЕНЮ \n"
        "(0) Выход из системы \n"
        "(1) Ввод данных студентов \n"
        "(2) Распечатка данных \n"
        "(3) Добавить данные \n"
        "(4) Изменить данные \n"
        "(5) Удалить данные \n"
        "(6) Сортировка списка \n"
        "(7) Запись данных в текстовый файл \n"
        "(8) Перевод данных из текстового файла в бинарный \n";
    cin >> menu;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();

    int amountOfData = 0, choice = 0;

    Data* d = new Data[amountOfData];
    while (menu != 0)
    {
        switch (menu)
        {
        case input:
            system("cls");
            cout << "(1) Ввод с клавиатуры\n(2) Считать данные из текстового файла\n(3) Считать данные из бинарного файла\n" << endl;
            cin >> choice;
            if (choice == 1)
            {
                DataInput(d, amountOfData);
            }
            else if (choice == 2)
            {
                char filename[20]{};
                cout << "введите название файла\n";
                cin >> filename;
                txtreader(d, amountOfData, filename);
            }
            else if (choice == 3)
            {
                char filename[20]{};
                cout << "введите название файла\n";
                cin >> filename;
                BinaryReader(d, amountOfData, filename, "DataLoad.txt");
            }
            else {
                cout << "некорректный выбор, возвращение в меню" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case output:
            system("cls");
            cout << "(1) Вывести весь список\n(2) Вывести студентов по запросу" << endl;
            cin >> choice;
            if (choice == 1) {
                if (amountOfData != 0)
                {
                    system("cls");
                    cout << "Список всех студентов \n";
                    DataPrint(d, amountOfData);
                }
                else
                {
                    system("cls");
                    cout << "список пуст" << endl;
                }
            }
            else if (choice == 2)
            {
                if (amountOfData != 0)
                {
                    cout << "Студенты одного года рождения и обучающиеся на одном курсе \n";
                    DataPrintYear(d, amountOfData);
                }
                else {
                    cout << "Данные пусты" << endl;
                }
            }
            else {
                cout << "некорректный выбор, возвращение в меню" << endl;
                system("pause");
                system("cls");
                Menu();
                break;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case add:
            system("cls");

            DataAdd(d, amountOfData);
            cout << "данные добавлены";
            amountOfData += 1;
            system("pause");
            system("cls");
            Menu();
            break;

        case change:
            system("cls");
            if (amountOfData != 0)
            {
                DataChange(d, amountOfData);
            }
            else
            {
                cout << "данные пусты";
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case del:
            system("cls");
            if (amountOfData != 0)
            {
                DeleteData(d, amountOfData);
                amountOfData--;
            }
            else
            {
                cout << "данные пусты";
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case d_sort:
            system("cls");
            if (amountOfData != 0) {
                int param = 0, course = 0;
                cout << "1. Фамилия\n2. Имя\n3. Отчество\n4. День рождения\n5. Месяц рождения\n6. Год рождения\n7. Курс\n8. Группа\n";
                cin >> param;
                system("cls");
                cout << "1. По возрастанию\n2. По убыванию\n";
                cin >> course;
                if (course == 1 || course == 2) {
                    Sorting(d, amountOfData, param, course);
                }
                else { cout << "неверно введен параметр\n"; }
            }
            else
            {
                cout << "данные пусты";
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case d_save:
            system("cls");

            if (amountOfData != 0)
            {
                char filename[20]{};
                cout << "введите название файла\n";
                cin >> filename;
                DataSave(d, amountOfData, filename);
                cout << "Данные записаны в файл " << filename << endl;
            }
            else
            {
                cout << "Данные пусты" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case d_savebin:
            system("cls");
            {
                cout << "введите название текстового файла\n";
                char filename1[20]{};
                cin >> filename1;
                cout << "введите название текстового файла\n";
                char filename2[20]{};
                cin >> filename2;
                BinaryTranslation(amountOfData,filename1, filename2);
            }
            system("pause");
            system("cls");
            Menu();
            break;

        default:
            system("cls");
            cout << "Ошибка выбора пункта меню" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
    }
}