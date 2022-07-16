#include <iostream>
#include <string>
using namespace std; 
class myClass {
    public :
        bool isSubstr(string ls, string ss);  
    private :
};

bool myClass :: isSubstr(string ls, string ss) {
    int index1 = 0;
    while (index1 < ls.size()) {
        if (ls[index1] == ss[0]) {
            cout << ls[index1] << " in longer string is equal to " << ss[0] << " in shorter string " << endl;
            if (ls.substr(index1, ss.size()) == ss) {
                return true;
            } else {
                cout << "No substring at this long string index " << endl;
            }
        }
        index1++;
    }
    return false;
}

int main() {
    myClass obj;
    
    string test1 = "bwaterbottle";
    string test2 = "bottlet";
    
    if (obj.isSubstr(test1, test2))
        cout << test2 << " is substring of " << test1 << endl;
    else 
        cout << test2 << " is NOT a substring of " << test1 << endl;
        
    return 0;
}
}
