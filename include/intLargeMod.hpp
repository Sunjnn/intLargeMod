#ifndef __HPP_intLargeMod__
#define __HPP_intLargeMod__

class intLargeMod {
public:
    intLargeMod(int x = -1) : _val(x) {
        _val %= _MOD;
    }
    int getVal() {return _val;}

    intLargeMod &operator+=(intLargeMod &right);
    intLargeMod &operator+=(int right);
    friend intLargeMod operator+(intLargeMod &left, intLargeMod &right);
    friend intLargeMod operator+(intLargeMod &left, int right);
    friend intLargeMod operator+(int left, intLargeMod &right);

    intLargeMod &operator*=(intLargeMod &right);
    intLargeMod &operator*=(int right);
    friend intLargeMod operator*(intLargeMod &left, intLargeMod &right);
    friend intLargeMod operator*(intLargeMod &left, int right);
    friend intLargeMod operator*(int left, intLargeMod &right);

private:
    int _val;
    static int _MOD;
};

int intLargeMod::_MOD = 1e9 + 7;

intLargeMod &intLargeMod::operator+=(intLargeMod &right) {
    _val += right._val;
    _val %= _MOD;
    return *this;
}

intLargeMod &intLargeMod::operator+=(int right) {
    intLargeMod tmp(right);
    *this += tmp;
    return *this;
}

intLargeMod operator+(intLargeMod &left, intLargeMod &right) {
    intLargeMod res(left._val);
    res += right;
    return res;
}

intLargeMod operator+(intLargeMod &left, int right) {
    intLargeMod res(right);
    res += left;
    return res;
}

intLargeMod operator+(int left, intLargeMod &right) {
    intLargeMod res(left);
    res += right;
    return res;
}

intLargeMod &intLargeMod::operator*=(intLargeMod &right) {
    int div = _MOD / _val;
    if (right._val <= div) {
        _val *= right._val;
        return *this;
    }

    ++div;
    int div1 = right._val / div;
    int rem = right._val % div;
    rem *= _val;
    _val *= div;
    _val %= _MOD;

    intLargeMod newRight(div1);
    *this *= newRight;
    *this += rem;

    return *this;
}

intLargeMod &intLargeMod::operator*=(int right) {
    intLargeMod newRight(right);
    *this *= newRight;
    return *this;
}

intLargeMod operator*(intLargeMod &left, intLargeMod &right) {
    intLargeMod res(left._val);
    res *= right;
    return res;
}

intLargeMod operator*(intLargeMod &left, int right) {
    intLargeMod res(right);
    res *= left;
    return res;
}

intLargeMod operator*(int left, intLargeMod &right) {
    intLargeMod res(left);
    res *= right;
    return res;
}

#endif