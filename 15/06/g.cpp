#include <string>
#include <iostream>

using namespace std;

int main() {
    string s = "make pyb happy"s;
    std::cout<<"s[5]: "<<s[5]<<std::endl;
    s.replace(5, 3, "zhxx");    // 变成 make zhxx happy
    cout << s << endl;
}
