#pragma once
#include "children.hpp"
#include "object.hpp"
using namespace std;

bool Children::append(Object* child, string name) {
    bool done = keyToIndex.insert({name, children.size()}).second;
    if (!done) return false;
    children.push_back(child);
    return true;
}

bool Children::insert(Object* child, string name, size_t idx) {
    if (idx > children.size()) return false;
    bool done = keyToIndex.insert({name, children.size()}).second;

    return false;
}

bool remove(string name) {
    return false;
}
    Object* operator[] (const string& key);
    Object* operator[] (size_t idx);
    size_t size() const;

private:
    vector<Object*> children;
    unordered_map<string, size_t> keyToIndex;
};