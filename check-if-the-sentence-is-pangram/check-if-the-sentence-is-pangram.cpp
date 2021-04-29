class Solution {
public:
    bool checkIfPangram(string sentence) {
      
      int arr[26] = {0};
      
      for(char c : sentence)
      {
        arr[c-97] = 1;
      }
      
      for(int a : arr)
        if(a!=1)
          return false;
      
      return true;
        
    }
};