#pragma once
#include"Shapes.h"
#include "MyForm.h"

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
public:
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
		ContainerChanged->Invoke(this,nullptr);
	}
	void unclick() {
		Node^ r = first;
		while (r != nullptr) {
			if (r->value->getIsClckd()) {
				r->value->setIsClckd(false);
				r->value->setIsSlctd(false);
			}
			r = r->nextNode;
		}
	}
	void unselect() {
		unclick();
	}
	void addOrSelect(int x, int y, bool cBoxMulty, bool fCtrl) {//провер€ет, не принадлежат ли координаты уже существующей фигуре. ≈сли нет - добавл€ет новую, иначе - закрашивает старую
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
			Shape^ newShape = gcnew CCircle(x, y, true);
			unselect();
			push_back(newShape);
		}
		else {
			c = first;
			if (!fCtrl) unclick();
			for (int i = 0; i < size; i++) {
				if (c->value->isPointInObj(x, y) && !(c->value->getIsSlctd())) {
					c->value->setIsSlctd(true);
					c->value->setIsClckd(true);
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
		Node^ p = nullptr; // ”зел-предшественник удал€емого узла
		while (r != nullptr) {
			if (r->value == c) {
				if (p == nullptr) {
					// ≈сли удал€емый узел - первый в списке
					if (current == first) current = first->nextNode;
					if (last == first) last = nullptr;
					Node^ nxt = first->nextNode;
					delete first;
					first = nxt;
					size--;
					break;

				}
				else {
					// ”дал€емый узел не первый в списке
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

};