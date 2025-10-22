//
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <string>

#include "Queue.h"
#include "Stack.h"

using namespace std;
using namespace csi281;

TEST_CASE("Queue Tests", "[queue]") {
  SECTION("Queue w/ int tests") {
    Queue<int> q1 = Queue<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    q1.push(7);
    q1.push(3);
    q1.push(7);
    q1.push(25);
    CHECK(q1.peek() == 7);
    q1.push(8);
    CHECK(q1.getCount() == 5);
    CHECK(q1.peek() == 7);
    cout << "Queue before Pop:" << endl;
    q1.debugPrint();
    CHECK(q1.pop() == 7);
    CHECK(q1.peek() == 3);
    cout << "Queue after Pop:" << endl;
    q1.debugPrint();
  }

  SECTION("Queue w/ string tests") {
    Queue<string> q2 = Queue<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    q2.push("cat");
    q2.push("Doug");
    q2.push("cat");
    q2.push("groceries");
    CHECK(q2.peek() == "cat");
    q2.push("dishes");
    CHECK(q2.getCount() == 5);
    CHECK(q2.peek() == "cat");
    cout << "Queue before Pop:" << endl;
    q2.debugPrint();
    CHECK(q2.pop() == "cat");
    CHECK(q2.peek() == "Doug");
    cout << "Queue after Pop:" << endl;
    q2.debugPrint();
  }
}

TEST_CASE("Stack Tests", "[stack]") {
  SECTION("Stack w/ int tests") {
    Stack<int> s1 = Stack<int>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    s1.push(1);
    s1.push(8);
    s1.push(3);
    CHECK(s1.peek() == 3);
    s1.push(8);
    CHECK(s1.getCount() == 4);
    CHECK(s1.peek() == 8);
    cout << "Stack before Pop" << endl;
    s1.debugPrint();
    CHECK(s1.pop() == 8);
    CHECK(s1.peek() == 3);
    cout << "Stack after Pop" << endl;
    s1.debugPrint();
  }

  SECTION("Stack w/ string tests") {
    Stack<string> s2 = Stack<string>();
    // Ensure that push(), pop(), and peek()
    // work properly in concert with getCount()
    // and remove()
    s2.push("cat");
    s2.push("dog");
    s2.push("mouse");
    CHECK(s2.peek() == "mouse");
    s2.push("dog");
    CHECK(s2.getCount() == 4);
    CHECK(s2.peek() == "dog");
    cout << "Stack before Pop" << endl;
    s2.debugPrint();
    CHECK(s2.pop() == "dog");
    CHECK(s2.peek() == "mouse");
    cout << "Stack after Pop" << endl;
    s2.debugPrint();
  }
}
