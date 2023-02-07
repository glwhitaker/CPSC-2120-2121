#include "Node.h"
#include "List.h"
#include <iostream>

int main(){
    List<string> list1;
    for(int i = 0; i < 10; i++){
        list1.insertEnd("000" + to_string(i));
    }

    list1.print("List 1");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;

    list1.insertAt("_", 5);
    list1.print("List 2");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;  

    list1.insertStart("_");
    list1.print("List 3");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;

    list1.insertEnd("_");
    list1.print("List 4");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;

    list1.removeStart();
    list1.print("List 5");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;
        
    list1.removeEnd();
    list1.print("List 6");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;
        
    list1.removeAt(5);
    list1.print("List 7");
    cout << "First: " << list1.getFirst();
    cout << " | Last: " << list1.getLast();
    cout << " | Value 5: " << list1.find("0005");
    cout << " | Index 5: " << list1.getAt(5) << endl << endl;
    
    return 0;
}