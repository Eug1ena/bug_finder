#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string res;
    cin >> res;
    
    if(a + b < 10){
        if(a + b == stoi(res)){
            cout << "ok" << endl;
        }else{
            cout << "ng" << endl;
        }
    }else{
        if(res == "over"){
            cout << "ok" << endl;
        }else{
            cout << "ng" << endl;
        }
    }
}
