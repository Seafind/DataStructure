#include <iostream>

using namespace std;

class Rectangle{
    public:
        void Set(int len, int wid);
        void Print() const;
        int ComputeArea();
        int ComputePerimeter();
    private:
        int length, width, area, perimeter;
};

void Rectangle::Set(int len, int wid){
    length = len;
    width = wid;
}

void Rectangle::Print() const{
    cout << "Length:    " << length << endl;
    cout << "Width:     " << width << endl;
}

int Rectangle::ComputeArea() {
    area = length * width;
    return area;
}

int Rectangle::ComputePerimeter() {
    perimeter = 2 * (length + width);
    return perimeter;
}

int main (){
    Rectangle rec;
    int len, wid;
    cout << "Please enter length and width: ";
    cin >> len >> wid;
    rec.Set(len, wid);
    rec.Print();
    cout << "Area:      " << rec.ComputeArea() << endl;
    cout << "Perimeter: " << rec.ComputePerimeter() << endl;
    return 0;
}