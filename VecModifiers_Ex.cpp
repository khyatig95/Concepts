#include <iostream> 
#include <vector>  
using namespace std; 

int main() 
{ 
    vector<int> vec = {2,4,6,78, 2}; 
    vector<int>::iterator iter = vec.begin();
    
    vec.assign(3, 8); //Repeats 8 3 times in the vector
    cout << " Vector is : { "; 
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        cout << *itr << " "; 
    cout << " }" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 
    
    cout << endl<< "Insert element 100 at pos 2" << endl;
    vec.insert(iter+2, 100);
    cout << " Vector is : { "; 
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        cout << *itr << " "; 
    cout << " }" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 
    
    cout << endl << "Delete element at pos 2" << endl;
    iter = vec.begin();
    vec.erase(iter+2);
    cout << " Vector is : { "; 
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        cout << *itr << " "; 
    cout << " }" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 
    
    cout << endl<< "Emplace element 100 at pos 2" << endl;
    iter = vec.begin();
    vec.emplace(iter+2, 100);
    cout << " Vector is : { "; 
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        cout << *itr << " "; 
    cout << " }" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 
    
    cout << endl << "Clear vector" << endl;
    vec.clear();
    cout << " Vector is : { "; 
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        cout << *itr << " "; 
    cout << " }" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl;
    return 0; 

}
