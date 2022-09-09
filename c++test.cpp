// #include <iostream>
// using namespace std;
 
// class Test
// {
//     static int x;
// public:
//     Test() { x++; }
//     static int getX() {return x;}
// };
 
// int Test::x = 0;
 
// int main()
// {
//     cout << Test::getX() << " ";
//     Test t[5];
//     cout << Test::getX();
//     return 0;
// }

// #include <iostream>
// using namespace std;
 
// class A
// {
//     int x;
// public:
//     A() { cout << "A's constructor called " << endl;  }
// };
 
// class B
// {
//     static A a;
// public:
//     B() { cout << "B's constructor called " << endl; }
//     static A getA() { return a; }
// };
// A B::a;
// int main()
// {
//     B b;
//     //A a = b.getA();
//     return 0;
// }

// #include<iostream>
// using namespace std;
 
// class Test
// {
// private:
//   int x;
// public:
//   Test(int x = 0) { this->x = x; }
//   void change(Test *t) { this->x = t->x; }
//   void print() { cout << "x = " << x << endl; }
// };
 
// int main()
// {
//   Test obj(5);
//   Test *ptr = new Test (10);
//   obj.change(ptr);
//   obj.print();
//   return 0;
// }


// #include<iostream>
// using namespace std;
 
// class Test
// {
// private:
//   int x;
//   int y;
// public:
//   Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
//   static void fun1() { cout << "Inside fun1()"; }
//   static void fun2() { cout << "Inside fun2()"; fun1(); }
// };
 
// int main()
// {
//   Test obj;
//   obj.fun2();
//   return 0;
// }

// #include<iostream>
// using namespace std;
 
// class Test
// {
// private:
//   int x;
//   int y;
// public:
//   Test (int y = 0, int x = 0) { this->x = x; this->y = y; }
//   Test &setX(int a) { x = a; return *this; }
//   Test &setY(int b) { y = b; return *this; }
//   void print() { cout << "x = " << x << " y = " << y << endl; }
// };
 
// int main()
// {
//   Test obj1;
//   obj1.setY(10).setX(30);
//   obj1.print();
//   return 0;
// }


#include<iostream>
using namespace std;
 
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y; }
  void setX(int a) { x = a; }
  void setY(int b) { y = b; }
  void destroy()  { delete this; }               
  void print() { cout << "x = " << x << " y = " << y << endl; }
};
 
int main()
{
  Test obj;
  obj.destroy();
  obj.print();
  return 0;
}