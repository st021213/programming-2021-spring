#include<iostream>
#include<fstream>
using namespace std;

struct Point {
	int x;
	int y;
	int z;
	Point() : x(rand() % 10), y(rand() % 10), z(rand() % 10) {}
	friend ostream& operator<<(ostream& stream, const Point& point)
	{
		stream << "(" << point.x << "; " << point.y << "; " << point.z << ")";
		return stream;
	}
};

int main()
{
	cout << sizeof(Point) << endl;
	Point p1;
	Point p2;
	/*
	Режим	Назначение
	in		Открыть для ввода (выбирается по умолчанию для ifstream)
	out		Открыть для вывода (выбирается по умолчанию для ofstream)
	binary	Открыть файл в бинарном виде
	aрр		Присоединять данные; запись в конец файла
	ate		Установить файловый указатель на конец файла
	trunc	Уничтожить содержимое, если файл существует (выбирается по умолчанию, если флаг out указан, а флаги ate и арр — нет)
	*/
	cout << p1 << p2 << endl;
	fstream fout;
	fout.open("in.txt", ios::binary | ios::out);
	if (!fout)
	{
		cout << "Не удалось открыть файл";
	}
	fout.write((char*)(&p1), sizeof(Point));
	fout.write((char*)(&p2), sizeof(Point));
	fout.close();

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
	Point p3;
	Point p4;
	fstream fin;
	cout << p3 << p4 << endl;
	fin.open("in.txt", ios::binary | ios::in);
	if (!fin)
	{
		cout << "Не удалось открыть файл";
	}
	fin.read((char*)(&p3), sizeof(Point));
	cout << p3;
	fin.seekg(-(int)sizeof(Point), ios::cur);
	fin.read((char*)(&p4), sizeof(Point));
	cout << p4;
	fin.read((char*)(&p4), sizeof(Point));
	fin.close();
	cout << p3 << p4 << endl;


	//seekg seekp tellg tellp
	fin.seekg(15, ios::cur); // перемещаемся вперед на 15 байт относительно текущего местоположения файлового указателя
	fin.seekg(-17, ios::cur); // перемещаемся назад на 17 байт относительно текущего местоположения файлового указателя
	fin.seekg(24, ios::beg); // перемещаемся к 24-му байту относительно начала файла
	fin.seekg(25); // перемещаемся к 25-му байту файла
	fin.seekg(-27, ios::end); // перемещаемся к 27-му байту от конца файла
	
	fin.seekg(0, ios::beg); // перемещаемся в начало файла
	fin.seekg(0, ios::end); // перемещаемся в конец файла

	return 0;
}