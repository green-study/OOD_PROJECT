#include<iostream>
#include<string>
#define interface class
using namespace std;

interface Shape {
public:
	virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
	void draw() {
		cout << "Shape: Rectangle" << '\n';
	}
};

class Circle : public Shape {
public:
	void draw() {
		cout << "Shape: Circle" << '\n';
	}
};

class ShapeDecorator : public Shape {
protected:
	Shape* decoratedShape;
public:
	ShapeDecorator(Shape* decoratedShape) {
		this->decoratedShape = decoratedShape;
	}
	void draw() {
		decoratedShape->draw();
	}
};

class RedShapeDecorator : public ShapeDecorator {
	void setRedBorder(Shape* decoratedShape) {
		cout << "Border Color: Red" << '\n';
	}
public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {
	}

	void draw() {
		decoratedShape->draw();
		setRedBorder(decoratedShape);
	}

};

int main(){
	Shape * circle = new Circle();
	Shape* redCircle = new RedShapeDecorator(new Circle());
	Shape* redRectangle = new RedShapeDecorator(new Rectangle());
	cout << "Circle with normal border" << '\n';
	circle->draw();

	cout << '\n' << "Circle of red border" << '\n';
	redCircle->draw();

	cout << '\n' << "Rectangle of red border" << endl;
	redRectangle->draw();

	return 0;

}