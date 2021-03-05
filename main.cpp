//
//  main.cpp
//  MyVector
//
//  Created by Christoph Loik on 16.02.21.
//

#include <iostream>
#include "vector.hpp"
using namespace std;


int main(){

cout  <<"Test Konstruktor" << "\n";

Vector<int> konst;
Vector<int> konst2(5);
Vector<string> konst3{1};
Vector<int> kopier{1,2,3,4};
Vector<string> leer;

konst.push_back(5);
konst.push_back(10);
//kopier = konst;

cout << konst[0] << "==" << kopier[0] << "\n";
cout << konst[1] << "==" << kopier[1] << "\n";

cout << "\n" << "Test Size" << "\n";

cout << "2 == " << konst.size()<< "\n";
cout << "4 == " << kopier.size()<< "\n";
cout << "0 == " << konst2.size()<< "\n";
cout << "0 ==" << konst3.size() << "\n";

cout << "\n" << "Test empty" << "\n";
    
cout << leer.empty() << "== 1"<< "\n";
cout << konst.empty() << "== 0"<< "\n";
    
cout << "\n" << "Test push_back" << "\n";

for(size_t i{0}; i<10;i++){
konst.push_back(10);
konst2.push_back(5);}
leer.push_back("hello");
    
cout << "no error here :D"<< "\n";
cout << "konst size = 12 ==" << konst.size()<<"\n";
cout << "leer size = 1 ==" << leer.size()<<"\n";
cout <<  "konst 2 size = 10==" << konst2.size()<<"\n";
    
cout << "\n" << "Test pop_back" << "\n";

//cout << " Test print";
//cout << leer;
    

    

    









system("pause");
}
