#define debug(x) cout<<#x" = "<<x<<endl;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while( tx>=sx && ty>=sy )
        {
            if( tx==sx && ty==sy ) return true;
            if(tx==ty) return false;            
            if(tx>ty) tx=(tx%ty)?(tx%ty):ty;
            else ty=(ty%tx)?(ty%tx):tx;
        }
        if(tx==sx && (sy-ty)%sx==0) return true;
        if(ty==sy && (sx-tx)%sy==0) return true;
        return false;
    }
};