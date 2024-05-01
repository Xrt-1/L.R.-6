#pragma once
ref class Shape {
protected:
	int x, y;
	bool isSelected, isClicked;
	virtual void DrawUnSlctd(System::Drawing::Graphics^ g) = 0;
	virtual void DrawSlctd(System::Drawing::Graphics^ g) = 0;
public:
	virtual void Draw(System::Drawing::Graphics^ g) = 0;
	virtual bool isPointInObj(int x1, int y1) = 0;
	bool getIsSlctd() {
		return isSelected;
	}
	void setIsSlctd(bool slctd) {
		isSelected = slctd;
	}
	void setIsClckd(bool clckd) {
		isClicked = clckd;
	}
	bool getIsClckd() {
		return isClicked;
	}
};

ref class CCircle :public Shape {
protected:
	int r;
	void DrawUnSlctd(System::Drawing::Graphics^ g) override {
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::Gray);
		g->FillEllipse(brush, x, y, r * 2, r * 2);
	}
	void DrawSlctd(System::Drawing::Graphics^ g) override {
		System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::BlueViolet);
		g->FillEllipse(brush, x, y, r * 2, r * 2);
	}
public:
	CCircle(int _x, int _y) {
		r = 20;
		x = _x - r;
		y = _y - r;
		isClicked = false;
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
};