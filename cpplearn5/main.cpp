#include <iostream>
using namespace std;

struct hero {
    string name;
    int age;
    string sex;
};
//冒泡排序函数
void bubbleSort(hero* arr, int len)  //int * arr 也可以写为int arr[]
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j].age > arr[j + 1].age)
            {
                hero temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//打印数组函数
void printArray(hero *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i].name + " " << arr[i].age  << " " + arr[i].sex << endl;
    }
}

int main() {

    struct hero arr[5] {
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"}
    };
    int len = sizeof(arr) / sizeof(hero);

    bubbleSort(arr, len);

    printArray(arr, len);

    system( "read -n 1 -s -p \"Press any key to continue...\"" );

    return 0;
}