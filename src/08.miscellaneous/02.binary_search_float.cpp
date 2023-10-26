double sqrtnWithBinSearch(double a, int n) {
	double l = 0, r = a;
	for (int _ = 0; _ < 200; _++) {
		double mid = (r + l) / 2;
		if (pow(mid, n) > a) {
			r = mid;
		}
		else  l = mid;
	}
	return l;
}
