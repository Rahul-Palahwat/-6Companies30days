class StockPrice {
public:
    map<int,int> mp;
    multiset<int> st;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp) != mp.end()){
            st.erase(st.find(mp[timestamp]));
        }
        mp[timestamp]=price;
        st.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }

    int maximum() {
        return *st.rbegin();
    }

    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */