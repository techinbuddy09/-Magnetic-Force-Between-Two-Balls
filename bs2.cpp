class Solution {
public:
    
    // no making function of casespossible 
    int casepossible(int mid_force,vector<int>position,int m)
    {
        // means here ball is placed at 1 (0th) index
        int previous_pos=position[0];// previous position where u have kept the ball
        int count=1; // means one ball is already placed
        // no the loop to iterate for placing the next two baals
        for(int i=1;i<position.size();i++)
        {
            int current_pos=position[i]; // means storing the current position of the ball at 1st index
            if(current_pos-previous_pos >=mid_force) // if the ball palced at currenr position is greater 
            {
                count++; // if current-previos>=mid then c++ means suppose  4-1=3>=3 
                previous_pos=current_pos;// now 5the previous position will become the current position
                
            }
            if(count==m)
            {
                break; // if count of balls == m then break
            }
        }
   return  count ==m;// return the count when count of balls==m
    }
    int maxDistance(vector<int>& position, int m) {
        int len=position.size();// storing the size of the array
        sort(position.begin(),position.end());// sorting the array since checking in number line
        int min_f=1;//minimum force setting at one(low)
        int max_f=(position[len-1]-position[0]);// maximum force is the difference between start and end
        int ans=0;//to store the minimum force
        // now applying Binary Search
        while(min_f<=max_f)
        {
            int mid_f=min_f+(max_f-min_f)/2;// storing the mid value the force
            if(casepossible(mid_f,position,m)) // if suppose case possible 
            {
                ans=mid_f;// ans will take up the value of mid
                // low =mid+
                min_f=mid_f+1;// we will increase this
                
            }
            else // if not possible the decrease the high mid-1
            {
                max_f=mid_f-1;
            }
        }
        // return final ans
        return ans;
        
    }
};
