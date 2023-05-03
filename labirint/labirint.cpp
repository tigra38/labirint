#include "labirint.h"
#include <iostream>

//����������� � �����������
Labirint::Labirint(size_t n, size_t m) : n_(n), m_(m), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {
	//������� ������
	matrix_ = new int* [n_];

	//������� �������
	for (size_t i = 0; i < n_; ++i) {
		matrix_[i] = new int[m_];
	}

	//�������������� ����������
	for (size_t i = 0; i < n_; ++i) {
		for (size_t j = 0; j < m_; ++j) {
			matrix_[i][j] = 0;
		}
	}

	generate();
}


//����������
Labirint::~Labirint() {
	//����������� ����� � ����
	for (size_t i = 0; i < n_; ++i) {
		delete[] matrix_[i];
	}

	delete[] matrix_;
}

//����� ��� ��������� ���������
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

//����� ��� ����� ���������
void Labirint::show() {
	std::cout << std::endl << std::endl;

	//�������������� ����������
	for (size_t i = 0; i < n_; ++i) {
		std::cout << "  ";
		for (size_t j = 0; j < m_; ++j) {
			if (matrix_[i][j] != 0) {
				std::cout << "   ";
			}
			else {
				std::cout << "|#|";
			}
		}
		std::cout << std::endl;
	}
}