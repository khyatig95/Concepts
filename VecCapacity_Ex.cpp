#include <iostream> 
#include <vector>  
using namespace std; 

int main() 
{ 
    std::vector<int> vec; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 

    vec = {2,4,6,78, 2}; 
    cout << endl << "Add elements" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 

    vec.resize(3); 
    cout << endl << "Downsize vector" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl;

    vec.resize(7); 
    cout << endl << "Upsize vector" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 
    cout << " Vector is : { "; 
    for(auto itr=vec.begin(); itr!=vec.end(); ++itr) 
        cout << *itr << " "; 
    cout << " }" << endl; 

    for (int i = 0; i< 5; i++) 
        vec.push_back(i*2); 
    cout << endl << "Add elements" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl;

    vec.shrink_to_fit(); 
    cout << endl << "Shrink to fit" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 

    vec.reserve(15); 
    cout << endl << "Reserve" << endl; 
    cout << " Size of vector "<< vec.size() << endl; 
    cout << " Max size of vector "<< vec.max_size() << endl; 
    cout << " Capacity of vector "<< vec.capacity() << endl; 

    return 0; 

}
