#include <iostream>
using namespace std;

int main() {
    char str[] = {'a','a','b','c'};
    int n = 4;

    int freq[256] = {0};
    char queue[100];
    int front = 0, rear = -1;
    
    cout << "Output: ";
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        freq[ch]++;
        queue[++rear] = ch;

        // remove repeating chars from front
        while (front <= rear && freq[queue[front]] > 1) {
            front++;
        }

        if (front <= rear)
            cout << queue[front] << " ";
        else
            cout << -1 << " ";
    }
    return 0;
}
