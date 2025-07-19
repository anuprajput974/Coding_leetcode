class FreqStack {
    public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int maxcount;
public:
    FreqStack() {
         maxcount=0;
        
    }
    
    void push(int val) {
        freq[val]++;
        int f=freq[val];
         maxcount=max(maxcount,f);
        group[f].push(val);


        
    }
    
    int pop() {
        int val=group[maxcount].top();
        group[maxcount].pop();
        freq[val]--;

        if(group[maxcount].empty()){
            maxcount--;
        }
        return val;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */