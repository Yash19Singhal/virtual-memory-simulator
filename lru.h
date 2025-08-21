#ifndef LRU_H
#define LRU_H
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class LRU {
    int frames;
    list<int> memory;
    unordered_map<int, list<int>::iterator> pos;
public:
    LRU(int f);
    int simulate(vector<int> pages);
};
#endif
