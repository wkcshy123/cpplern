#include <iostream>
#include <regex>
using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    for (int i=1; i<100; i++) {
        string j;
        bool a;
        bool b;
        a = false;
        b = false;
        j = to_string(i);

        for (int w = 0; w <= j.length(); w++) {
            string ww;
            ww = j[w];
            if (ww == "7") {
                a = true;
                break;
            }
        }

        if (i % 7 == 0) {
            b = true;
        }

        if (a && b) {
            cout << "hanyou 7 and 7 de beishu" << endl;
            continue;
        }
        else if (a && !b) {
            cout << "hanyou 7" << endl;
            continue;
        }
        else if (!a && b) {
            cout << "7 de beishu" << endl;
            continue;
        }
        cout << i << endl;
    }
    return 0;
}
