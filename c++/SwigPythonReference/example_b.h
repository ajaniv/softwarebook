/* File : example.h */

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



  
