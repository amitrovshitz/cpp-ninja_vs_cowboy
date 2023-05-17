#include "doctest.h"
#include "sources/Team.hpp"
#include <stdexcept>
using namespace ariel;
//1
TEST_CASE("Test constructor and getters") {
  Point p(1.5, 2.5);
  CHECK(p.getX() == 1.5);
  CHECK(p.getY() == 2.5);
}
//2
TEST_CASE("Test distance between two points") {
  Point p1(1, 2);
  Point p2(4, 6);
  double expected = 5;
  double result = p1.distance(p2);
  CHECK(result == expected);

  Point p3(-2, -3);
  Point p4(-5, -7);
  expected = 5;
  result = p3.distance(p4);
  CHECK(result == expected);
}
//3
TEST_CASE("print point.") {
  Point p(1, 2);
  string expected = "(1,2)";
  string result = p.print();
  CHECK(result == expected);
}
//4
TEST_CASE("Test moveTowards with positive distance") {
  Point source(0, 0);
  Point destination(5, 5);
  double distance = 2.5;
  Point expected(1.7678, 1.7678);
  Point result = Point::moveTowards(source, destination, distance);
  CHECK(result.getX() == expected.getX());
  CHECK(result.getY() == expected.getY());
}
//5
TEST_CASE("Test moveTowards with zero distance") {
  Point source(0, 0);
  Point destination(5, 5);
  double distance = 0;
  Point expected(0, 0);
  Point result = Point::moveTowards(source, destination, distance);
  CHECK(result.getX() == expected.getX());
  CHECK(result.getY() == expected.getY());
}
//6
TEST_CASE("Test moveTowards with negative distance") {
  ariel::Point source(0, 0);
  ariel::Point destination(5, 5);
  double distance = -2.5;
  CHECK_THROWS(Point::moveTowards(source, destination, distance));
}
//7
TEST_CASE("constructor- characters.")
{
  CHECK_NOTHROW(Cowboy c1("amit", Point(1, 2)));
	CHECK_NOTHROW(YoungNinja c2("ido", Point(3, 4)));
	CHECK_NOTHROW(TrainedNinja c3("shaked", Point(5, 6)));
	CHECK_NOTHROW(OldNinja c4("tal", Point(7, 8)));

}
//8
TEST_CASE("isAlve-character.")
{
  Cowboy c1("amit", Point(1, 2));
	YoungNinja c2("ido", Point(3, 4));
	TrainedNinja c3("shaked", Point(5, 6));
	OldNinja c4("tal", Point(7, 8));
	CHECK_EQ(c1.isAlive(), true);
	CHECK_EQ(c2.isAlive(), true);
	CHECK_EQ(c3.isAlive(), true);
	CHECK_EQ(c4.isAlive(), true);
}

//9
TEST_CASE("get the name of the character.")
{
  Cowboy c1("amit", Point(1, 2));
	YoungNinja c2("ido", Point(3, 4));
	TrainedNinja c3("shaked", Point(5, 6));
	OldNinja c4("tal", Point(7, 8));
	CHECK_EQ(c1.getName(), "amit");
	CHECK_EQ(c2.getName(), "ido");
	CHECK_EQ(c3.getName(), "shaked");
	CHECK_EQ(c4.getName(), "tal");


}
//10
TEST_CASE("get the loaction of the character.")
{
  Cowboy c1("amit", Point(1, 2));
	YoungNinja c2("ido", Point(3, 4));
	TrainedNinja c3("shaked", Point(5, 6));
	OldNinja c4("tal", Point(7, 8));
	CHECK_EQ(c1.getLocation().getX(), 1);
	CHECK_EQ(c1.getLocation().getY(), 2);

	CHECK_EQ(c2.getLocation().getX(), 3);
	CHECK_EQ(c2.getLocation().getY(), 4);

	CHECK_EQ(c3.getLocation().getX(), 5);
	CHECK_EQ(c3.getLocation().getY(), 6);

	CHECK_EQ(c4.getLocation().getX(), 7);
	CHECK_EQ(c4.getLocation().getY(), 8);

}
//11
TEST_CASE("print -character.")
{ 
  Cowboy c1("amit", Point(1, 2));
	YoungNinja c2("ido", Point(3, 4));
	TrainedNinja c3("shaked", Point(5, 6));
	OldNinja c4("tal", Point(7, 8));  
	CHECK_EQ(c1.print(), "Name: C(amit), HP: 100, Location: (1,2)");
	CHECK_EQ(c2.print(), "Name: Y(shaked), HP: 100, Location: (3,4)");
	CHECK_EQ(c3.print(), "Name: T(ido), HP: 120, Location: (5,6)");
	CHECK_EQ(c4.print(), "Name: N(tal), HP: 150, Location: (7,8)");
}
//12
TEST_CASE("move Characters.")
{ 
  Cowboy c1("amit", Point(1, 2));
	YoungNinja c2("ido", Point(3, 4));
	TrainedNinja c3("shaked", Point(5, 6));
	OldNinja c4("tal", Point(7, 8)); 
  CHECK_NOTHROW(c2.move(&c3));
	CHECK_NOTHROW(c3.move(&c2));
	CHECK_NOTHROW(c4.move(&c1));
}
//13
TEST_CASE("constructor - team.")
{
  Cowboy *c1 = new Cowboy("amit", Point(1, 2));
	YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
	TrainedNinja *c3 = new TrainedNinja("ido", Point(5, 6));
	OldNinja *c4 = new OldNinja("tal", Point(7, 8));

	Team t1(c1), t2(c3);

	CHECK_EQ(t1.getSize(), 1);
	CHECK_EQ(t2.getSize(), 1);
}
//14
TEST_CASE("hit function throw exception when thw argument is negative.")
{ 
   Cowboy *c1 = new Cowboy("amit", Point(1, 2));
   YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
   CHECK_THROWS(c1->hit(-20));

}
//15
TEST_CASE("constructor Ninja throw exception when the speed is negative.")
{
  CHECK_THROWS(Ninja(Point(1, 2), 30, "amit", -5));
}
//16
TEST_CASE("attack -team.")
{
  Cowboy *c1 = new Cowboy("amit", Point(1, 2));
	YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
	TrainedNinja *c3 = new TrainedNinja("ido", Point(5, 6));
	OldNinja *c4 = new OldNinja("tal", Point(7, 8));
  Team t1(c1), t2(c3);
  t1.add(c2);
  t2.add(c4);
  CHECK_NOTHROW(t1.attack(&t2));
  CHECK_NOTHROW(t2.attack(&t1));

}
//17
TEST_CASE("add-team.")
{
  Cowboy *c1 = new Cowboy("amit", Point(1, 2));
	YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
	TrainedNinja *c3 = new TrainedNinja("ido", Point(5, 6));
	OldNinja *c4 = new OldNinja("tal", Point(7, 8));

	Team t1(c1), t2(c3);
	CHECK_THROWS(t1.add(c1));
	CHECK_THROWS(t1.add(c3));
  CHECK_NOTHROW(t1.add(c2));
	CHECK_THROWS(t1.add(c1));
  CHECK_THROWS(t1.add(c2));
  CHECK_NOTHROW(t2.add(c4));
}

//18
TEST_CASE("team-stillAlive.")
{
  Cowboy *c1 = new Cowboy("amit", Point(1, 2));
	YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
	TrainedNinja *c3 = new TrainedNinja("ido", Point(5, 6));
	OldNinja *c4 = new OldNinja("tal", Point(7, 8));
  Team t1(c1), t2(c3);
  t1.add(c2);
  t2.add(c4);
  CHECK_EQ(t1.stillAlive(),2);
  CHECK_EQ(t2.stillAlive(),2);
  
}
//19
TEST_CASE("print-team.")
{
  Cowboy *c1 = new Cowboy("amit", Point(1, 2));
	YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
	TrainedNinja *c3 = new TrainedNinja("ido", Point(5, 6));
	OldNinja *c4 = new OldNinja("tal", Point(7, 8));

	Team t1(c1), t2(c3);
  t1.add(c2);
  t2.add(c4);
  CHECK_NOTHROW(t1.print());
  CHECK_NOTHROW(t2.print());
}
//20
TEST_CASE("after 10 figther in a team throw execption.")
{
  Cowboy *c1 = new Cowboy("amit", Point(1, 2));
	YoungNinja *c2 = new YoungNinja("shaked", Point(3, 4));
	TrainedNinja *c3 = new TrainedNinja("ido", Point(5, 6));
	OldNinja *c4 = new OldNinja("tal", Point(7, 8));
    Cowboy *c5 = new Cowboy("tom", Point(9, 10));
	YoungNinja *c6 = new YoungNinja("or", Point(11, 12));
	TrainedNinja *c7 = new TrainedNinja("gal", Point(13, 14));
	OldNinja *c8 = new OldNinja("yam", Point(15, 16));
    Cowboy *c9 = new Cowboy("yan", Point(17, 18));
	YoungNinja *c10 = new YoungNinja("ben", Point(19, 20));
	TrainedNinja *c11 = new TrainedNinja("noam", Point(21, 22));

	Team t1(c1);
  CHECK_NOTHROW(t1.add(c2));
  CHECK_NOTHROW(t1.add(c3));
  CHECK_NOTHROW(t1.add(c4));
  CHECK_NOTHROW(t1.add(c5));
  CHECK_NOTHROW(t1.add(c6));
  CHECK_NOTHROW(t1.add(c7));
  CHECK_NOTHROW(t1.add(c8));
  CHECK_NOTHROW(t1.add(c9));
  CHECK_NOTHROW(t1.add(c10));
  CHECK_THROWS(t1.add(c11));

}
