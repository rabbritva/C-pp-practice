#include <math.h>
class Complex {
    double x, y;
public:
    Complex(double x=0, double y=0) {
        this->x = x;
        this->y = y;
    }
    Complex(const Complex &z) {
        this->x = z.x;
        this->y = z.y;
    }
    void show() {
        if (x==0 && y==0) printf("0\n");
        else if (y>=0) printf("%f + i*%f\n",x,y);
        else printf("%f - i*%f\n",x,abs(y));
    }
    Complex operator+(Complex&c) const{return {x+c.x,y+c.y};}
    Complex operator-(Complex&c) const{return {x-c.x,y-c.y};}
    Complex operator*(Complex&c) const {return {(x*c.x-y*c.y),(x*c.y+c.x*y)};}
    Complex operator/(Complex&c) const {
        return {((x*c.x+y*c.y)/(c.x*c.x+c.y*c.y)),((c.x*y-x*c.y)/(c.x*c.x+c.y*c.y))};
    }
    friend Complex pow(Complex&c, short stepen) {
        double modul_z = pow(sqrt(c.x*c.x + c.y*c.y),stepen);
        double fi = atan2(c.y, c.x);
        double n_x = modul_z*cos(stepen*fi);
        double n_y = modul_z*sin(stepen*fi);
        return {n_x,n_y};
    }
};