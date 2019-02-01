//q780
//(x,y)->(x+y,y) or (x,x+y)
//given(sx,sy), determine if (tx,ty) is reachable from (sx,sy)
//codinates are non negative
/*
	observe that if tx > ty then (tx,ty) is from (ty-tx,ty)
	this is very similar to eucildean algorithm 
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx > tx || sy > ty)return false;
        if((tx-sx) % ty == 0 && ty == sy)return true;
        if((ty-sy) % tx == 0 && tx == sx)return true;
        return reachingPoints(sx,sy,tx%ty,ty%tx);
    }
};