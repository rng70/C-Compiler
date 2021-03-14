#include <iostream>
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "SymbolTable.h"

using namespace std;

void printSubMenu(std::string s, std::string s1) {
    cout << "Press " << s << " to " << s1 << endl;
}

void menu() {
    printSubMenu("I", " Insert in the current Scope Table");
    printSubMenu("L", " LookUp the current Scope Table");
    printSubMenu("D", " Delete from current Scope Table");
    printSubMenu("P", " Print Scope Table");
    printSubMenu("S", " Enter into a new Scope");
    printSubMenu("E", " Exit the current Scope Table");
    cout << endl;
}

void takeInput() {
    freopen("input.txt", "r", stdin);

    int n;
    cout << "Enter the size of Symbol Table: " << endl;
    cin >> n;

    // Initialize Symbol Table
    SymbolTable currentSymbolTable(n);

    char ch;
    string name, type;
    while (true) {
        // Show operation menu
        menu();
        // Take user choice for operation
        cin >> ch;

        if (ch == 'I' || ch == 'i') {
            cin >> name >> type;
            currentSymbolTable.Insert(name, type);
        } else if (ch == 'L' || ch == 'l') {
            cin >> name;
            currentSymbolTable.LookUp(name);
        } else if (ch == 'D' || ch == 'd') {
            cin >> name;
            currentSymbolTable.Remove(name);
        } else if (ch == 'P' || ch == 'p') {
            char cp;
            cin >> cp;
            if (cp == 'A')
                currentSymbolTable.printAllTable();
            else
                currentSymbolTable.printCurrentScopeTable();
        } else if (ch == 'S' || ch == 's') {
            currentSymbolTable.ExitScope();
        } else if (ch == 'E' || ch == 'e') {
            currentSymbolTable.ExitScope();
        } else {
            break;
        }
    }
}

int main() {
    takeInput();
    return 0;
}
