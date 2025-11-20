#include <iostream>
#include <unordered_map>
#include <string>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    // hash map
    unordered_map<int, int> map;
    // Map -> assignment
    map.insert({7, 200});
    map[5] = 100;
    // Map -> access
    map[5];       // prints: 100, If you access a key that doesn’t exist with myMap[key], it creates it with a default value
    map.count(7); // check without creating
    // Map -> remove
    map.erase(5); // removes a key and it's value
    // Looping over the map
    for (auto &pair : map)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }
    // Deque
    deque<int> de;
    de.push_back(1);  // addeds to the back
    de.push_front(3); // addes to the front
    de.pop_back();    // removes from the back
    de.pop_front();   // removes from the front
    // Stack
    stack<int> s;
    s.pop();
    s.push(6);
    s.size();

    // Queue
    queue<int> qe;
    qe.pop();// removes from the front
    qe.push(4); // addes to the rear
    qe.back(); // returns the rear element
    qe.front(); // returns the front element
    
}

/*
for (auto &num : arr)
{
    num += 5;  // adds 5 to each element
}
*/