#include <iostream>

using namespace std;

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void bubblesort(vector<int> &vec1) {
    for (int i: vec1) {
        for (int b = 0; b < vec1.size(); b++) {
            if (vec1[b] > vec1[b + 1]) {
                std::swap(vec1[b], vec1[b + 1]);
            }
        }

    }
}

void insertion(vector<int> &vec1) {
    for (int i = 1; i < vec1.size(); i++) {
        if (vec1[i - 1] > vec1[i]) {
            std::swap(vec1[i - 1], vec1[i]);
            for (int b = i - 1; b != 0 && (vec1[b - 1] > vec1[b]); b--) {
                std::swap(vec1[b - 1], vec1[b]);
            }
        }
    }
}


void quicksort(std::vector<int> &vec1, unsigned int first, unsigned last) {
    unsigned int f = first;
    unsigned int l = last;
    while (vec1[first] < vec1[last]) {
        last--;
    }
    std::swap(vec1[first], vec1[last]);
    while (first != last) {
        if (first < last) {
            if (vec1[first] <= vec1[last]) {
                first++;
            } else {
                std::swap(vec1[first], vec1[last]);
                std::swap(first, last);
            }
        } else if(first>last) {
            if (vec1[first] >= vec1[last]) {
                first--;
            } else {
                std::swap(vec1[first], vec1[last]);
                std::swap(first, last);
            }
        }
    }
    if (f < last)
    {
        quicksort(vec1, f, last - 1);
    }
    if (l > last) {
        quicksort(vec1, last + 1, l);
    }
}


int main() {
    int length;
    cout << "vvedite dlinu massiva bolshe 29" << endl;
    cin >> length;
    while (length < 5) {
        cout << "vvedite drugoe shislo" << endl;
        cin >> length;
    }
    vector<int> vec1;
    srand(time(nullptr));
    for (int i = 0; i < length; ++i) {
        vec1.push_back(rand() % 501 - 250);
    }
    quicksort(vec1, 0, vec1.size() - 1);
    for (int i : vec1) {
        cout << i << endl;
    }
    return 0;
}