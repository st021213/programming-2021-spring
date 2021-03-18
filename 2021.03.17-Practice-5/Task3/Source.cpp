#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

int main()
{
	srand(time(0));
	const int n = 10;
	int a[n] = { 0 };
	for (int i = 0; i < n; a[i] = rand() % 10, ++i);
	cout << "random array written to in.txt" << endl;
	for (int i = 0; i < n; cout << a[i] << (i == n - 1 ? '\n' : ' '), ++i);

	ofstream fout("in.txt");
	for (int i = 0; i < n; fout << a[i] << ' ', ++i);
	fout.close();

	cout << "array read from in.txt" << endl;
	int b[n] = { 0 };
	ifstream fin("in.txt");
	for (int i = 0; i < n; fin >> b[i], ++i);
	fin.close();
	for (int i = 0; i < n; cout << b[i] << (i == n - 1 ? '\n' : ' '), ++i);

	/*
	00010111 = 1 | 2 | 4 | 16
	00010111 = имя | фамилия | отчество | вес
	00000001 1 - имя
	00000010 2 - фамилия
	00000100 4 - отчество
	00001000 8 - дата рождения
	00010000 16 - вес
	00100000 32 - пол
	01000000 64 - цвет глаз
	10000000 128 - наличие волос
	*/

	/*
	Режим	Назначение
	in		Открыть для ввода (выбирается по умолчанию для ifstream)
	out		Открыть для вывода (выбирается по умолчанию для ofstream)
	binary	Открыть файл в бинарном виде
	aрр		Присоединять данные; запись в конец файла
	ate		Установить файловый указатель на конец файла
	trunc	Уничтожить содержимое, если файл существует (выбирается по умолчанию, если флаг out указан, а флаги ate и арр — нет)
	*/
	fstream fbin;
	fbin.open("in.bin", ios::binary | ios::out);
	if (!fbin)
	{
		cout << "Не удалось открыть файл на запись" << endl;
	}
	fbin.write((char*) a, sizeof(a));
	fbin.close();

	cout << "randomized array" << endl;
	for (int i = 0; i < n; b[i] = rand() % 10, ++i);
	for (int i = 0; i < n; cout << b[i] << (i == n - 1 ? '\n' : ' '), ++i);

	/*
	Метод	Описание
	open	Открывает файл для чтения
	get		Читает один или более символов из файла
	getline	Читает символьную строку из текстового файла или данные из бинарного файла до определенного ограничителя
	read	Считывает заданное число байт из файла в память
	eof		Возвращает ненулевое значение (true), когда указатель потока достигает конца файла
	peek	Выдает очередной символ потока, но не выбирает его
	seekg	Перемещает указатель позиционирования файла в заданное положение
	tellg	Возвращает текущее значение указателя позиционирования файла
	close	Закрывает файл
	*/
	fbin.open("in.bin", ios::binary | ios::in);
	if (!fbin)
	{
		cout << "Не удалось открыть файл на чтение" << endl;
	}
	fbin.read((char*)b, sizeof(b));
	fbin.close();
	cout << "array read from in.bin" << endl;
	for (int i = 0; i < n; cout << b[i] << (i == n - 1 ? '\n' : ' '), ++i);


	return 0;
}