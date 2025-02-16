#include <iostream>
#include <cmath>

using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double getArea() const
    {
        return M_PI * radius * radius;
    }

    double getPerimeter() const
    {
        return 2 * M_PI * radius;
    }
};

int main()
{
    double r;
    cout << "Enter radius of the circle: ";
    cin >> r;

    Circle circle(r);

    cout << "Area: " << circle.getArea() << endl;
    cout << "Perimeter: " << circle.getPerimeter() << endl;

    return 0;
}
