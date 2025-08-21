#include "utils.h"
#include <iostream>
using namespace std;

void printFrames(const vector<int>& frames, int page, bool isHit) {
    cout << (isHit ? "HIT: " : "MISS: ") << page << " | Frames: ";
    for (int f : frames) {
        cout << f << " ";
    }
    cout << endl;
}
