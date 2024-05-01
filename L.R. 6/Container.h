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
	void addOrSelect(int x, int y) {//���������, �� ����������� �� ���������� ��� ������������ ������. ���� ��� - ��������� �����, ����� - ����������� ������
		
		
		ContainerChanged->Invoke(this, nullptr);
	}

	void del(Shape^ c) {
		if (c == nullptr || first == nullptr) return;
		Node^ r = first;
		Node^ p = nullptr; // ����-�������������� ���������� ����
		while (r != nullptr) {
			if (r->value == c) {
				if (p == nullptr) {
					// ���� ��������� ���� - ������ � ������
					if (current == first) current = first->nextNode;
					if (last == first) last = nullptr;
					Node^ nxt = first->nextNode;
					delete first;
					first = nxt;
					size--;
					break;

				}
				else {
					// ��������� ���� �� ������ � ������
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