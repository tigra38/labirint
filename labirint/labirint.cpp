﻿#include "labirint.h"
#include <iostream>
#include <ctime>

//Конструктор с параметрами
Labirint::Labirint(int n, int m) : n_(n), m_(m), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {

	//Создаем строки
	root = nullptr;
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

   //Определяем коорднату начала с помощью генератора случайных чисел
   //Устанавливаем точку отсчета генерации
   srand(time(NULL));
   
   //Выбираем сначало случайным образом 0 или 1
   //Это поможет выбрать вариант, когда x выбирается из двух вариантов 
   //или y
   int choose1 = rand() % 2;

   if(choose1 == 0){
      //Выбираем x из двух вариантов
      int array[2];
      array[0] = 0;
      array[1] = n_ - 1;

      int choose2 = rand() % 2;
      //Координата начала равна
      startx_ = array[choose2];
      starty_ = rand() % m_;
   }
   else{
      //Выбираем н из двух вариантов
      int array[2];
      array[0] = 0;
      array[1] = m_ - 1;

      int choose2 = rand() % 2;
      //Координата начала равна
      starty_ = array[choose2];
      startx_ = rand() % n_;
      
   }

   std::cout << "startx_ = " << startx_ << " starty_ = " << starty_ << std::endl; 

	//generate();
}


//Деструктор
Labirint::~Labirint() {
	//Освобождаем место в куче
	for (size_t i = 0; i < n_; ++i) {
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
	matrix_[6][0] = 1;
	matrix_[6][1] = 1;
	matrix_[5][1] = 1;
	matrix_[4][1] = 1;
	matrix_[3][1] = 1;
	matrix_[2][1] = 1;
	matrix_[2][2] = 1;
	matrix_[4][3] = 1;
	matrix_[3][3] = 1;
	matrix_[3][2] = 1;
	matrix_[4][2] = 1;
	matrix_[2][3] = 1;
	matrix_[2][4] = 1;
	matrix_[2][5] = 1;
	matrix_[3][5] = 1;
	matrix_[3][6] = 1;
}

//Метод для вывод лабиринта
void Labirint::show() {
	std::cout << std::endl << std::endl;
	char b = (int)32; //black (space)
	char w = (int)219; //white
	char s = (int)176; //semi-gray
	char g = (int)178; //gray
	//Инициализируем значениями
	for (size_t i = 0; i < n_*2+1; ++i) {
		std::cout << b << b; //отступ
		for (size_t j = 0; j < m_*2; ++j) {
			if ((i % 2) && (j % 2) && matrix_[i/2][j/2]) {
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

	/*for (size_t i = 0; i < 2 * n_ + 1; ++i) {
		std::cout << "  ";
		for (size_t j = 0; j < 2 * m_ + 1; ++j) {
			if (!(i % 2) && !(j % 2) && matrix_[i / 2][j / 2] != 0) {
				std::cout << "  ";
			}
			else {
				std::cout << c << c;
			}
		}
		std::cout << std::endl;
	}*/
}
