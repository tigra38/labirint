#pragma once

//Класс для лабиринта
class Labirint {
	size_t n_;//количество строк в матрице
	size_t m_;//количество столбцов в матрице
	int startx_;//номер столбца для начала
	int starty_;//номер строки для начала
	int endx_;//номер столбца для выхода
	int endy_;//номер строки для выхода
	int** matrix_;//матрица
public:
	//Конструктор по умолчанию
	Labirint() : n_(0), m_(0), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {}

	//Конструктор с параметрами
	Labirint(size_t n, size_t m);

	//Деструктор
	~Labirint();

	//Метод для генерации лабиринта
	void generate();

	//Метод для вывод лабиринта
	void show();
};

