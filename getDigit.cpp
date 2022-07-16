#include <iostream>
#include <string>
using namespace std; 
class myClass {
    public :
        void printDigit(int num);  
    private :
        int rem;
};

void myClass :: printDigit(int num) {
    cout << "Digits from ones to highest place are :" << endl; 
    if (num == 0) {
        cout << num <<endl;
        return;
    }
    while (num > 0) {
        rem = num%10;
        num = num/10;
        cout << rem << endl;
    }
}

int main() {
    myClass obj;
    
    obj.printDigit(0);
        
    return 0;
}
