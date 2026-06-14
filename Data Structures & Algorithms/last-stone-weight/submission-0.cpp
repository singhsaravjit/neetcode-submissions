class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> heapmax;

        for(int num : stones){
            heapmax.push(num);
        }

        while(heapmax.size()> 1){

            int x= heapmax.top();
            heapmax.pop();
            int y= heapmax.top();
            
            heapmax.pop();
            if(x>y){
                heapmax.push(x-y);
            }
            else if(x<y){
                heapmax.push(y-x);
            }
        }
        if(heapmax.empty())
        return 0;
        else
        return heapmax.top();
        
    }
};
