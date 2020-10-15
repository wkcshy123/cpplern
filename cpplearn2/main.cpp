#include <iostream>
#include <vector>
using namespace std;

int max(int a);

int main() {
    max(10);
    return 0;
}

int max(int a) {
    std::vector< int > arr;
    arr.reserve(a);
    for (int i=0; i<a; i++) {
        arr.push_back(i);
    }
    cout << "整个数组所占内存空间为： " << arr.size() << endl;
    return 0;
}
