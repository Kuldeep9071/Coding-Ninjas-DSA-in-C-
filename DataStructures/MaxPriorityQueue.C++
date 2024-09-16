#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    
    vector<int> pq;

   public:
    
    void insert(int element) {
        pq.push_back(element);
        int i=pq.size()-1;
        while(i>0){
            int j=(i-1)/2;
            if(pq[j]<pq[i]){
                swap(pq[i],pq[j]);
                i=j;
            }
            else break;
        }
    }

    int getMax() {
        if(pq.size()==0) return INT_MIN;
        return pq[0];
    }

    int removeMax() {
        if(pq.size()==0) return INT_MIN;
        int max=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int n=pq.size();
        int i=0;
        while(i<n){
            int maxIndex=i;
            if(2*i+1<n && pq[2*i+1]>pq[maxIndex]) maxIndex=2*i+1;
            if(2*i+2<n && pq[2*i+2]>pq[maxIndex]) maxIndex=2*i+2;
            if(i==maxIndex) break;
            else{
                swap(pq[maxIndex],pq[i]);
                i=maxIndex;
            }
        }
        return max;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {   
        return pq.size()==0;
    }
};