#include <iostream>
#include <string>
#include <vector>

using namespace std;

string& trim(string& s) {
    if (s.empty()) 
    {
        return s;
    }
 
    s.erase(0, s.find_first_not_of("\n\t"));
    s.erase(s.find_last_not_of("\n\t") + 1);
    return s;
}

int main() {
    string s = "hello";
    const char *c_str = s.c_str();
    cout << c_str << endl << s << endl;
    return 0;
}
