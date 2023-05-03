#pragma once

//����� ��� ���������
class Labirint {
	size_t n_;//���������� ����� � �������
	size_t m_;//���������� �������� � �������
	int startx_;//����� ������� ��� ������
	int starty_;//����� ������ ��� ������
	int endx_;//����� ������� ��� ������
	int endy_;//����� ������ ��� ������
	int** matrix_;//�������
public:
	//����������� �� ���������
	Labirint() : n_(0), m_(0), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {}

	//����������� � �����������
	Labirint(size_t n, size_t m);

	//����������
	~Labirint();

	//����� ��� ��������� ���������
	void generate();

	//����� ��� ����� ���������
	void show();
};

