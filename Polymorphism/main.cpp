#include <vector>
#include <iostream>
#include <string>

struct Point
{
    Point(double x, double y) { this->x = x; this->y = y; }
    double x;
    double y;
};

// class GeometricElement
// {
// public:
//     GeometricElement();
//     virtual void SetName() { name_ = "DefaultName"; }
//     virtual void Scale(double factor) { std::cout << "Base Scale" << std::endl; }
//     std::string GetName() { return name_; }
//
// protected:
//     std::vector<Point> vertex_list_;
//     std::string name_;
// };
//
// class Triangle : public GeometricElement
// {
// public:
//     Triangle(Point vertex1, Point vertex2, Point vertex3);
//     void SetName() { name_ = "Triangle"; }
//     void Scale(float factor) { std::cout << "Triangle Scale" << std::endl; }
// };
//
// Triangle::Triangle(Point vertex1, Point vertex2, Point vertex3)
// {
//   vertex_list_.push_back(vertex1);
//   vertex_list_.push_back(vertex2);
//   vertex_list_.push_back(vertex3);
// }
//
// GeometricElement::GeometricElement()
// {
//     SetName();
// }



class GeometricElement
{
public:
    GeometricElement(std::string name);
    virtual ~GeometricElement();
    std::string GetName() const { return name_; }
    virtual void Scale(double factor) = 0;

    protected:
        std::vector<Point> vertex_list_;
        std::string name_;
};

class Triangle : public GeometricElement
{
public:
    Triangle(Point vertex1, Point vertex2, Point vertex3);
    ~Triangle();
    void Scale(double factor) override { std::cout << "Triangle Scale" << std::endl; }
  void Scale(float factor) { std::cout << "Triangle scale float" << std::endl; }
  std::string GetName() const { return name_; }
};

GeometricElement::GeometricElement(std::string name)
: name_(name)
{ }

GeometricElement::~GeometricElement() { }

Triangle::~Triangle() { }

Triangle::Triangle(Point vertex1,
                   Point vertex2,
                   Point vertex3)
: GeometricElement("Triangle")
{
  vertex_list_.push_back(vertex1);
  vertex_list_.push_back(vertex2);
  vertex_list_.push_back(vertex3);
}

int main(int argc, char** argv)
{
    Point a(0., 0.); Point b(1., 0.); Point c(1., 1.);

    float factor = 2.f;

    GeometricElement* triangle = new Triangle(a, b, c);
    Triangle* triangle2 = new Triangle(a, b, c);
    std::cout << "Triangle name = " << triangle->GetName() << std::endl;
    triangle->Scale(2.f);
    triangle2->Scale(2.);

    return 0;
}
