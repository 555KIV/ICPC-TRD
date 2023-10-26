double phi = 1 + (1 + sqrt(5)) / 2;
// continuous ternary search
double cont_ternary_search(double l, double r)
{
    double m1 = l + (r - l) / phi, m2 = r - (r - l) / phi;
    double f1 = f(m1), f2 = f(m2);
    int count = 200;
    while (count--) {
        if (f1 < f2)    {
            r = m2;
            m2 = m1;
            f2 = f1;
            m1 = l + (r - l) / phi;
            f1 = f(m1);
        }
        else {
            l = m1;
            m1 = m2;
            f1 = f2;
            m2 = r - (r - l) / phi;
            f2 = f(m2);
        }
    }
    return f((l + r) / 2);
}
// discrete ternary search
double discr_ternary_search(int l, int r)   {
    int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    while (r - l > 2)   {
        if (f(m1) < f(m2))
            r = m2;
        else
            l = m1;
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
    }
    return min(f(l), min(f(l + 1), f(r)));
}