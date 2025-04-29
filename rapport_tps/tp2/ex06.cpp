#include <iostream>

using namespace std;

class Point {
	public:
		int x;
		int y;

		Point(int a, int b) {
			x = a;
			y = b;
		}

		void comparer(int x, int y) {
			if (this->x < x)
				cout << x << " est plus grand que " << this->x << endl;
			else if (this->x > x)
				cout << this->x << " est plus grand que " << x << endl;
			else
				cout << this->x << " egal " << x << endl;

			if (this->y < y)
				cout << y << " est plus grand que " << this->y << endl;
			else if (this->y > y)
				cout << this->y << " est plus grand que " << y << endl;
			else
				cout << this->y << " egal " << y << endl;
		}
};

int main() {
    Point p(2, 4);
    p.comparer(5, 4);
    return 0;
}
