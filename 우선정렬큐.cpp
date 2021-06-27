struct cmp{
    bool operator()(int A, int B){
        return A > B;
    }
};

priority_queue <int, vector<int>, cmp> pq;
