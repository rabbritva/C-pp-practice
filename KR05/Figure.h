#include <string>
#include <math.h>
using namespace std;
double const PI = fabs(acos(-1));

class Figure {
protected:
    const char* type_;
    static double TotalArea;
public:
    const char* name;
    static double getTotalArea() { return TotalArea; }
    virtual string getInfoStr() {
        string result = "Type: ";
        result += type_;
        result += "\nName: ";
        result += name;
        return result;
    }
    virtual void info() { printf("*\t*\t*\n%s\n*\t*\t*\n", getInfoStr().c_str()); }
    Figure(const char* type, const char* name) {
        this->type_ = type;
        this->name = name;
    }
}; double Figure::TotalArea = 0;

class Triangle : public Figure {
private:
    double a_ = 0, b_ = 0, c_ = 0;
    double area_ = 0;
    double area() {
        double P = (a_ + b_ + c_) / 2;
        double S = sqrt((P * (P - a_) * (P - b_) * (P - c_)));
        return S;
    }
public:
    Triangle(const char* type, const char* name, double a = 3, double b = 4, double c = 5) : Figure(type, name) {
        if (((a + b > c) && (a + c > b) && (c + b > a)) && (a != 0 && b != 0 && c != 0)) {
            this->a_ = a; this->b_ = b; this->c_ = c;
            area_ = area();
            TotalArea += area_;
        }
        else printf("The triangle is incorrectly defined\n");
    }
    Triangle(const char* name, double a = 3, double b = 4, double c = 5) : Triangle("Triangle", name, a, b, c) {}
    Triangle(double a = 3, double b = 4, double c = 5) : Triangle("Triangle", "Triangle", a, b, c) {}
    ~Triangle() { TotalArea -= area_; };
    double getArea() { return area_; }

    void info() {
        printf("*\t*\t*\n%s\nSides: a = %f; b = %f; c = %f\nArea: %f\n*\t*\t*\n", Figure::getInfoStr().c_str(), a_, b_, c_, area());
    }
};

class Quadrilaterials : public Figure {
private:
    double c_, d_;
protected:
    double a_, b_;
    double area_;
public:
    virtual double area() { return 0; }
    virtual double getArea() { return area_; }
    virtual string getInfoStr() {
        string result = Figure::getInfoStr();
        result += "\nSides: a = "; result += to_string(a_); result += "; b = "; result += to_string(b_);
        result += "; c = "; result += to_string(c_); result += "; d = "; result += to_string(d_);
        return result;
    }
    Quadrilaterials(const char* type, const char* name, double a, double b, double c, double d) : Figure(type, name) {
        this->a_ = a; this->b_ = b; this->c_ = c; this->d_ = d;
        area_ = area();
        TotalArea += area_;
    }
    Quadrilaterials(const char* type, const char* name, double a, double b) : Figure(type, name) {
        this->a_ = a; this->b_ = b; this->c_ = a; this->d_ = b;
        area_ = area();
        TotalArea += area_;
    }
    ~Quadrilaterials() { TotalArea -= area_; }
};

class Parallelogramm : public Quadrilaterials {
protected:
    double alpha_, h_;
    double area() {
        if (alpha_ != 0) return a_ * b_ * sin(alpha_ * PI / 180);
        else return a_ * h_;
    }
public:
    Parallelogramm(const char* type, const char* name, double a, double b, double alpha, double h) : Quadrilaterials(type, name, a, b) {
        this->alpha_ = alpha; this->h_ = h;
        area_ = area();
        TotalArea += area_;
    }
    Parallelogramm(const char* name, double a, double b, double alpha, double h) : Parallelogramm("Parallelogramm", name, a, b, alpha, h) {}
    Parallelogramm(double a, double b, double alpha, double h = 0) : Parallelogramm("Parallelogramm", "Parallelogramm", a, b, alpha, h) {}
    string getInfoStr() {
        string result = Quadrilaterials::getInfoStr();
        result += "\nHeight: "; result += to_string(h_);
        result += ";\talpha: "; result += to_string(alpha_);
        result += "\nArea: "; result += to_string(area_);
        return result;
    }
};