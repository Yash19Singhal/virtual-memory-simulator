#include "optimal.h"
#include "utils.h"
#include <algorithm>

Optimal::Optimal(int f) {
    frames = f;
}

int Optimal::simulate(vector<int> pages) {
    int faults = 0;
    memory.clear();

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];
        bool fault = false;

        if (find(memory.begin(), memory.end(), page) == memory.end()) {
            faults++;
            fault = true;
            if (memory.size() < frames) {
                memory.push_back(page);
            } else {
                int farthest = i + 1, idx = -1;
                for (int j = 0; j < memory.size(); j++) {
                    int k;
                    for (k = i + 1; k < pages.size(); k++) {
                        if (memory[j] == pages[k]) 
                        break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        idx = j;
                    }
                }
                if (idx == -1) idx = 0;
                memory[idx] = page;
            }
        }
        printFrames(memory, page, fault);
    }
    return faults;
}
