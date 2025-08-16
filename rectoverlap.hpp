int overlap(int Ax1, int Ay1, int Ax2, int Ay2, int Tx1, int Ty1, int Tx2, int Ty2) {
    int overlap = 0;
    // T right of A
    if (Ax1 <= Tx1 && Tx1 <= Ax2) {
        // T upper right of A
        if (Ay1 <= Ty1 && Ty1 <= Ay2) {
            int xDiff = Ax2 - Tx1;
            int yDiff = Ay2 - Ty1;
            overlap += xDiff * yDiff;
        }
        // T lower right of A
        else if ((Ax1 <= Tx2 && Tx2 <= Ax2) && (Ay1 <= Ty2 && Ty2 <= Ay2)) {
            int xDiff = Ax2 - Tx1;
            int yDiff = Ty2 - Ay1;
            overlap += xDiff * yDiff;
        }
    }
    // T left of A
    else if (Ax1 <= Tx2 && Tx2 <= Ax2) {
        // T upper left of A
        if ((Ax1 <= Tx2 && Tx2 <= Ax2) && (Ay1 <= Ty1 && Ty1 <= Ay2)) {
            int xDiff = Tx2 - Ax1;
            int yDiff = Ay2 - Ty1;
            overlap += xDiff * yDiff;
        }
        // T lower left of A
        else if ((Ax1 <= Tx2 && Tx2 <= Ax2) && (Ay1 <= Ty2 && Ty2 <= Ay2)) {
            int xDiff = Tx2 - Ax1;
            int yDiff = Ty2 - Ay1;
            overlap += xDiff * yDiff;
        }
    }
    return overlap;
}