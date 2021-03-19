#include <bits/stdc++.h>
using namespace std;

string nth_ordinal(int i){
    string ords[4] = {"th", "st", "nd", "rd"};
    return to_string(i) + (i % 10 <= 3 && i / 10 != 1 ? ords[i % 10] : "th");
}

bool is_exist(string filename){
        ifstream ifs(filename);
        return ifs.is_open();
}

string read_file(string filename){
        ifstream ifs(filename);
        return string(istreambuf_iterator<char>(ifs),
                      istreambuf_iterator<char>());
}

int main(int argc, char *argv[]){
    if(argc <= 1){
        cout << "ERROR: input the number of times to try test cases" << endl;
        return 0;
    }
    
    if(!is_exist("code/wrong.cpp")){
        cout << "ERROR: code/wrong.cpp not found" << endl;
        return 0;
    }
    if(!is_exist("code/correct.cpp")){
        cout << "ERROR: code/correct.cpp not found" << endl;
        return 0;
    }
    if(!is_exist("code/testcase.cpp")){
        cout << "ERROR: code/testcase.cpp not found" << endl;
        return 0;
    }

    int loop = stoi(argv[1]);
    system("g++ -std=c++14 -O2 -o work/wrong code/wrong.cpp");
    system("g++ -std=c++14 -O2 -o work/correct code/correct.cpp");
    system("g++ -std=c++14 -O2 -o work/testcase code/testcase.cpp");

    cout << "MESSAGE: compilation finished" << endl;
    
    for(int i = 1; i <= loop; i++){
        system("./work/testcase > work/in.txt");
        system("./work/wrong < work/in.txt > work/outwrong.txt");
        system("./work/correct < work/in.txt > work/outcorrect.txt");
        
        string testcase = read_file("work/in.txt");
        string out_wrong = read_file("work/outwrong.txt");
        string out_correct = read_file("work/outcorrect.txt");
        
        if(out_wrong == out_correct) continue;
        cout << "[" + nth_ordinal(i + 1) + " testcase]" << endl;
        cout << "testcase:" << endl;
        cout << testcase << endl;
        cout << "wrong:" << endl;
        cout << out_wrong << endl;
        cout << "correct:" << endl;
        cout << out_correct << endl;
        return 0;
    }
    
    cout << "MESSAGE: no bug found" << endl;
}
