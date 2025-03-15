#include <iostream>

using namespace std; 
//名空间，多个项目中只需要保证每个名空间中没有重名即可

int main(){
    int a = 10;
    std::cout << "Hello World!" << endl; //cout的全称是std::cout
    cout << "a = \n" << a << endl;
    return 0;
}