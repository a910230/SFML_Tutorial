#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Object;

class Children {
public:
    size_t append(Object* child, string name);
    bool insert(Object* child, string name, size_t idx);
    bool remove(string name);
    bool remove(size_t idx);
    Object* operator[] (const string& key);
    Object* operator[] (size_t idx);
    const Object* operator[] (const string& key) const;
    const Object* operator[] (size_t idx) const;
    size_t size() const;

private:
    vector<pair<string, Object*>> children;
    unordered_map<string, size_t> keyToIndex;
};