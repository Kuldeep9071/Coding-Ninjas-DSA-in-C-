#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        int min=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int i=0;
        int n=pq.size();
        while(i<n){
            if(2*i+2<n){
                if(pq[i]>pq[2*i+1] || pq[i]>pq[2*i+2]){
                    if(pq[2*i+1]<pq[2*i+2]){
                        swap(pq[i],pq[2*i+1]);
                        i=2*i+1;
                    }
                    else{
                        swap(pq[i],pq[2*i+2]);
                        i=2*i+2;
                    }
                }
                else{
                    return min;
                }
            }
            else if(2*i+1<n){
                if(pq[2*i+1]<pq[i]){
                    swap(pq[i],pq[2*i+1]);
                    i=2*i+1;
                }
                else{
                    return min;
                }
            }
            else return min;
        }
    }
};
