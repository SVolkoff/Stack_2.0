#include <stack.hpp>
#include <catch.hpp>

SCENARIO(" init")
{
	stack<int> s1();
	REQUIRE(s1.count() == 0);
}
SCENARIO("init with object")
{ 
	stack<int> s1(); 
	s1.push(5); 
	s1.push(6); 
  	stack<int> s2(s1());
	REQUIRE(s1.count() == s2.count());
	REQUIRE(s2.pop() == 6);
	REQUIRE(s1.pop() == 5);
}

SCENARIO("push") 
{
	stack<int> s1();
	s1.push(1);
	REQUIRE(s1.count() == 1);
	s1.push(2);
	REQUIRE(s1.count() == 2);
	s1.push(3);
	REQUIRE(s1.count() == 3);
}

SCENARIO("pop") 
{
	stack<int> s1();
	s1.push(1);
	s1.push(2);
	s1.push(3);
	int val = s1.pop();
	REQUIRE(s1.count() == 2 && val == 3);
	val = s1.pop();
	REQUIRE(s1.count() == 1 && val == 2);
	val = s1.pop();
	REQUIRE(s1.count() == 0 && val == 1);
}

SCENARIO("Stack operator= with swap") {
	stack<int> s1();
	stack<int> s2();
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(4);
	REQUIRE(s1.count() == 3);
	s2 = s1;
	REQUIRE(s2.count() == 3);
	REQUIRE(s1.pop() == s2.pop());
	REQUIRE(s1.pop() == s2.pop());
	REQUIRE(s1.pop() == s2.pop());
	
}
