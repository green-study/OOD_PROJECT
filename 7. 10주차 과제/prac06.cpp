#include <iostream>
#define interface class

interface DrawAPI {
public:
	virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI {
public:
	void drawCircle(int radius, int x, int y) {
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape {
protected:
	DrawAPI* drawAPI;

	Shape(DrawAPI* drawAPI) {
		this->drawAPI = drawAPI;
	}
	virtual ~Shape() {

	}

public:
	virtual void draw() = 0;
};

class Circle : public Shape {
	int x, y, radius;

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI) {
		this->x = x;
		this->y = y;
		this->radius = radius;
	}

	~Circle() {

	}

	void draw() {
		drawAPI->drawCircle(radius, x, y);
	}
};

int main() {
	RedCircle red;
	Shape* redCircle = new Circle(100, 100, 10, &red);
	GreenCircle green;
	Shape* greenCircle = new Circle(100, 100, 10, &green);

	redCircle->draw();
	greenCircle->draw();

	return 0;
}