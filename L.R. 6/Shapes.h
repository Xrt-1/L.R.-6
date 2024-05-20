#pragma once
ref class Point {
private: int a, b;
public:
	Point(int _a, int _b) : a(_a), b(_b) {}
};
ref class Shape {
protected:
	int x, y;
	System::Drawing::Brush^ ColorSlctd;
	bool isSelected;
	virtual void DrawSlctd(System::Drawing::Graphics^ g) = 0;
	virtual void DrawUnSlctd(System::Drawing::Graphics^ g) = 0;
public:
	virtual void Draw(System::Drawing::Graphics^ g) = 0;
	virtual bool isPointInObj(int x1, int y1) = 0;
	bool getIsSlctd() {
		return isSelected;
	}
	void Move(System::String^ side) {
		if (side == "right") x++;
		else if (side == "left") x--;
		else if (side == "up") y++;
		else if (side == "down") y--;
	}
	void setColorSlctd(System::Drawing::Brush^ color) { ColorSlctd = color; }
	void setIsSlctd(bool slctd) {
		isSelected = slctd;
	}
	virtual bool isA(System::String^ name) = 0;
};

ref class CCircle :public Shape {
protected:
	int r;
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
		g->FillEllipse(brush, x, y, r * 2, r * 2);
	}
	void DrawSlctd(System::Drawing::Graphics^ g) override {
		g->FillEllipse(ColorSlctd, x, y, r * 2, r * 2);
	}
public:
	CCircle(int _x, int _y) {
		r = 20;
		x = _x - r;
		y = _y - r;
		isSelected = true;
	}
	CCircle(int x, int y, bool slctd) : CCircle(x, y) {
		isSelected = slctd;
	}
	bool isPointInObj(int x1, int y1) override {
		int distanceSquared = (x1 - (x + r)) * (x1 - (x + r)) + (y1 - (y + r)) * (y1 - (y + r));
		return distanceSquared <= r * r;
	}
	void Draw(System::Drawing::Graphics^ g) override {
		if (this->isSelected) DrawSlctd(g);
		else DrawUnSlctd(g);
	}
	bool isA(System::String^ name) override {
		return (name == "Circle"); 
	}
};

ref class Square : public Shape {
protected:
	int a;
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
		g->FillRectangle(brush, x, y, a, a);
	}
	void DrawSelected(System::Drawing::Graphics^ g) override {
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::BlueViolet);
		g->FillRectangle(brush, x, y, a, a);
	}
public:
	Square(int _x,int _y){
		a = 10;
		x = _x - a / 2;
		y = _y - a / 2;
		isSelected = true;
	}
	bool isPointInObj(int x1, int y1) override {
		return (x1 - (x + a/2))* (x1 - (x+a/2)) + (y1 - (y+a/2)) * (y1 - (y+a/2)) <= a / 2;
	}
	void Draw(System::Drawing::Graphics^ g) override {
		if (this->isSelected) DrawSelected(g);
		else DrawUnSlctd(g);
	}
	bool isA(System::String^ name) override {
		return (name == "Square");
	}

};
ref class Triangle : public Shape {
protected:
	int size = 10;
	Point^ A = gcnew Point(-1, 0);
	Point^ B = gcnew Point(3, 0);
	Point^ C = gcnew Point(1, 4);

	//array <Point^>^ points = {};
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
	}
};