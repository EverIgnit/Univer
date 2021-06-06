#pragma once
#pragma once
class Num {
	int a;
	int b;
public:
	Num(int a, int b) {
		this->a = a;
		this->b = b;
	}
	void func(TCHAR* str) {
		/*
		Calculate % - t=false
		/ - t=true
		*/
		int i = a+1, rest=b+1;
		if (a > 0)
			i =i*(-1)+2;
		if (b > 0)
			rest =rest*(-1)+2;
		for (; abs(i) < abs(a); i++) {
			for (int r=rest; abs(r) < abs(b); r++) {
				if (b*i + r == a) {
					if ((a <= 0 && b >= 0) || (b <= 0 && a >= 0)) {
						i++;
						r = a - b*i;
					}
						wsprintf(str, L"%d - целая часть, %d - остаток", i, r);
						return;
				}
			}
		}

		/*int i=0;
		if (a < 0) {
			if (b < 0) {
				for (; b*i <= a; 
					i++) {}
			}
			else
			for (; b*i >= a; i--) {}
		}
		else
			if (b < 0)
				for (; b*i <= a+b; i--) {}
			else
		for (; b*i <= a-b; i++) {}
		if (a < 0)
			i++;
		if (t)
			return i;
			//return a / b;
		return a - b*i;
			//return a%b;
			*/
	}
};
