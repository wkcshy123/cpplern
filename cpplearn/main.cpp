#include <iostream>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    int a;
    int b;
    b = 100;
    do {
        cin >> a;
        if (a < b) {
            cout << "kleiner als b" << endl;
        }
        else if (a > b) {
            cout << "gro-er als b" << endl;
        }
    } while (a != b);
    cout << "erfolg! " << endl;
    system("read -p 'Press Enter to continue...' var");
    return 0;
}
