class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // double m1 = (p1[1] - p2[1])/(p1[0]-p2[0]);
        // double 
        set<int> s;
        int dis1 = (pow((p1[1]-p2[1]),2) + pow((p1[0]-p2[0]),2));
        int dis2 = (pow((p2[1]-p3[1]),2) + pow((p2[0]-p3[0]),2));
        int dis3 = (pow((p3[1]-p4[1]),2) + pow((p3[0]-p4[0]),2));
        int dis4 = (pow((p1[1]-p4[1]),2) + pow((p1[0]-p4[0]),2));
        
        s.insert(dis1);
        s.insert(dis2);
        s.insert(dis3);
        s.insert(dis4);
        
        int dis5 = (pow((p1[1]-p3[1]),2) + pow((p1[0]-p3[0]),2));
        s.insert(dis5);
        
        int dis6  = (pow((p2[1]-p4[1]),2) + pow((p2[0]-p4[0]),2));
        s.insert(dis6);
        return s.size() == 2 && s.count(0) <= 0;
    }
};