#include<bits/stdc++.h>
using namespace std;

class Deque {
    private:
    int* data;
    int firstIndex;
    int Lastindex;
    int size;
    int capacity;
    public:
    Deque(int x){
        data=new int[10];
        capacity=x;
        firstIndex=-1;
        Lastindex=0;
        size=0;
    }

    void insertFront(int element)
    {
        if (size == capacity)
        {
            cout << -1 << endl;
            return;
        }
        if (size == 0)
        {
            firstIndex = 0;
            Lastindex = 1;
        }
        else
        {
            firstIndex = (((firstIndex - 1) % capacity + capacity) % capacity);
        }
        data[firstIndex] = element;
        size++;
    }

    void insertRear(int element)
    {
        if (size == capacity)
        {
            cout << -1 << endl;
            return;
        }
        data[Lastindex] = element;
        Lastindex = (Lastindex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    void deleteFront()
    {
        if (size == 0)
        {
            cout << -1 << endl;
            return;
        }
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            Lastindex = 0;
        }
    }
    
    void deleteRear()
    {
        if (size == 0)
        {
            cout << -1 << endl;
            return;
        }
        Lastindex = ((Lastindex - 1) % capacity + capacity) % capacity;
        size--;
        if (size == 0)
        {
            Lastindex = 0;
            firstIndex = -1;
        }
    }

    int getFront()
    {
        if (size == 0)
        {
            return -1;
        }
        return data[firstIndex];
    }

    int getRear()
    {
        if (size == 0)
        {
            return -1;
        }
        return data[(((Lastindex - 1) % capacity + capacity) % capacity)];
    }
};
