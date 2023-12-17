#include "./include/allocator.h"
#include "./include/queue.h"
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, int, less<int>, Allocator<pair<const int, int>>> test;
    test[0] = 1;
    for (int i = 1; i < 10; ++i) 
        test[i] = test[i - 1] * i;
    for(const auto &[x, y] : test) 
        cout << "Key = " << x << " Value = " << y << endl;
    
    Queue<string> q;
    q.push("!");
    q.push("Vasya");
    q.push(", ");   
    q.push("Hello");

    cout << q << endl;

    cout << "START\n";

    map<int, int, less<int>, Allocator<pair<const int, int>>> allocTest;
    const size_t initialSize = 10000;
    for (size_t i = 0; i < initialSize; ++i) 
        allocTest[i] = i;

    cout << "Map size after initial insertion: " << allocTest.size() << endl;
    const size_t elementsToRemove = 5000;
    for (size_t i = 0; i < elementsToRemove; ++i) 
        allocTest.erase(i);

    cout << "Map size after removal: " << allocTest.size() << endl;
    const size_t additionalElements = 7000;
    for (size_t i = initialSize; i < initialSize + additionalElements; ++i) 
        allocTest[i] = i;
    
    cout << "Map size after additional insertion: " << allocTest.size() << endl;
    for (size_t i = initialSize; i < allocTest.size(); ++i) 
        allocTest.erase(i);
    
    cout << "Map size after removal: " << allocTest.size() << endl;
    const size_t additionalElements1 = 17000;
    for (size_t i = initialSize; i < initialSize + additionalElements1; ++i) 
        allocTest[i] = i;
    
    cout << "Map size after additional insertion: " << allocTest.size() << endl;
    for (size_t i = initialSize; i < allocTest.size() - 10000; ++i) 
        allocTest.erase(i);
    
    cout << "END\n";
}
