/// Dimitar Gjorgievski, UIN 650730211
/// CS 251
/// Project 4 - Shape List
///
/// @filename tests.cpp
/// @date March 7, 2023

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

//Testing default constructor of class Shape
TEST_CASE("Shape default constructor") 
{
  Shape s;
  REQUIRE(s.getX() == 0); 
  REQUIRE(s.getY() == 0);
}

//Testing parametrized constructor of class Shape
TEST_CASE("Shape parametrized constructor") 
{
  Shape s(5,6);
  REQUIRE(s.getX() == 5); 
  REQUIRE(s.getY() == 6);
}

//Testing setter functions of class Shape
TEST_CASE("Shape setters") 
{
  Shape s;
  s.setX(10);
  s.setY(2);
  REQUIRE(s.getX() == 10); 
  REQUIRE(s.getY() == 2);
}

//Testing copy function of class Shape
TEST_CASE("Shape copy") 
{
  Shape s(5,2);
  s.copy();
  REQUIRE(s.getX() == s.copy()->getX()); 
  REQUIRE(s.getY() == s.copy()->getY());
}

//Testing default constructor of class Circle
TEST_CASE("Circle default constructor") 
{
  Circle c;
  REQUIRE(c.getX() == 0); 
  REQUIRE(c.getY() == 0);
  REQUIRE(c.getRadius() == 0);
}

//Testing parametrized constructor of class Circle for radius only
TEST_CASE("Circle default constructor for radius only") 
{
  Circle c(9);
  REQUIRE(c.getX() == 0); 
  REQUIRE(c.getY() == 0);
  REQUIRE(c.getRadius() == 9);
}

//Testing parametrized constructor of class Circle
TEST_CASE("Circle parametrized constructor") 
{
  Circle c(5, 6, 7);
  REQUIRE(c.getX() == 5); 
  REQUIRE(c.getY() == 6);
  REQUIRE(c.getRadius() == 7);
}

//Testing setter functions of class Circle
TEST_CASE("Circle setters") 
{
  Circle c;
  c.setX(10);
  c.setY(2);
  c.setRadius(7);
  REQUIRE(c.getX() == 10); 
  REQUIRE(c.getY() == 2);
  REQUIRE(c.getRadius() == 7);
}

//Testing copy function of class Circle
TEST_CASE("Circle copy") 
{
  Circle c(5,2,6);
  c.copy();
  REQUIRE(c.getX() == c.copy()->getX()); 
  REQUIRE(c.getY() == c.copy()->getY());
  REQUIRE(c.getRadius() == c.copy()->getRadius());
}

//Testing default constructor of class Rectangle
TEST_CASE("Rectangle default constructor") 
{
  Rectangle r;
  REQUIRE(r.getX() == 0); 
  REQUIRE(r.getY() == 0);
  REQUIRE(r.getWidth() == 0);
  REQUIRE(r.getHeight() == 0);
}

//Testing parametrized constructor of class Rectangle for width and height only
TEST_CASE("Rectangle parametrized constructor for width and height only") 
{
  Rectangle r(7, 4);
  REQUIRE(r.getX() == 0); 
  REQUIRE(r.getY() == 0);
  REQUIRE(r.getWidth() == 7);
  REQUIRE(r.getHeight() == 4);
}

//Testing parametrized constructor of class Rectangle
TEST_CASE("Rectangle parametrized constructor") 
{
  Rectangle r(5, 6, 7, 4);
  REQUIRE(r.getX() == 5); 
  REQUIRE(r.getY() == 6);
  REQUIRE(r.getWidth() == 7);
  REQUIRE(r.getHeight() == 4);
}

//Testing setter functions of class Rectangle
TEST_CASE("Rectangle setters") 
{
  Rectangle r;
  r.setX(10);
  r.setY(2);
  r.setWidth(7);
  r.setHeight(3);
  REQUIRE(r.getX() == 10); 
  REQUIRE(r.getY() == 2);
  REQUIRE(r.getWidth() == 7);
  REQUIRE(r.getHeight() == 3);
}

//Testing copy function of class Rectangle
TEST_CASE("Rectangle copy") 
{
  Rectangle r(3,4,8,7);
  r.copy();
  REQUIRE(r.getX() == r.copy()->getX()); 
  REQUIRE(r.getY() == r.copy()->getY());
  REQUIRE(r.getWidth() == r.copy()->getWidth());
  REQUIRE(r.getHeight() == r.copy()->getHeight());
  
}

//Testing default constructor of class RightTriangle
TEST_CASE("RightTriangle default constructor") 
{
  RightTriangle r;
  REQUIRE(r.getX() == 0); 
  REQUIRE(r.getY() == 0);
  REQUIRE(r.getBase() == 0);
  REQUIRE(r.getHeight() == 0);
}

//Testing parametrized constructor of class RightTriangle for base and height only
TEST_CASE("RightTriangle parametrized constructor for base and height only") 
{
  RightTriangle r(7, 4);
  REQUIRE(r.getX() == 0); 
  REQUIRE(r.getY() == 0);
  REQUIRE(r.getBase() == 7);
  REQUIRE(r.getHeight() == 4);
}

//Testing parametrized constructor of class RightTriangle
TEST_CASE("RightTriangle parametrized constructor") 
{
  RightTriangle r(5, 6, 7, 4);
  REQUIRE(r.getX() == 5); 
  REQUIRE(r.getY() == 6);
  REQUIRE(r.getBase() == 7);
  REQUIRE(r.getHeight() == 4);
}

//Testing setter functions of class RightTriangle
TEST_CASE("RightTriangle setters") 
{
  RightTriangle r;
  r.setX(10);
  r.setY(2);
  r.setBase(7);
  r.setHeight(3);
  REQUIRE(r.getX() == 10); 
  REQUIRE(r.getY() == 2);
  REQUIRE(r.getBase() == 7);
  REQUIRE(r.getHeight() == 3);
}

//Testing copy function of class RightTriangle
TEST_CASE("RightTriangle copy") 
{
  RightTriangle r(3,4,8,7);
  r.copy();
  REQUIRE(r.getX() == r.copy()->getX()); 
  REQUIRE(r.getY() == r.copy()->getY());
  REQUIRE(r.getBase() == r.copy()->getBase());
  REQUIRE(r.getHeight() == r.copy()->getHeight());
}

//Tetsing empty linked list
TEST_CASE("Empty CanvasList")
{
  CanvasList MyCanvas;

  REQUIRE(MyCanvas.size()==0);
  REQUIRE(MyCanvas.front()==NULL);
  REQUIRE(MyCanvas.pop_front()==NULL);
  REQUIRE(MyCanvas.pop_back()==NULL);
}

//Tetsing adding elements to linked list 
TEST_CASE("Increasing size of linked lis CanvasList")
{
  CanvasList MyCanvas;
  Shape *s = new Rectangle(3, 4, 8, 7);
  MyCanvas.push_back(s);

  REQUIRE(MyCanvas.size()==1);
  REQUIRE(MyCanvas.front()->value==s);
  
  s = new Circle (3, 4, 8);
  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==2);

  s = new RightTriangle (1, 2);
  MyCanvas.push_front(s);
  REQUIRE(MyCanvas.size()==3);
  REQUIRE(MyCanvas.front()->value==s);  
}

//Testing adding and removing elements from linked list
TEST_CASE("Increasing and decreasing size of linked lis CanvasList")
{
  CanvasList MyCanvas;
  Shape *s = new Rectangle(3, 4, 8, 7);
  MyCanvas.push_back(s);

  REQUIRE(MyCanvas.size()==1);
  REQUIRE(MyCanvas.front()->value==s);
  
  s = new Circle (3, 4, 8);
  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==2);

  s = new RightTriangle (1, 2);
  MyCanvas.push_front(s);
  REQUIRE(MyCanvas.size()==3);
  REQUIRE(MyCanvas.front()->value==s);  

  delete MyCanvas.pop_front();
  REQUIRE(MyCanvas.size()==2);

  MyCanvas.removeAt(1);
  REQUIRE(MyCanvas.size()==1);

  MyCanvas.removeAt(0);
  REQUIRE(MyCanvas.size()==0);
}

//Testing the push_front and pop_front functions
TEST_CASE("Pushing and popping elements only from the front")
{
  CanvasList MyCanvas;
  Shape *s = new Shape(3, 4);
  
  REQUIRE(MyCanvas.size()==0);

  MyCanvas.push_front(s);
  REQUIRE(MyCanvas.front()->value==s);
  REQUIRE(MyCanvas.size()==1);  

  s = new Circle(1, 4, 7);
  MyCanvas.push_front(s);
  REQUIRE(MyCanvas.front()->value==s);
  REQUIRE(MyCanvas.size()==2);

  s = new Rectangle(5, 6);
  MyCanvas.push_front(s);
  REQUIRE(MyCanvas.front()->value==s);
  REQUIRE(MyCanvas.size()==3);

  delete MyCanvas.pop_front();
  REQUIRE(MyCanvas.size()==2);

  delete MyCanvas.pop_front();
  REQUIRE(MyCanvas.size()==1);

  delete MyCanvas.pop_front();
  REQUIRE(MyCanvas.size()==0);

  REQUIRE(MyCanvas.isempty());
}

//Testing the push_back and pop_back functions
TEST_CASE("Pushing and popping elements only from the back")
{
  CanvasList MyCanvas;
  Shape *s = new Shape(3, 4);
  
  REQUIRE(MyCanvas.size()==0);

  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==1);  

  s = new Circle(1, 4, 7);
  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==2); 

  s = new Rectangle(5, 6);
  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==3);

  delete MyCanvas.pop_back();
  REQUIRE(MyCanvas.size()==2);

  delete MyCanvas.pop_back();
  REQUIRE(MyCanvas.size()==1);

  delete MyCanvas.pop_back();
  REQUIRE(MyCanvas.size()==0);

  REQUIRE(MyCanvas.isempty());
}

//Testing insertAfter and removeAt
TEST_CASE("Inserting and removing elements from the middle"){
  CanvasList MyCanvas;
  Shape *s = new Shape(3, 4);
  
  REQUIRE(MyCanvas.size()==0);

  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==1);  

  s = new Circle(1, 4, 7);
  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==2);

  s = new Rectangle(5, 6);
  MyCanvas.push_back(s);
  REQUIRE(MyCanvas.size()==3);

  s = new Shape(5, 6);
  MyCanvas.insertAfter(1, s);
  REQUIRE(MyCanvas.find(5,6)==2);
  REQUIRE(MyCanvas.shapeAt(2)==s);

  MyCanvas.removeAt(2);
  REQUIRE(MyCanvas.find(5,6)==-1);
}

//Testing clear function
TEST_CASE("Clear function"){
  CanvasList MyCanvas;
  
  Shape *s = new Shape(3, 4);
  MyCanvas.push_back(s);
  s = new Circle(1, 4, 7);
  MyCanvas.push_back(s);
  s = new Rectangle(5, 6);
  MyCanvas.push_back(s);

  REQUIRE(MyCanvas.size()==3);
  
  MyCanvas.clear();

  REQUIRE(MyCanvas.size()==0);
  REQUIRE(MyCanvas.isempty());
}


//Testing copy constructor
TEST_CASE("Copy test"){
  CanvasList MyCanvas;
  
  Shape *s = new Shape(3, 4);
  MyCanvas.push_back(s);
  s = new Circle(1, 4, 7);
  MyCanvas.push_back(s);
  s = new Rectangle(5, 6);
  MyCanvas.push_back(s);
 
  CanvasList CopyCanvas = MyCanvas;
  
  REQUIRE(MyCanvas.size()==CopyCanvas.size());
  REQUIRE(MyCanvas.shapeAt(0)->getX()==CopyCanvas.shapeAt(0)->getX());
  REQUIRE(MyCanvas.shapeAt(0)->getY()==CopyCanvas.shapeAt(0)->getY());
  REQUIRE(MyCanvas.shapeAt(1)->getX()==CopyCanvas.shapeAt(1)->getX());
  REQUIRE(MyCanvas.shapeAt(1)->getY()==CopyCanvas.shapeAt(1)->getY());
  REQUIRE(MyCanvas.shapeAt(2)->getX()==CopyCanvas.shapeAt(2)->getX());
  REQUIRE(MyCanvas.shapeAt(2)->getY()==CopyCanvas.shapeAt(2)->getY());
}

//Testing overwritten original with previous copy
TEST_CASE("Overwriting original"){
  
  CanvasList MyCanvas;
  
  Shape *s = new Shape(3, 4);
  MyCanvas.push_back(s);
  s = new Circle(1, 4, 7);
  MyCanvas.push_back(s);
  s = new Rectangle(5, 6);
  MyCanvas.push_back(s);
 
  CanvasList CopyCanvas = MyCanvas;

  MyCanvas.clear();

  s = new Shape;

  MyCanvas.push_back(s);
  
  REQUIRE(MyCanvas.size()!=CopyCanvas.size());
  REQUIRE(MyCanvas.shapeAt(0)->getX()!=CopyCanvas.shapeAt(0)->getX());
  REQUIRE(MyCanvas.shapeAt(0)->getY()!=CopyCanvas.shapeAt(0)->getY());
}

//Testing = operator
TEST_CASE("= operator"){
  
  CanvasList MyCanvas;
  
  Shape *s = new Shape(3, 4);
  MyCanvas.push_back(s);
  s = new Circle(1, 4, 7);
  MyCanvas.push_back(s);
  s = new Rectangle(5, 6);
  MyCanvas.push_back(s);

  CanvasList CopyCanvas;

  s = new Shape;
  CopyCanvas.push_back(s);

  REQUIRE(MyCanvas.size()!=CopyCanvas.size());
  
  CopyCanvas = MyCanvas;
  
  REQUIRE(MyCanvas.size()==CopyCanvas.size());
  REQUIRE(MyCanvas.shapeAt(0)->getX()==CopyCanvas.shapeAt(0)->getX());
  REQUIRE(MyCanvas.shapeAt(0)->getY()==CopyCanvas.shapeAt(0)->getY());
  REQUIRE(MyCanvas.shapeAt(1)->getX()==CopyCanvas.shapeAt(1)->getX());
  REQUIRE(MyCanvas.shapeAt(1)->getY()==CopyCanvas.shapeAt(1)->getY());
  REQUIRE(MyCanvas.shapeAt(2)->getX()==CopyCanvas.shapeAt(2)->getX());
  REQUIRE(MyCanvas.shapeAt(2)->getY()==CopyCanvas.shapeAt(2)->getY());
}