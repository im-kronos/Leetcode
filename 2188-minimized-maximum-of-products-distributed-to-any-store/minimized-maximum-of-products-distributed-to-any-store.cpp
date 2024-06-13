class Solution {
public:
    bool possible(vector<int> &q,int n, int mid){
        int ind=0;
        while(ind<q.size()){
            int num= (q[ind]+mid-1)/mid;
            if(n>=num){
                n-=num;
            }
            else{
               return false;
            }
            ind++;
        }

        return true;;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,r= *max_element(quantities.begin(),quantities.end()),mid;

        while(l<r){
            mid= (l+r)/2 ;
            if(possible(quantities,n,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return r;
    }
};