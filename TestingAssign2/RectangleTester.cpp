/**
  @brief Assignment 2 Unit Testing
  @author (Louis)YunHo Law
  */

//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Point.h"
#include "Rectangle.h"

#include <cmath>
using namespace std;

TEST_CASE( "Rectangle/Constructor 1", "2 arguments constructor" ) {
    //CAPTURE is like cout but only shows if we fail the test
    //CAPTURE("My message");
    Point p1(1 , 2);
    Point p2(6 , -2);
    Rectangle r1(p1 , p2);
    //An actual test
    Point temp = r1.getUpperLeftVertex();
    REQUIRE( temp.isSameAs(p1) == true );
    REQUIRE( r1.getHeight() == Approx(4));
    REQUIRE( r1.getWidth() == Approx(5));
}

TEST_CASE( "Rectangle/Construtor 2", "3 arguments constructor" ){
    Point p1(-3 , 5);
    Rectangle r1(p1, 6 , 7);

    Point temp = r1.getUpperLeftVertex();
    REQUIRE( temp.isSameAs(p1) == true );
    REQUIRE( r1.getHeight() == 6);
    REQUIRE( r1.getWidth() == 7);

}

TEST_CASE( "Rectangle/getArea", "test finding area"){
    Point p1(5 , 8);
    Point p2(10 , -5);
    Rectangle r1(p1 , p2);

    double tempArea = r1.getArea();

    REQUIRE( tempArea == Approx(65));
}

TEST_CASE( "Rectangle/getPerimeter", "test finding perimeter"){
    Point p1(-5 , 8);
    Rectangle r1(p1, 8 , 12);

    double tempPerimeter = r1.getPerimeter();

    REQUIRE( tempPerimeter == Approx(40));
}

TEST_CASE( "Rectangle/getCenter", "test finding the center"){
    Point p1(0 , 0);
    Point p1(2 , -8);
    Point c1(1 , -4);
    Point c2(1 , 4);
    Rectangle r1(p1 , p2);

    Point temp = getCenter();

    REQUIRE( temp.isSameAs(c1) == true);
    REQUIRE( temp.isSameAs(c2) == false);
}

TEST_CASE( "Rectangle/shift", "test shfiting point"){
    Point p1(-1 , -7);
    Point p2(0 , -8);
    Rectangle r1(p1 , p2);
    Point s1(2 , 3);
    Point s2(-2 , 4);

    r1.shift(3 , 11);
    Point temp = r1.getUpperLeftVertex();

    REQUIRE( temp.isSameAs(s1) == true);
    REQUIRE( temp.isSameAs(s2) == false);
}

TEST_CASE( "Rectangle/contain", "test identifying the point"){
    Point p1(1 , 3);
    Point p2(4 , -4);
    Rectangle r1(p1 , p2);
    Point c1(1 , 3);
    Point c2(4 , 4);
    Point c3(2 , 1);
    Point c4(2 , 5);

    REQUIRE( r1.contain(c1) = true);
    REQUIRE( r1.contain(c2) = false);
    REQUIRE( r1.contain(c3) = true);
    REQUIRE( r1.contain(c4) = false);
}
