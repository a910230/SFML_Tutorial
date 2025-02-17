#pragma once
#include "object.hpp"
using namespace std;

class Children {
public:
    bool append(Object* child, string name);
    bool insert(Object* child, string name, size_t idx);
    bool remove(string name);
    Object* operator[] (const string& key);
    Object* operator[] (size_t idx);
    size_t size() const;

private:
    vector<Object*> children;
    unordered_map<string, size_t> keyToIndex;
};