#pragma once



ref class Shape {
protected:
	int x, y, pX, pY;
	System::Drawing::Brush^ ColorSlctd;
	System::Drawing::Brush^ ColorUnSlctd = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
	bool isSelected;
	virtual void DrawSlctd(System::Drawing::Graphics^ g) = 0;
	virtual void DrawUnSlctd(System::Drawing::Graphics^ g) = 0;
	int dMove = 5;
	virtual void set_pCoords() {
		pX = x;
		pY = y;
	}
	virtual void set_pParams() = 0;
public:
	void reset_dMove() { dMove = 5; }
	void set_dMove(int dMove) { this->dMove = dMove; }
	int get_dMove() { return dMove; }
	virtual void returnBack() {
		x = pX;
		y = pY;
	}

	virtual bool isPointInObj(int x1, int y1) = 0;
	bool getIsSlctd() {
		return isSelected;
	}
	virtual void sizeChange(System::String^ operation) = 0;

	void Draw(System::Drawing::Graphics^ g) {
		if (this->isSelected) DrawSlctd(g);
		else DrawUnSlctd(g);
	}

	virtual void Move(System::String^ side) {
		pX  = x, pY = y;
		if (side == "right") x+=dMove;
		else if (side == "left") x-=dMove;
		else if (side == "up") y-=dMove;
		else if (side == "down") y+=dMove;
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
	void set_pParams() override {
		Shape::set_pCoords();
		pR = r;
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
		set_pParams();
		int delta = 2;
		if (operation == "+") {
			r += delta;
			x -= delta;
			y -= delta;
		}
		else if (operation == "-") if (r >= 2) {
			r -= delta;
			x += delta;
			y += delta;
		}
	}
	void returnBack() override {
		Shape::returnBack();
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
	void set_pParams() override {
		Shape::set_pCoords();
		pA = a;
	}
public:
	Square(int _x,int _y){
		pA = a = 30;
		pX = x = _x - a / 2;
		pY = y = _y - a / 2;
		isSelected = true;
	}
	void returnBack() override{
		Shape::returnBack();
		a = pA;
	}
	bool isPointInObj(int x1, int y1) override {
		return (x1 - (x + a/2))* (x1 - (x+a/2)) + (y1 - (y+a/2)) * (y1 - (y+a/2)) <= (a / 2) * (a/2);
	}
	void sizeChange(System::String^ operation) override {
		set_pParams();
		int delta = 2;
		if (operation == "+") {
			a += delta;
			x -= delta / 2;
			y -= delta / 2;
		}
		else if (operation == "-") if (a >= 2) {
			a -= delta;
			x += delta / 2;
			y += delta / 2;
		}
	}
};
ref class Triangle : public Shape {
protected:
	double pHeight, height = 30;
	System::Drawing::PointF A, B, C, pA, pB, pC;
	array<System::Drawing::PointF>^ points = gcnew array<System::Drawing::PointF>(3);
	void DrawSlctd(System::Drawing::Graphics^ g) override {
		g->FillPolygon(ColorSlctd, points);
	}
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		g->FillPolygon(ColorUnSlctd,points);
	}
	void set_pParams() override {
		Shape::set_pCoords();
		pA = A;
		pB = B;
		pC = C;
		pHeight = height;
	}
public:
	void returnBack() override{
		Shape::returnBack();
		points[0] = A = pA;
		points[1] = B = pB;
		points[2] = C = pC;
		height = pHeight;
	}
	Triangle(int _x, int _y) {
		x = _x;
		y = _y;
		set_pParams();
		points[0] = A = System::Drawing::PointF(x, y - height / 3);
		points[1] = B = System::Drawing::PointF(x - height / 2, y + height * 3 / 2);
		points[2] = C = System::Drawing::PointF(x + height / 2, y + height * 3 / 2);
		isSelected = true;
	}
	void Move(System::String^ side) override {//проблема именно в этом методе
		Shape::Move(side);
		set_pParams();
		if (side == "right") {
			A.X += dMove;
			B.X += dMove;
			C.X += dMove;
		}
		else if (side == "left") {
			A.X -= dMove;
			B.X -= dMove;
			C.X -= dMove;
		}
		else if (side == "up") {
			A.Y -= dMove;
			B.Y -= dMove;
			C.Y -= dMove;
		}
		else if (side == "down") {
			A.Y += dMove;
			B.Y += dMove;
			C.Y += dMove;
		}
		points[0] = A;
		points[1] = B;
		points[2] = C;
	}
	bool isPointInObj(int x1, int y1) override {
		double triangleArea = System::Math::Abs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2);
		double subTriangle1Area = System::Math::Abs((A.X * (B.Y - y1) + B.X * (y1 - A.Y) + x1 * (A.Y - B.Y)) / 2);
		double subTriangle2Area = System::Math::Abs((A.X * (y1 - C.Y) + x1 * (C.Y - A.Y) + C.X * (A.Y - y1)) / 2);
		double subTriangle3Area = System::Math::Abs((x1 * (B.Y - C.Y) + B.X * (C.Y - y1) + C.X * (y1 - B.Y)) / 2);
		double area2 = subTriangle1Area + subTriangle2Area + subTriangle3Area;
		double delta = System::Math::Abs(triangleArea - area2);
		return (delta < 0.00011 || delta < -0.00011);
	}

	void sizeChange(System::String^ operation) override {
		set_pParams();
		if (operation == "+") {
			A.Y -= dMove;
			B.X -= dMove;
			C.X += dMove;
		}
		else if (operation == "-") {
			A.Y += dMove;
			B.X += dMove;
			C.X -= dMove;
			if (B.X == C.X) returnBack();
		}
		points[0] = A;
		points[1] = B;
		points[2] = C;
	}
};

