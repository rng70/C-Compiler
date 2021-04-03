#include <bits/stdc++.h>
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
    // For any normal text editor
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Only for Clion absolute path is needed
    freopen("G://GitHub Repositories//C-Compiler//input.txt", "r", stdin);
    freopen("G://GitHub Repositories//C-Compiler//output.txt", "w", stdout);

    int n;
    cin >> n;

    // Initialize Symbol Table
    SymbolTable currentSymbolTable(n);

    char ch;
    string name, type;
    // Show operation menu in console input mode
    //menu();
    while (cin >> ch) {
        // Show operation menu each time
        // menu();
        // Take user choice for operation
        // cin >> ch;

        if (ch == 'I' || ch == 'i') {
            cin >> name >> type;
            cout << ch << " " << name << " " << type << endl << endl;
            currentSymbolTable.Insert(name, type);
        } else if (ch == 'L' || ch == 'l') {
            cin >> name;
            cout << ch << " " << name << endl << endl;
            currentSymbolTable.LookUp(name);
        } else if (ch == 'D' || ch == 'd') {
            cin >> name;
            cout << ch << " " << name << endl << endl;
            bool t = currentSymbolTable.Remove(name);
            if (!t) {
                cout << name << " not found" << endl << endl;
            }
        } else if (ch == 'P' || ch == 'p') {
            char cp;
            cin >> cp;
            cout << ch << " " << cp << endl << endl;
            if (cp == 'A')
                currentSymbolTable.printAllTable();
            else
                currentSymbolTable.printCurrentScopeTable();
        } else if (ch == 'S' || ch == 's') {
            cout << ch << endl << endl;
            currentSymbolTable.EnterScope();
        } else if (ch == 'E' || ch == 'e') {
            cout << ch << endl << endl;
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
