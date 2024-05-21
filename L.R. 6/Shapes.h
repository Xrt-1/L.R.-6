#pragma once



ref class Shape {
protected:
	int x, y, pX, pY;
	System::Drawing::Brush^ ColorSlctd;
	System::Drawing::Brush^ ColorUnSlctd = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
	bool isSelected;
	virtual void DrawSlctd(System::Drawing::Graphics^ g) = 0;
	virtual void DrawUnSlctd(System::Drawing::Graphics^ g) = 0;
public:
	virtual bool isPointInObj(int x1, int y1) = 0;
	bool getIsSlctd() {
		return isSelected;
	}
	virtual void sizeChange(System::String^ operation) = 0;
	virtual void setXY() {
		x = pX;
		y = pY;
	}

	void Draw(System::Drawing::Graphics^ g) {
		if (this->isSelected) DrawSlctd(g);
		else DrawUnSlctd(g);
	}

	virtual void Move(System::String^ side) {
		pX  = x, pY = y;
		if (side == "right") x+=5;
		else if (side == "left") x-=5;
		else if (side == "up") y-=5;
		else if (side == "down") y+=5;
	}

	
	void setColorSlctd(System::Drawing::Brush^ color) { ColorSlctd = color; }
	void setIsSlctd(bool slctd) {
		isSelected = slctd;
	}
};

ref class CCircle :public Shape {
protected:
	int r, pR;
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		g->FillEllipse(ColorUnSlctd, x, y, r * 2, r * 2);
	}
	void DrawSlctd(System::Drawing::Graphics^ g) override {
		g->FillEllipse(ColorSlctd, x, y, r * 2, r * 2);
	}
public:
	CCircle(int _x, int _y) {
		pR = r = 20;
		pX = x = _x - r;
		pY = y = _y - r;
		isSelected = true;
	}
	CCircle(int x, int y, bool slctd) : CCircle(x, y) {
		isSelected = slctd;
	}
	bool isPointInObj(int x1, int y1) override {
		int distanceSquared = (x1 - (x + r)) * (x1 - (x + r)) + (y1 - (y + r)) * (y1 - (y + r));
		return distanceSquared <= r * r;
	}
	void sizeChange(System::String^ operation) override {
		pR = r;
		if (operation == "+") r += 2;
		else if (operation == "-") if(r!= 0) r -= 2;
	}
	void setR() {
		r = pR;
	}
};

ref class Square : public Shape {
protected:
	int a, pA;
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		g->FillRectangle(ColorUnSlctd, x, y, a, a);
	}
	void DrawSlctd(System::Drawing::Graphics^ g) override {
		g->FillRectangle(ColorSlctd, x, y, a, a);
	}
public:
	Square(int _x,int _y){
		pA = a = 30;
		pX = x = _x - a / 2;
		pY = y = _y - a / 2;
		isSelected = true;
	}
	void setA() {
		a = pA;
	}
	bool isPointInObj(int x1, int y1) override {
		return (x1 - (x + a/2))* (x1 - (x+a/2)) + (y1 - (y+a/2)) * (y1 - (y+a/2)) <= (a / 2) * (a/2);
	}
	void sizeChange(System::String^ operation) override {
		pA = a;
		if (operation == "+") a += 3;
		else if (operation == "-") if (a!= 0) a -= 3;
	}
};
ref class Triangle : public Shape {
protected:
	int size = 30;
	double height = (System::Math::Sqrt(3) / 2) * size;
	System::Drawing::PointF A, B, C, pA, pB, pC;
	array<System::Drawing::PointF>^ points = gcnew array<System::Drawing::PointF>(3);
	void DrawSlctd(System::Drawing::Graphics^ g) override {
		g->FillPolygon(ColorSlctd, points);
	}
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		g->FillPolygon(ColorUnSlctd,points);
	}
	void Initialize() {
		System::Drawing::PointF _A(x , y - height / 3);
		System::Drawing::PointF _B(x - size / 2 , y + height * 3 / 2);
		System::Drawing::PointF _C(x + size / 2, y + height * 3 / 2);
		pA = A = _A;
		pB = B = _B;
		pC = C = _C;
		points[0] = A;
		points[1] = B;
		points[2] = C;
	}
public:
	void setCoords(){
		A = pA;
		B = pB;
		C = pC;
	}
	Triangle(int _x, int _y) {
		pX = x = _x;
		pY = y = _y;
		isSelected = true;
		Initialize();
	}
	void Move(System::String^ side) override {
		Shape::Move(side);
		Initialize();
	}
	bool isPointInObj(int x1, int y1) override {
		double triangleArea = System::Math::Abs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2);
		double subTriangle1Area = System::Math::Abs((A.X * (B.Y - y1) + B.X * (y1 - A.Y) + x1 * (A.Y - B.Y)) / 2);
		double subTriangle2Area = System::Math::Abs((A.X * (y1 - C.Y) + x1 * (C.Y - A.Y) + C.X * (A.Y - y1)) / 2);
		double subTriangle3Area = System::Math::Abs((x1 * (B.Y - C.Y) + B.X * (C.Y - y1) + C.X * (y1 - B.Y)) / 2);
		double area2 = subTriangle1Area + subTriangle2Area + subTriangle3Area;
		return ((int)area2 == (int)triangleArea);
	}

	void sizeChange(System::String^ operation) override {
		if (operation == "+") size += 3;
		else if (operation == "-") if (size != 0) size -= 3;
		Initialize();
	}
};

