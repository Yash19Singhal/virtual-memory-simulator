#include <bits/stdc++.h>
#include "fifo.h"
#include "lru.h"
#include "optimal.h"
using namespace std;

int main() {
    int frames, n;
    cout << "Enter number of frames: ";
    cin >> frames;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    FIFO fifo(frames);
    LRU lru(frames);
    Optimal opt(frames);

    cout << "\n--- Simulation Results ---\n";
    cout << "FIFO Page Faults: " << fifo.simulate(pages) << endl;
    cout << "LRU Page Faults: " << lru.simulate(pages) << endl;
    cout << "Optimal Page Faults: " << opt.simulate(pages) << endl;

    return 0;
}
