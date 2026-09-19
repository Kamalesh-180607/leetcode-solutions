class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Closest point of rectangle to circle center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Distance from center to that point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        // Compare distance² with radius²
        return dx * dx + dy * dy <= radius * radius;
    }
};