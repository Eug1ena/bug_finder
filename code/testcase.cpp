#include <iostream>
#include "libs/library.hpp"
using namespace std;

int main(){
    int a = rnd::choose(1, 9), b = rnd::choose(1, 9);
    cout << a << " " << b << endl;
}
