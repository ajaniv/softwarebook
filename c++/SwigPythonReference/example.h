/* File : example.h */

#include <string>
#ifndef SWIG
struct A {
};
#endif

class Exc {
public:
  Exc(int c, const char *m) {
    code = c;
    strncpy(msg,m,256);
  }
  int code;
  char msg[256];
};

#if defined(_MSC_VER)
  #pragma warning(disable: 4290) // C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#endif

class Test {
public:
  int simple() throw(int) {
      throw(37);
      return 1;
  }
  int message() throw(const char *) {
      throw("I died.");
      return 1;
  }
  int hosed() throw(Exc) {
      throw(Exc(42,"Hosed"));
      return 1;
  } 
  int unknown() throw(A*) {
      static A a;
      throw &a;
      return 1;
  }
  int multi(int x) throw(int, const char *, Exc) {
     if (x == 1) throw(37);
     if (x == 2) throw("Bleah!");
     if (x == 3) throw(Exc(42,"No-go-diggy-die"));
     return 1;
  }
};

#if defined(_MSC_VER)
  #pragma warning(default: 4290) // C++ exception specification ignored except to indicate a function is not __declspec(nothrow)
#endif

class Shape {
public:
  Shape() {
    nshapes++;
  }
  virtual ~Shape() {
    nshapes--;
  };
  double  x, y;   
  void    move(double dx, double dy);
  virtual double area(void) = 0;
  virtual double perimeter(void) = 0;
  static  int nshapes;
};

class Circle : public Shape {
private:
  double radius;
public:
  Circle(double r) : radius(r) { };
  virtual double area(void);
  virtual double perimeter(void);
};

class Square : public Shape {
private:
  double width;
public:
  Square(double w) : width(w) { };
  virtual double area(void);
  virtual double perimeter(void);
};




class Rectangle : public Shape {
private:
	int sides;
public:
	Rectangle(int sidesV) : sides(sidesV){}
	Rectangle() : sides(0){}
	virtual double area(void) { return sides * sides; } 
	virtual double perimeter(void) { return sides * 2;}  
	int getSides() { return sides; }
};
