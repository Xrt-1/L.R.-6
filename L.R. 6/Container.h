#pragma once
#include"Shapes.h"
#include "MyForm.h"

ref class BordersChecker {
private:
	System::Drawing::Size Borders;
	System::Drawing::Point Location;
public:
	BordersChecker(System::Drawing::Size Borders, System::Drawing::Point Location) {
		setParams(Borders, Location);
	}
	void setParams(System::Drawing::Size Borders, System::Drawing::Point Location) {
		this->Borders = Borders;
		this->Location = Location;
	}
	bool BordersCheck(Shape^ obj) {
		Triangle^ t;
		CCircle^ c;
		Square^ s;
		for (int i = 0; i < Borders.Width; i++) {
			if (obj->isPointInObj(i, Borders.Height) || obj->isPointInObj(i, Location.Y)) {
				obj->setXY();
				t = dynamic_cast<Triangle^> (obj);
				c = dynamic_cast<CCircle^> (obj);
				s = dynamic_cast<Square^> (obj);
				if (c != nullptr) c->setR();
				else if (t != nullptr) t->setXY();
				else if (s != nullptr) s->setA();
				return false;
			}
		}
		for (int i = 0; i < Borders.Height; i++) {
			if (obj->isPointInObj(Borders.Width, i) || obj->isPointInObj(Location.X, i)) {
				obj->setXY();
				return false;
			}
		}
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
	System::Drawing::Size pBoxBorders;
	System::Drawing::Point pBoxLocation;
	
public:
	void setpBoxBorders(System::Drawing::Size Size) {
		pBoxBorders = Size;
	}
	void setpBoxLocation(System::Drawing::Point Location) {
		pBoxLocation = Location;
	}
	System::EventHandler^ ContainerChanged;
	ShapeContainer() {
		last = current = first = nullptr;
		size = 0;
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
			if (r->value->getIsSlctd())
				if (!Borders) r->value->Move(side);
				else r->value->Move(side, pBoxBorders, pBoxLocation);
			r = r->nextNode;
		}
		ContainerChanged->Invoke(this, nullptr);
	}
	void sizeChange(System::String^ operation, bool Borders) {
		Node^ r = first;
		while (r != nullptr) {
			if (r->value->getIsSlctd()) {
				if (!Borders) r->value->sizeChange(operation);
				else r -> value->sizeChange(operation,pBoxBorders, pBoxLocation);
			}
			r = r->nextNode;
		}
		ContainerChanged->Invoke(this, nullptr);
	}
};