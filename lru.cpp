#include "lru.h"
#include "utils.h"

LRU::LRU(int f) {
    frames = f;
}

int LRU::simulate(vector<int> pages) {
    int faults = 0;
    memory.clear();
    pos.clear();

    for (int page : pages) {
        bool fault = false;
        if (pos.find(page) == pos.end()) {
            faults++;
            fault = true;
            if ((int)memory.size() == frames) {
                int victim = memory.back();
                memory.pop_back();
                pos.erase(victim);
            }
        } else {
            memory.erase(pos[page]);
        }
        memory.push_front(page);
        pos[page] = memory.begin();
        printFrames(vector<int>(memory.begin(), memory.end()), page, fault);
    }
    return faults;
}
