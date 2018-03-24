class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int O = 0, X = 0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if(board[i][j]=='O') O++;
                if(board[i][j]=='X') X++;                                
            }
        if(O>X || X-O>1) return false;                
        bool OO = false, XX = false;
        for(int i=0;i<3;i++)
        {
            if(board[i]=="OOO")
            {
                if(OO || XX) return false;
                OO = true;
            }
            if(board[i]=="XXX")
            {
                if(OO || XX) return false;
                XX = true;
            }
        }
        if(OO && X!=O) return false;
        if(XX && X==O) return false;
        OO = XX = false;
        for(int i=0;i<3;i++)
        {
            string str = "   ";
            str+=board[0][i]; str+=board[1][i]; str+=board[2][i];
            if(str=="OOO")
            {
                if(OO || XX) return false;
                OO = true;
            }
            if(str=="XXX")
            {
                if(OO || XX) return false;
                XX = true;
            }
        }
        if(OO && X!=O) return false;
        if(XX && X==O) return false;
        OO = XX = false;
        string str1; str1+=board[0][0]; str1+=board[1][1]; str1+=board[2][2];
        string str2; str2+=board[2][0]; str2+=board[1][1]; str2+=board[0][2];
        if(str1=="XXX" || str2=="XXX") XX=true;
        if(str1=="OOO" || str2=="OOO") OO=true;
        if(OO && X!=O) return false;
        if(XX && X==O) return false;
        return true;
    }
};