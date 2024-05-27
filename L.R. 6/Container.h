#pragma once
#include"Shapes.h"
#include "MyForm.h"

ref class BordersChecker {
private:
	System::Drawing::Size Borders;
public:
	BordersChecker() {}
	void setBorders(System::Drawing::Size Borders) {
		this->Borders = Borders;
	}
	bool BordersCheck(Shape^ obj) {
		for (int i = 0; i < Borders.Width; i++) {
			if (obj->isPointInObj(i, Borders.Height) || obj->isPointInObj(i, -1)) {
				obj->returnBack();
				obj->set_dMove(1);//для того, чтобы максимально близко подойти к границе
				return true;
			}
		}
		for (int i = 0; i < Borders.Height; i++) {
			if (obj->isPointInObj(Borders.Width, i) || obj->isPointInObj(-1, i)) {
				obj->returnBack();
				obj->set_dMove(1);
				return true;
			}
		}
		if (obj->get_dMove() == 1) obj->reset_dMove();
		return false;
	}
};

ref class ShapeContainer {
private:
	ref class Node {
	public:
		Shape^ value;
		Node^ nextNode;
		Node(Shape^ shape, Node^ nxt) {
			value = shape;
			nextNode = nxt;
		}
	};
	Node^ first;
	Node^ current;
	Node^ last;
	int size;
	System::Drawing::Brush^ LastBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::BlueViolet);
	BordersChecker^ bChecker;
	
public:
	System::EventHandler^ ContainerChanged;
	void Initialize_BChecker(System::Drawing::Size size) {
		bChecker->setBorders(size); 
	}
	
	ShapeContainer() {
		last = current = first = nullptr;
		size = 0;
		bChecker = gcnew BordersChecker();
	}
	
	void push_back(Shape^ cr) {
		Node^ newNode = gcnew Node(cr,nullptr);
		if (first == nullptr) {
			first = newNode;
		}
		else {
			last->nextNode = newNode;
			(last->value)->setIsSlctd(false);
		}
		last = newNode;
		size++;
		cr->setColorSlctd(LastBrush);
		ContainerChanged->Invoke(this,nullptr);
	}
	void unselect() {
		Node^ r = first;
		while (r != nullptr) {
			if (r->value->getIsSlctd()) {
				r->value->setIsSlctd(false);
			}
			r = r->nextNode;
		}
	}
	
	void addOrSelect(int x, int y, bool cBoxMulty, bool fCtrl, System::String^ type) {//проверяет, не принадлежат ли координаты уже существующей фигуре. Если нет - добавляет новую, иначе - закрашивает старую
		Node^ c = first;
		int counter = 0;
		for (int i = 0; i < size; i++) {
			if (c->value->isPointInObj(x, y)) {
				counter++;
				break;
			}
			c = c->nextNode;
		}
		if (counter == 0) {
			Shape^ newShape;
			if (type == "Circle") newShape = gcnew CCircle(x, y, true);
			else if (type == "Triangle") newShape = gcnew Triangle(x,y);
			else if (type == "Square") newShape = gcnew Square(x, y);
			unselect();
			push_back(newShape);
		}
		else {
			c = first;
			if (!fCtrl) unselect();
			for (int i = 0; i < size; i++) {
				if (c->value->isPointInObj(x, y) && !(c->value->getIsSlctd())) {
					c->value->setIsSlctd(true);
					if (!(cBoxMulty)) break;
				}
				c = c->nextNode;
			}
		}
		ContainerChanged->Invoke(this, nullptr);
	}
	void delSlctd() {
		Node^ r = first;
		while (r != nullptr) {
			Node^ nxt = r->nextNode;
			if (r->value->getIsSlctd()) del(r->value);
			r = nxt;
		}
		if (last != nullptr) last->value->setIsSlctd(true);
		ContainerChanged->Invoke(this, nullptr);
	}
	void DrawAll(System::Drawing::Graphics^ g) {
		Node^ r = first;
		while (r != nullptr) {
			(r->value)->Draw(g);
			r = r->nextNode;
		}
	}

	void del(Shape^ c) {
		if (c == nullptr || first == nullptr) return;
		Node^ r = first;
		Node^ p = nullptr; 
		while (r != nullptr) {
			if (r->value == c) {
				if (p == nullptr) {
					if (current == first) current = first->nextNode;
					if (last == first) last = nullptr;
					Node^ nxt = first->nextNode;
					delete first;
					first = nxt;
					size--;
					break;

				}
				else {
					if (current == r) current = current->nextNode;
					if (last == r) {
						last = p;
						last->value->setIsSlctd(true);
					};
					p->nextNode = r->nextNode;
					delete r;
					size--;
					break;
				}
			}
			p = r;
			r = r->nextNode;
		}
		ContainerChanged->Invoke(this, nullptr);
	}

	void setSlctdColor(System::Drawing::Color color) {
		LastBrush = gcnew System::Drawing::SolidBrush(color);
		Node^ r = first;
		while (r != nullptr) {
			r->value->setColorSlctd(LastBrush);
			r = r->nextNode;
		}
		ContainerChanged->Invoke(this, nullptr);
	}

	void MoveSlctd(System::String^ side, bool Borders) {
		Node^ r = first;
		while (r != nullptr) {
			if (r->value->getIsSlctd()) {
				r->value->Move(side);
				if (Borders) (bChecker->BordersCheck(r->value));
				else (r->value)->reset_dMove();
			}
			r = r->nextNode;
		}
		ContainerChanged->Invoke(this, nullptr);
	}

	void sizeChange(System::String^ operation, bool Borders) {
		Node^ r = first;
		while (r != nullptr) {
			if (r->value->getIsSlctd()) {
				r->value->sizeChange(operation);
				if (Borders) (bChecker->BordersCheck(r->value));
			}
			r = r->nextNode;
		}
		ContainerChanged->Invoke(this, nullptr);
	}
};