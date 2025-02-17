#include "children.hpp"
#include "object.hpp"
using namespace std;

bool Children::append(Object* child, string name) {
    bool done = keyToIndex.insert({name, children.size()}).second;
    if (!done) return false;
    children.push_back({name, child});
    return true;
}

bool Children::insert(Object* child, string name, size_t idx) {
    if (idx > children.size()) return false;
    bool done = keyToIndex.insert({name, idx}).second;
    if (!done) return false;
    children.insert(children.begin() + idx, {name, child});
    for (int i = idx + 1; i < children.size(); ++i) {
        keyToIndex[children[i].first] = i;
    }
    return true;
}

bool Children::remove(string name) {
    if (keyToIndex.find(name) == keyToIndex.end()) return false;
    size_t idx = keyToIndex[name];
    children.erase(children.begin() + idx);
    keyToIndex.erase(name);
    for (int i = idx; i < children.size(); ++i) {
        keyToIndex[children[i].first] = i;
    }
    return true;
}

bool Children::remove(size_t idx) {
    if (idx >= children.size()) return false;
    keyToIndex.erase(children[idx].first);
    children.erase(children.begin() + idx);
    for (int i = idx; i < children.size(); ++i) {
        keyToIndex[children[i].first] = i;
    }
    return true;
}

Object* Children::operator[] (const string& key) {
    if (keyToIndex.find(key) == keyToIndex.end()) return nullptr;
    return children[keyToIndex[key]].second;
}

Object* Children::operator[] (size_t idx) {
    return children[idx].second;
}

const Object* Children::operator[] (const string& key) const {
    auto it = keyToIndex.find(key); 
    if (it == keyToIndex.end()) return nullptr;
    return children[it->second].second;
}

const Object* Children::operator[] (size_t idx) const {
    return children[idx].second;
}

size_t Children::size() const {
    return children.size();
}