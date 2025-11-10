#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> heap;

    void heapifyUp(int index)
    {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;

        if (heap[parent] < heap[index])
        {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax()
    {
        if (heap.empty())
        {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMax()
    {
        if (heap.empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    void display()
    {
        cout << "Priority Queue: ";
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;
    int choice, val;

    do
    {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Delete max element\n";
        cout << "3. Display queue\n";
        cout << "4. Show max element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            pq.insert(val);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Maximum element is: " << pq.getMax() << endl;
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
