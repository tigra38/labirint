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
        Node* left_children = nullptr; // список дочерних вершин       
		Node* right_children = nullptr;
		Node* front_children = nullptr;
		Node* back_children = nullptr;
    };

	int length;//количество площадок по x
	int height;//количество количество площадок по y
	int startx_;//координата начала по x
	int starty_;//координата начала по y
	int endx_;//координата конца по x
	int endy_;//координата конца по y
	int** matrix_;//матрица
public:
	//Конструктор по умолчанию
	Labirint() : length(0), height(0), startx_(0), starty_(0), endx_(0), endy_(0), matrix_(nullptr) {}
	
	//Конструктор с параметрами
	Labirint(int n, int m);

	//Деструктор
	~Labirint();

	//Метод для генерации лабиринта
	void generate();

	//Метод для вывод лабиринта
	void show_by_index();
	void show_by_steps();

	int track_order = 0;

private:
	Node* root = nullptr;
};

