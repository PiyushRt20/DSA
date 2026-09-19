class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX;
        int closestY;
        if(x2 < xCenter){
            closestX = x2;
        }
        else if(x1 > xCenter){
            closestX = x1;
        }
        else{
            closestX = xCenter;
        }
        if(y2 < yCenter){
            closestY = y2;
        }
        else if(y1 > yCenter){
            closestY = y1;
        }
        else{
            closestY = yCenter;
        }
        int closestDis = sqrt(pow(xCenter - closestX , 2) + pow(yCenter - closestY , 2));
        cout<<closestDis;
        return closestDis <= radius;
    }
};