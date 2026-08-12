class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(q.empty()){
            q.push(t);
            return 1;
        }
        else{
            int margin = t-3000;
            while(!q.empty() && q.front() < margin){
                q.pop();
            }
            q.push(t);
        }
        return q.size();


    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */