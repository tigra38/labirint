#include "labirint.h"
#include <iostream>

//Конструктор с параметрами
Labirint::Labirint(size_t n, size_t m) : n_(n), m_(m), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {
	//Создаем строки
	matrix_ = new int* [n_];

	//Создаем столбцы
	for (size_t i = 0; i < n_; ++i) {
		matrix_[i] = new int[m_];
	}

	//Инициализируем значениями
	for (size_t i = 0; i < n_; ++i) {
		for (size_t j = 0; j < m_; ++j) {
			matrix_[i][j] = 0;
		}
	}

	generate();
}


//Деструктор
Labirint::~Labirint() {
	//Освобождаем место в куче
	for (size_t i = 0; i < n_; ++i) {
		delete[] matrix_[i];
	}

	delete[] matrix_;
}

//Метод для генерации лабиринта
void Labirint::generate() {
	matrix_[6][0] = 1;
	matrix_[6][1] = 1;
	matrix_[5][1] = 1;
	matrix_[4][1] = 1;
	matrix_[3][1] = 1;
	matrix_[2][1] = 1;
	matrix_[2][2] = 1;
	matrix_[2][3] = 1;
	matrix_[3][3] = 1;
	matrix_[4][3] = 1;
	matrix_[4][4] = 1;
	matrix_[4][5] = 1;
	matrix_[3][5] = 1;
	matrix_[3][6] = 1;
}

//Метод для вывод лабиринта
void Labirint::show() {
	std::cout << std::endl << std::endl;
	char c = 219;
	//Инициализируем значениями
	for (size_t i = 0; i < n_; ++i) {
		std::cout << "  ";
		for (size_t j = 0; j < m_; ++j) {
			if (matrix_[i][j] != 0) {
				std::cout << "  ";
			}
			else {
				std::cout << c << c;
			}
		}
		std::cout << std::endl;
	}
}