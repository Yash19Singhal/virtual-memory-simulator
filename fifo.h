#ifndef FIFO_H
#define FIFO_H
#include <vector>
#include <queue>
using namespace std;

class FIFO {
    int frames;
    vector<int> memory;
    queue<int> q;
public:
    FIFO(int f);
    int simulate(vector<int> pages);
};
#endif