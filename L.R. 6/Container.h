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
	void addOrSelect(int x, int y) {//провер€ет, не принадлежат ли координаты уже существующей фигуре. ≈сли нет - добавл€ет новую, иначе - закрашивает старую
		
		
		ContainerChanged->Invoke(this, nullptr);
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