/**
  @brief Assignment 2
  @author (Louis)YunHo Law
  */
#include <iostream>
#include <cmath>
using namespace std;

#include "Rectangle.h"

Rectangle::Rectangle(Point p1, Point p2){
    height = p1.getY() - p2.getY();
    width = p2.getX() - p1.getX();
    upperLeftVertex = p1;
}
Rectangle::Rectangle(Point p1, double heightValue, double widthValue){
    upperLeftVertex = p1;
    height = heightValue;
    width = widthValue;
}
/**
 * @brief Rectangle::getUpperLeftVertex
 * @return the upper left vertex
 */
Point Rectangle::getUpperLeftVertex() const{
    return upperLeftVertex;
}
/**
 * @brief Rectangle::getWidth
 * @return the width of the rectangle
 */
double Rectangle::getWidth() const{
    return width;
}
/**
 * @brief Rectangle::getHeight
 * @return the height of the rectangle
 */
double Rectangle::getHeight() const{
    return height;
}
/**
 * @brief Rectangle::getArea
 * @return the area of the rectangle
 */
double Rectangle::getArea() const{
    double area = height * width;
    return area;
}
/**
 * @brief Rectangle::getPerimeter
 * @return the perimeter of the rectangle
 */
double Rectangle::getPerimeter() const{
    double perimeter = (height + width) * 2;
    return perimeter;
}
/**
 * @brief Rectangle::getCenter
 * @return the center point of the rectangle
 */
Point Rectangle::getCenter() const{
    Point center;
    double newY = upperLeftVertex.getY() - height / 2;
    double newX = width / 2 + upperLeftVertex.getX();
    center.setX(newX);
    center.setY(newY);
    return center;
}
/**
 * @brief Rectangle::shift
 * @param xShift is the shifting distance of the x-coordinate
 * @param yShift is the shifting distance of the y-coordinate
 */
void Rectangle:: shift(double xShift, double yShift){
    upperLeftVertex.translate(xShift, yShift);
//    xShift += upperLeftVertex.getX();
//    yShift += upperLeftVertex.getY();
//    upperLeftVertex.setX(xShift);
//    upperLeftVertex.setY(yShift);
}
/**
 * @brief Rectangle::contains
 * @param p is the point
 * @return whether the point is inside the rectangle
 */
bool Rectangle:: contains(Point p){
    bool yes = ((p.getX() >= upperLeftVertex.getX()) && (p.getX() <= (width + upperLeftVertex.getX())) &&
               ((p.getY() <= upperLeftVertex.getY())) && (p.getY()) >= upperLeftVertex.getY() - height);
    if(yes)
        return true;
    else
        return false;

}


