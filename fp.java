// Hanbo Ye

public class fp {

    public int add(int a, int b) {

        int aS, aE, aF;
        int bS, bE, bF;
        int cS, cE, cF;

        aS = (a >> 31) & 1;
        bS = (b >> 31) & 1;

        aE = (a >> 23) & 255;
        bE = (b >> 23) & 255;

        aF = a & 0x7FFFFF;
        bF = b & 0x7FFFFF;

        if (aE == 0) {
            return b;
        }
        if (bE == 0) {
            return a;
        }

        if (aE == 0b11111111) {
            return Float.floatToIntBits(Float.NaN);
        }
        if (bE == 0b11111111) {
            return Float.floatToIntBits(Float.NaN);
        }

        if (a == Float.floatToIntBits(Float.POSITIVE_INFINITY)
                && b == Float.floatToIntBits(Float.POSITIVE_INFINITY)) {
            return Float.floatToIntBits(Float.POSITIVE_INFINITY);
        }
        if (a == Float.floatToIntBits(Float.POSITIVE_INFINITY)
                && b == Float.floatToIntBits(Float.NEGATIVE_INFINITY)) {
            return Float.floatToIntBits(Float.NaN);
        }
        if (a == Float.floatToIntBits(Float.NEGATIVE_INFINITY)
                && b == Float.floatToIntBits(Float.POSITIVE_INFINITY)) {
            return Float.floatToIntBits(Float.NaN);
        }
        if (a == Float.floatToIntBits(Float.NEGATIVE_INFINITY)
                && b == Float.floatToIntBits(Float.NEGATIVE_INFINITY)) {
            return Float.floatToIntBits(Float.NEGATIVE_INFINITY);
        }

        aF += 0x800000;
        bF += 0x800000;
        aF = aF >> (bE - aE);
        aE = bE;

        if (aS == bS) {
            cF = aF + bF;
        } else {
            cF = Math.abs(aF - bF);
        }

        if (aF > bF) {
            cS = aS;
        } else {
            cS = bS;
        }

        int shAmt = 8 - Integer.numberOfLeadingZeros(cF);

        if (shAmt < 0) {
            cF = cF << Math.abs(shAmt);
        } else {
            cF = cF >> shAmt;
        }

        cF -= 0x800000;
        cE = aE + shAmt;

        int c = cF;
        c += cE << 23;
        c += cS << 31;

        return c;
    }

    public int mul(int a, int b) {

        int aS, aE, aF;
        int bS, bE, bF;
        long cS, cE, cF;

        aS = (a >> 31) & 1;
        bS = (b >> 31) & 1;

        aE = (a >> 23) & 255; 
        bE = (b >> 23) & 255; 

        aF = a & 0X7FFFFF;
        bF = b & 0X7FFFFF;

        if (aE == 0) {            
            return a;
        }
        if (bE == 0) {
            return b;
        }

        if (aE == 0b11111111) {
            return Float.floatToIntBits(Float.NaN);
        }
        if (bE == 0b11111111) {
            return Float.floatToIntBits(Float.NaN);
        }

        if (a == Float.floatToIntBits(Float.POSITIVE_INFINITY)
                && b == Float.floatToIntBits(Float.POSITIVE_INFINITY)) {
            return Float.floatToIntBits(Float.POSITIVE_INFINITY);
        }
        if (a == Float.floatToIntBits(Float.POSITIVE_INFINITY)
                && b == Float.floatToIntBits(Float.NEGATIVE_INFINITY)) {
            return Float.floatToIntBits(Float.NaN);
        }
        if (a == Float.floatToIntBits(Float.NEGATIVE_INFINITY)
                && b == Float.floatToIntBits(Float.POSITIVE_INFINITY)) {
            return Float.floatToIntBits(Float.NaN);
        }
        if (a == Float.floatToIntBits(Float.NEGATIVE_INFINITY)
                && b == Float.floatToIntBits(Float.NEGATIVE_INFINITY)) {
            return Float.floatToIntBits(Float.NEGATIVE_INFINITY);
        }

        aF += 0x800000;
        bF += 0x800000;
        cS = aS ^ bS;
        cE = aE + bE - 127;
        cF = aF * bF;

        if (aS == bS) {
            cF = aF + bF;
        } else {
            cF = Math.abs(aF - bF);
        }

        if (Long.highestOneBit(cF) ==(long) Math.pow(2, 47)) {
            cF = cF >> 1;
            cE++;
        }

        cF = cF >> 24;

        int c = (int) (cF & 0x7FFFFF);
        c += cE << 23;
        c += cS << 31;

        return c;
    }

}
