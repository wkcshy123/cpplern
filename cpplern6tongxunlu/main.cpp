#include <iostream>
#include <typeinfo>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct memberList {
    string name;
    string sex;
    int age;
    long telephone;
    string adress;
};

int addMember(memberList* arr, int len){
    string name;
    string sex;
    int age;
    long telephone;
    string adress;
    int volumenIndex = 1;
    cout << "请添加联系人姓名：" << endl;
    cin >> name;
    cout << "请添加联系人性别：" << endl;
    cin >> sex;
    cout << "请添加联系人年龄：" << endl;
    cin >> age;
    cout << "请添加联系人电话：" << endl;
    cin >> telephone;
    cout << "请添加联系人地址：" << endl;
    cin >> adress;
    for (int i=0; i<len-1; i++) {
        if (arr[i].name.length()==0) {
            arr[i].name = name;
            arr[i].sex = sex;
            arr[i].age = age;
            arr[i].telephone = telephone;
            arr[i].adress = adress;
            break;
        }
        if (i==len-1){
            cout << "容量已满！" << endl;
            volumenIndex = 0;
        }
    }
    cout << "添加完成！ " << endl;
    return volumenIndex;
}

void showMember(memberList* arr, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i].name.length()==0) {
            break;
        }
        cout << arr[i].name + " " << arr[i].age  << " " + arr[i].sex + " " << arr[i].telephone << " " + arr[i].adress << endl;
    }
}

void deleteMember(memberList* arr, int len) {
    string to_delete;
    cout << "请输入要删除的人的名字：" << endl;
    cin >> to_delete;
    for (int i = 0; i < len-2; i++) {
        if (arr[i].name == to_delete) {
            for (int j = i; j < len-1; j++) {
                arr[j] = arr[j+1];
            }
            break;
        }
    }
    cout << "已删除！" << endl;
}

void searchMember(memberList* arr, int len) {
    string to_search;
    cout << "请输入要搜索的人的名字：" << endl;
    cin >> to_search;
    for (int i = 0; i < len-2; i++) {
        if (arr[i].name == to_search) {
            cout << arr[i].name + " " << arr[i].age << " " + arr[i].sex + " " << arr[i].telephone << " " + arr[i].adress
                 << endl;
            break;
        }
        if (i==len-1) {
            cout << "未找到" << endl;
        }
    }
}


void updateMember(memberList* arr, int len) {
    string to_update;
    bool n;
    bool s;
    bool a;
    bool t;
    bool ad;
    cout << "请输入要更新的人的名字：" << endl;
    cin >> to_update;
    for (int i = 0; i < len-2; i++) {
        if (arr[i].name == to_update) {
            cout << "是否更新名字？（1：是 0：否）" << endl;
            cin >> n;
            if (n) {
                cout << "请输入：" << endl;
                string x;
                cin >> x;
                arr[i].name = x;
            }
            cout << "是否更新性别？（1：是 0：否）" << endl;
            cin >> s;
            if (s) {
                cout << "请输入：" << endl;
                string x;
                cin >> x;
                arr[i].sex = x;
            }
            cout << "是否更新年龄？（1：是 0：否）" << endl;
            cin >> a;
            if (a) {
                cout << "请输入：" << endl;
                int x;
                cin >> x;
                arr[i].age = x;
            }
            cout << "是否更新电话？（1：是 0：否）" << endl;
            cin >> t;
            if (t) {
                cout << "请输入：" << endl;
                int x;
                cin >> x;
                arr[i].telephone = x;
            }
            cout << "是否更新地址？（1：是 0：否）" << endl;
            cin >> ad;
            if (ad) {
                cout << "请输入：" << endl;
                string x;
                cin >> x;
                arr[i].adress = x;
            }
            break;
        }
    }
    cout << "已更新！" << endl;
}

void deleteList(memberList* arr, int len) {
    memset(arr, 0, sizeof(struct memberList)*len);
    cout << "已清空！" << endl;
}

void quitList() {
    exit(0);
}

// 显示菜单
int showMenu() {
    cout << "请选择服务（1-7）" << endl;
    int a;
    cout << "---------------------" << endl;
    cout << "-----1. 添加联系人-----" << endl;
    cout << "-----2. 显示联系人-----" << endl;
    cout << "-----3. 删除联系人-----" << endl;
    cout << "-----4. 查找联系人-----" << endl;
    cout << "-----5. 修改联系人-----" << endl;
    cout << "-----6. 清空联系人-----" << endl;
    cout << "-----7. 退出通讯录-----" << endl;
    cout << "-----8. 保存通讯录-----" << endl;
    cout << "---------------------" << endl;
    do {
        cin >> a;
        if(a<=8 && a>=1) {
            break;
        } else cout << "请选择正确的数字！" << endl;
    } while (a > 8 || a <1);
    return a;
}


void write_books(memberList a[], int items, const char * fileName)
{
    FILE* ptr = fopen(fileName,"wb");
    if(! ptr) return; // TODO: better error handling
    fwrite( a, sizeof(memberList), items, ptr);
    fclose(ptr);
}

int read_books(memberList a[], const char * fileName)
{
    FILE* ptr = fopen(fileName,"rb");
    if( !ptr ) return 0;
    int n;
    for (n=0; !feof(ptr); ++n)
    {
        if ( fread(&a[n],sizeof(memberList),1,ptr) != 1) break;
    }

    fclose(ptr);
    return n;
}

int main() {
    int service;
    int volumen;
    // 选择服务类型，出现异常数则提醒；
    const char* path = "/Users/zf/CLionProjects/cpplern6tongxunlu/cmake-build-debug/b.dat";
    int items=1001;
    auto * ar = static_cast<memberList *>(malloc(sizeof(memberList) * items));
    if ( ! ar) return 0;
    items = read_books( ar, path);
    free(ar);

    memberList arr[1001];
    int len = 1001;
    for (int i=0; i<len-2; i++) {
        arr[i] = ar[i] ;
    }
    while (true) {
        service = showMenu();
        // 执行服务
        switch (service) {
            case 1:
                volumen = addMember(arr, len); // 添加联系人
                while (true) {
                    int a;
                    if (volumen) {
                        cout << "是否继续添加？(1：是 0：否）" << endl;
                        cin >> a;
                        if (a) {
                            volumen = addMember(arr, len);
                        }
                        else {break;}
                    } else {break;}
                }
                break;
            case 2:
                showMember(arr, len); // 显示联系人
                break;
            case 3:
                deleteMember(arr, len); // 删除联系人
                break;
            case 4:
                searchMember(arr, len); // 搜索联系人
                break;
            case 5:
                updateMember(arr, len); // 更新联系人
                break;
            case 6:
                deleteList(arr, len); // 清空通讯录
                break;
            case 7:
                quitList(); // 退出通讯录
                break;
            case 8:
                write_books(arr, 1001, path);
            default:
                break;
        }
    }
}
