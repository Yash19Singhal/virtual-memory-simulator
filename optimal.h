#ifndef OPTIMAL_H
#define OPTIMAL_H
#include <vector>
using namespace std;

class Optimal {
    int frames;
    vector<int> memory;
public:
    Optimal(int f);
    int simulate(vector<int> pages);
};
#endif
