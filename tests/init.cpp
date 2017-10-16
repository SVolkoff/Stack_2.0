#include <catch.hpp>
#include <stack.hpp>

SCENARIO("stack init", "[init]")
{
	stack<int> st;
	REQUIRE(st.count() == 0);
}

SCENARIO("stack init object", "[init object]") 
{
	stack<int> st1;

	st1.push(1);
	st1.push(2);
	st1.push(3);
	stack<int> st2(st1);
	REQUIRE(st1.count() ==3 ); 
	REQUIRE(st1.count() == st2.count());
}

SCENARIO("stack op=", "[op=]")
{
	stack<int> st1;

	st1.push(1);
	st1.push(2);
	st1.push(3);
	stack<int> st2 = st1;
	REQUIRE(st1.count() ==3 ); 
	REQUIRE(st1.count() == st2.count() );
}

SCENARIO("stack push", "[push]")
{
	stack<int> st;
	REQUIRE(st.count() == 0);
	st.push(6);
	REQUIRE(st.count() == 1);
	st.push(7);
	REQUIRE(st.count() == 2);
	st.push(78);
	REQUIRE(st.count() == 3);
}
SCENARIO("pop") 
{
	stack<int> s1;
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
