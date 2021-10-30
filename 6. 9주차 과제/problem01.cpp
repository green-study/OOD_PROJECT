#include <iostream>
#include <string>

class Shape {
public:
	virtual void draw() = 0;
};

class RoundedRectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {
public:
	void draw() {
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory {
public:
	virtual Shape* getShape(const char* str) = 0;
};

class ShapeFactory : public AbstractFactory {
public:
	Shape* getShape(const char* str) {
		if (!strcmp(str, "RECTANGLE")) {
			return new Rectangle();;
		}
		if (!strcmp(str, "SQUARE")) {
			return new Square();
		}
		return NULL;
	}
};

class RoundedShapeFactory :public AbstractFactory {
public:
	Shape* getShape(const char* str) {
		if (!strcmp(str, "RECTANGLE")) {
			return new RoundedRectangle();;
		}
		if (!strcmp(str, "SQUARE")) {
			return new RoundedSquare();
		}
		return NULL;
	}
};

class FactoryProducer {
public:
	static AbstractFactory* getFactory(bool rounded) {
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};

int main() {
	//get shape factory
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);
	//get an object of Shape Rectangle
	Shape* shape1 = shapeFactory->getShape("RECTANGLE");
	//call draw method of Shape Rectangle
	shape1->draw();
	//get an object of Shape Square 
	Shape* shape2 = shapeFactory->getShape("SQUARE");
	//call draw method of Shape Square
	shape2->draw();
	//get shape factory
	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);
	//get an object of Shape Rectangle
	Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
	//call draw method of Shape Rectangle
	shape3->draw();
	//get an object of Shape Square 
	Shape* shape4 = shapeFactory1->getShape("SQUARE");
	//call draw method of Shape Square
	shape4->draw();
	return 0;
}