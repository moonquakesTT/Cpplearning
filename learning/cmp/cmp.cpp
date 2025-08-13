#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    int age;

    // 重写小于运算符
    bool operator<(const Person &other) const {
        if (age != other.age)
            return age < other.age; // 年龄小的排前
        return name < other.name;   // 年龄相同按名字排序
    }
};

int main() {
    vector<Person> v = {{"Alice", 25}, {"Bob", 20}, {"Charlie", 25}, {"David", 20}};
    
    // 不用额外传比较器
    sort(v.begin(), v.end());

    for (auto &p : v) {
        cout << p.name << " " << p.age << endl;
    }
}
