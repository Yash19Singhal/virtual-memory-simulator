#include "fifo.h"
#include "utils.h"
#include <algorithm>

FIFO::FIFO(int f) {
    frames = f;
}

int FIFO::simulate(vector<int> pages) {
    int faults = 0;
    memory.clear();
    queue<int> empty; swap(q, empty);

    for (int page : pages) {
        bool fault = false;
        if (find(memory.begin(), memory.end(), page) == memory.end()) {
            faults++;
            fault = true;
            if (memory.size() < frames) {
                memory.push_back(page);
                q.push(page);
            } else {
                int victim = q.front(); q.pop();
                auto it = find(memory.begin(), memory.end(), victim);
                *it = page;
                q.push(page);
            }
        }
        printFrames(memory, page, fault);
    }
    return faults;
}
