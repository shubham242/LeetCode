class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         
        unordered_set <string> seen ;
        
        for(int i = 0 ;i <9 ;i++)
        {
            for (int j = 0 ;j<9 ;j++)
            { 
                if(board[i][j] != '.')
                {
                    
                    if(! seen.insert( "row" +to_string(i)+ to_string(board[i][j]) ).second || ! seen.insert( "col" + to_string(j)+ to_string(board[i][j]) ).second ||! seen.insert( "grid" + to_string((i/3)*3+(j/3))+ to_string(board[i][j]) ).second)
                    
// if this doesnt get inserted that means its being duplicated and thats why the suduko board is not valid so //return false 
        
                    
                {
                    return false ;
                }
                    
                    
                    
                    
                }
                
            }
        }
        
        
         return true;
        
        
    }
};