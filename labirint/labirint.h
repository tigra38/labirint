#pragma once

#include <cstddef>

//Класс для лабиринта
class Labirint {
    struct Node { // структура узла
        Node(int _x, int _y, Node* _parent = nullptr) :
            x(_x),
            y(_y),
            parent(_parent)
        { }
        ~Node()
        {
                delete left_children;
				delete right_children;
				delete front_children;
				delete back_children;
        }

        int x;
        int y;

        Node* parent; // родительская вершина
        Node* left_children; // список дочерних вершин       
		Node* right_children;
		Node* front_children;
		Node* back_children;
    };

	int n_;//количество площадок по x
	int m_;//количество количество площадок по y
	int startx_;//координата начала по x
	int starty_;//координата начала по y
	int endx_;//координата конца по x
	int endy_;//координата конца по y
	int** matrix_;//матрица
public:
	//Конструктор по умолчанию
	Labirint() : n_(0), m_(0), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {}
	
	//Конструктор с параметрами
	Labirint(int n, int m);

	//Деструктор
	~Labirint();

	//Метод для генерации лабиринта
	void generate();

	//Метод для вывод лабиринта
	void show();

private:
	Node* root;
};

