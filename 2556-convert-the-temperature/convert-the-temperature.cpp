class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>arr;
        double f=(celsius*1.80)+32;
        double k=celsius+273.15;
       arr.push_back(k);
       arr.push_back(f);
        return arr;
        
    }
};