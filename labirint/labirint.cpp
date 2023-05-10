#include "labirint.h"
#include <iostream>
#include <ctime>

//Конструктор с параметрами
Labirint::Labirint(int _x, int _y) : length(_x), height(_y), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {

	//Создаем строки
	root = nullptr;
	matrix_ = new int* [length];

	//Создаем столбцы
	for (size_t x = 0; x < length; ++x) {
		matrix_[x] = new int[height];
	}

	//Инициализируем значениями
	for (size_t x = 0; x < length; ++x) {
		for (size_t y = 0; y < height; ++y) {
			matrix_[x][y] = -1;
		}
	}

	//Определяем коорднату начала с помощью генератора случайных чисел
	//Устанавливаем точку отсчета генерации
	srand((long int)time(NULL));

	//Выбираем сначало случайным образом 0 или 1
	//Это поможет выбрать вариант, когда x выбирается из двух вариантов 
	//или y
	int choose1 = rand() % 2;

	if (choose1 == 0) {
		//Выбираем x из двух вариантов
		int array[2];
		array[0] = 0;
		array[1] = length - 1;

		int choose2 = rand() % 2;
		//Координата начала равна
		startx_ = array[choose2];
		starty_ = rand() % height;
	}
	else {
		//Выбираем н из двух вариантов
		int array[2];
		array[0] = 0;
		array[1] = height - 1;

		int choose2 = rand() % 2;
		//Координата начала равна
		starty_ = array[choose2];
		startx_ = rand() % length;

	}

	std::cout << "startx_ = " << startx_ << " starty_ = " << starty_ << std::endl;

	generate();
}


//Деструктор
Labirint::~Labirint() {
	//Освобождаем место в куче
	for (size_t i = 0; i < length; ++i) {
		delete[] matrix_[i];
	}
	if (root != nullptr)
	{
		delete root; // должны почистить за собой память

	}
	delete[] matrix_;
}

//Метод для генерации лабиринта
void Labirint::generate() {
	matrix_[startx_][starty_] = track_order++;
	matrix_[2][1] = track_order++;
	matrix_[2][2] = track_order++;
	matrix_[2][3] = track_order++;
	matrix_[2][4] = track_order++;
	matrix_[2][5] = track_order++;
	matrix_[3][5] = track_order++;
	matrix_[3][6] = track_order++;
}

//Метод для вывода лабиринта
void Labirint::show_by_index() {
	std::cout << std::endl << std::endl;
	char b = (unsigned)32; //black (space)
	char w = (unsigned)219; //white
	char s = (unsigned)176; //semi-gray
	char g = (unsigned)178; //gray
	//Инициализируем значениями
	for (size_t i = 0; i < length * 2 + 1; ++i) {
		std::cout << b << b; //отступ
		for (size_t j = 0; j < height * 2 + 1; ++j) {
			if ((i % 2) && (j % 2) && matrix_[j / 2][i / 2]) {
				std::cout << b << b; //трасса
			}
			else if ((i % 2) && (j % 2)) std::cout << w << w; //непроложенные трассы
			else {
				std::cout << s << s; //стены
			}
		}
		std::cout << s << s; //ограждение
		std::cout << std::endl;
	}
}

void Labirint::show_by_steps() {
	std::cout << std::endl << std::endl;
	char b = (unsigned)32; //black (space)
	char w = (unsigned)219; //white
	char s = (unsigned)176; //semi-gray
	char g = (unsigned)178; //gray

	//создание матрицы для прорисовки
	int** _lab = new int* [length * 2 + 1];
	for (int x = 0; x < length * 2 + 1; ++x) {
		_lab[x] = new int[height * 2 + 1];
	}

	//инициализация матрицы
	for (size_t x = 0; x < length * 2 + 1; ++x) {
		for (size_t y = 0; y < height * 2 + 1; ++y) {
			_lab[x][y] = 0;
		}
	}

	//отрисовка лабиринта в матрицу
	for (size_t y = 0; y < height * 2 + 1; ++y) {
		for (size_t x = 0; x < length * 2 + 1; ++x) {
			_lab[0][y] = 20; //отступ первой строки
			if ((x % 2) && (y % 2) && (matrix_[x / 2][y / 2] > 0)) {
				_lab[x][y] = 21; //трасса
			}
			else if ((x % 2) && (y % 2)) _lab[x][y] = 20; //непроложенные трассы
			else {
				_lab[x][y] = 20; //стены
			}
		}
	}

	//ломаем стену к стартовой точке
	int last_x = startx_ * 2 + 1;
	int last_y = starty_ * 2 + 1;
	if (startx_ == 0) last_x = 0;
	else if (startx_ == length - 1) last_x = startx_ * 2 + 2;
	if (starty_ == 0) last_y = 0;
	else if (starty_ == height - 1) last_y = starty_ * 2 + 2;
	if ((startx_ == 0) && (starty_ == 0)) last_x = 1;
	else if ((startx_ == length - 1) && (starty_ == height - 1)) last_x = startx_ * 2 + 1;
	else if ((startx_ == length - 1) && (starty_ == 0))  last_y = 1;
	_lab[last_x][last_y] = 21;

	//ломаем стены по трассе
	for (auto step = 0; step < track_order; step++)
	{
		for (auto y = 0; y < height * 2 + 1; ++y) {
			bool found = false; //для выхода сразу и из второго цикла
			for (auto x = 0; x < length * 2 + 1; ++x) {
				if ((x % 2) && (y % 2) && matrix_[x / 2][y / 2] == step) {
					if (last_x < x) _lab[x - 1][y] = step;
					else if (last_x > x) _lab[x + 1][y] = step;
					if (last_y < y) _lab[x][y - 1] = step;
					else if (last_y > y) _lab[x][y + 1] = step;
					last_x = x;
					last_y = y;
					_lab[x][y] = 21;
					found = true;
					break;
				}
			}
			if (found) break;
		}
	}

	//ломаем последнюю стену
	if (last_x == 1) --last_x; //левый край
	else if (last_x == length * 2 - 1) ++last_x; //правый край
	if (last_y == 1) --last_y; //верхний край
	else if (last_y == height * 2 - 1) ++last_y; //нижний край
	if ((last_x > length * 2 - 1) && (last_y < 1)) --last_x; //исключения: 
	else if ((last_x > length * 2 - 1) && (last_y > height * 2 - 1)) --last_x;
	else if ((last_x < 1) && (last_y > height * 2 - 1)) ++last_x;
	else if ((last_x < 1) && (last_y < 1)) ++last_x;
	_lab[last_x][last_y] = track_order;

	//вывод матрицы в консоль
	for (size_t y = 0; y < height * 2 + 1; ++y) {
		std::cout << b << b; //отступ слева
		for (size_t x = 0; x < length * 2 + 1; ++x) {
			switch (_lab[x][y])
			{
			case 20:
				std::cout << s << s;
				break;
			case 21:
				std::cout << b << b;
				break;
			case 22:
				std::cout << w << w;
				break;
			default:
				printf("%02d", _lab[x][y]); //вывод номера сломанной стены
				//std::cout << b << b; //закрашивание сломанной стены
				break;
			}
		}
		std::cout << std::endl;
	}




}
