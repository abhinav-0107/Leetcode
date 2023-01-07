class DataStream {
public:
    vector<int> v;
    int k,val,count=0;
    DataStream(int value, int k) {
        this->k=k;
        val=value;
    }
    
    bool consec(int num) {
        v.push_back(num);
        
        if(num==val) count++;
        else count=0;
        
        if(v.size()<k) return false;
        else if(count>=k) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */