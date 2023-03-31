/// Dimitar Gjorgievski, UIN 650730211
/// CS 251
/// Project 4 - Shape List
///
#pragma once

using namespace std;

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};

//Defining the default constructor of class Shape
Shape::Shape(){
    x = 0;
    y = 0;
}

//Defining the parametrized constructor of class Shape
Shape::Shape(int x, int y){
    this->x = x;
    this->y = y;
}

//Defining the destructor of class Shape
Shape::~Shape(){

}

//Defining the copy function of class Shape
Shape* Shape::copy(){
    Shape *copy = new Shape(this->x, this->y);
    return copy;
}

//Defining the getter for x of class Shape
int Shape::getX() const{
    return x;
}

//Defining the getter for y of class Shape
int Shape::getY() const{
    return y;
}

//Defining the setter for x of class Shape
void Shape::setX(int x){
    this->x = x;
}

//Defining the setter for y of class Shape
void Shape::setY(int y){
    this->y = y;
}

//Defining the printShape function of class Shape
void Shape::printShape() const{
    cout<<"It's a Shape at x: "<<x<<", y: "<<y<<endl;
}

class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};

//Defining the default constructor of class Circle
Circle::Circle(){
    x = 0;
    y = 0;
    radius = 0;
}

//Defining the parametrized constructor of class Circle with just radius parametrized
Circle::Circle(int r){
    x = 0;
    y = 0;
    radius = r;
}

//Defining the parametrized constructor of class Circle
Circle::Circle(int x, int y, int r){
    this->x = x;
    this->y = y;
    radius = r;
}

//Defining the destructor of class Circle
Circle::~Circle(){

}

//Defining the copy function of class Circle
Circle* Circle::copy(){
    Circle *copy = new Circle(this->x, this->y, this->radius);
    return copy;
}

//Defining the getter for radius of class Circle
int Circle::getRadius() const{
    return radius;
}

//Defining the setter for radius of class Circle
void Circle::setRadius(int r){
    radius = r;
}

//Defining the printShape function of class Circle
void Circle::printShape() const{
    cout<<"It's a Cirlce at x: "<<x<<", y: "<<y<<", radius: "<<radius<<endl;
}

class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

//Defining the default constructor of class Rectangle
Rectangle::Rectangle(){
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

//Defining the parametrized constructor of class Rectangle with just width and height parametrized
Rectangle::Rectangle(int w, int h){
    x = 0;
    y = 0;
    width = w;
    height = h;
}

//Defining the parametrized constructor of class Rectangle
Rectangle::Rectangle(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    width = w;
    height = h;
}

//Defining the destructor of class Rectangle
Rectangle::~Rectangle(){

}

//Defining the copy function of class Rectangle
Rectangle* Rectangle::copy(){
    Rectangle *copy = new Rectangle(this->x, this->y, this->width, this->height);
    return copy;
}

//Defining the getter for width of class Rectangle
int Rectangle::getWidth() const{
    return width;
}

//Defining the getter for height of class Rectangle
int Rectangle::getHeight() const{
    return height;
}

//Defining the setter for width of class Rectangle
void Rectangle::setWidth(int w){
    width = w;
}

//Defining the setter for height of class Rectangle
void Rectangle::setHeight(int h){
    height = h;
}

//Defining the printShape function of class Rectangle
void Rectangle::printShape() const{
    cout<<"It's a Rectangle at x: "<<x<<", y: "<<y<<" with width: "<<width<<" and height: "<<height<<endl;
}


class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};

//Defining the default constructor of class RightTriangle
RightTriangle::RightTriangle(){
    x = 0;
    y = 0;
    base = 0;
    height = 0;
}

//Defining the parametrized constructor of class RightTriangle with just base and height parametrized
RightTriangle::RightTriangle(int b, int h){
    x = 0;
    y = 0;
    base = b;
    height = h;
}

//Defining the parametrized constructor of class RightTriangle
RightTriangle::RightTriangle(int x, int y, int b, int h){
    this->x = x;
    this->y = y;
    base = b;
    height = h;
}

//Defining the destructor of class RightTriangle
RightTriangle::~RightTriangle(){

}

//Defining the copy function of class RightTriangle
RightTriangle* RightTriangle::copy(){
    RightTriangle *copy = new RightTriangle(this->x, this->y, this->base, this->height);
    return copy;
}

//Defining the getter for width of class RightTriangle
int RightTriangle::getBase() const{
    return base;
}

//Defining the getter for height of class RightTriangle
int RightTriangle::getHeight() const{
    return height;
}

//Defining the setter for width of class RightTriangle
void RightTriangle::setBase(int b){
    base = b;
}

//Defining the setter for height of class RightTriangle
void RightTriangle::setHeight(int h){
    height = h;
}

//Defining the printShape function of class RightTriangle
void RightTriangle::printShape() const{
    cout<<"It's a Right Triangle at x: "<<x<<", y: "<<y<<" with base: "<<base<<" and height: "<<height<<endl;
}