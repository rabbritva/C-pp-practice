int NOD(int a, int b) {
    while (a!=0 && b!=0) {
        if (a>b) a = a % b;
        else b = b % a;
    }
    return a+b;
}
class Fraction {
    int chisl, znamen;
public:
    Fraction(int chisl, int znam) {
        int c = NOD(chisl,znam);
        this->chisl = chisl/c;
        this->znamen = znam/c;
    }
    ~Fraction() {
        cout<<"~Fraction()"<<endl;
    };
    void show() {
        cout<<chisl<<"/"<<znamen<<endl;
    }
    Fraction& operator=(const Fraction& other) {
        if (this != &other) {
            this->chisl = other.chisl; this->znamen = other.znamen;
        }
        return *this;
    }
    Fraction operator+(Fraction& b) const{
        return {chisl*b.znamen + znamen*b.chisl,znamen*b.znamen};
    }
    Fraction operator-(Fraction& b) const{
        return {chisl*b.znamen - znamen*b.chisl,znamen*b.znamen};
    }
    Fraction operator*(Fraction& b) const{
        return {chisl*b.chisl,znamen*b.znamen};
    }
    Fraction operator/(Fraction& b) const{
        return {chisl*b.znamen,znamen*b.chisl};
    }
};