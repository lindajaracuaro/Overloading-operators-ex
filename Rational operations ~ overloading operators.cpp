#include <iostream>

class Rational{
	 int _n = 0;	//For numerator
	 int _d = 1;	//For denominator
public:
	Rational(int numerator = 0, int denominator = 1) : _n(numerator) , _d(denominator) {};	
	Rational(const Rational& other) : _n(other._n), _d(other._d) {};		//Constructor copycat,	if the user assigns values use them instead
	~Rational();

	//Just for assignment use
	inline int numerator() const { return _n; };	
	inline int denominator() const { return _d; };

	Rational &operator=(const Rational& other);			//	Why to pass a reference of other values?	<- Creates a new rational without afecting the other
	Rational operator+ (const Rational& other) const;	//	We use const at the end for telling the program that we won't change Class definition
	Rational operator- (const Rational& other) const;
	Rational operator* (const Rational& other) const;
	Rational operator/ (const Rational& other) const;
};

Rational::~Rational() {
	std::cout << "Destroyed "<<_n << " , " << _d << "\n\n";
	_n = 0;	_d = 1;
}

Rational& Rational :: operator= (const Rational& other){		
	if (this != &other) {        //If res is the same than the values stored in other, don't do it
		_n = other.numerator();
		_d = other.denominator();
	}
	return *this;           //Why a fucking pointer?
}

Rational Rational :: operator+(const Rational& other) const {
	return Rational ((_n * other._d) + (_d * other._n), _d * other._d);
}

Rational Rational:: operator-(const Rational& other) const {
	return Rational((_n * other._d) - (_d * other._n), _d * other._d);
}

Rational Rational:: operator*(const Rational& other) const {
	return Rational(_n * other._n, _d * other._d);
}

Rational Rational:: operator/ (const Rational& other) const {
	return Rational(_n * other._d, _d * other._n);
}

// Now, we redefined operators the compiler doesn't know what to do with <<
std::ostream& operator << (std::ostream& o, const Rational& r) {
	if (r.denominator() == 1) return o << r.numerator();			// Fraction format
	else return o << r.numerator() << '/' << r.denominator();
}


int main(){
	Rational o1 = 7;
	std::cout << "Just one argument" << std::endl
		<< "A = " << o1 << std::endl;

	Rational o2(5, 3);
	std::cout << "Two arguments" << std::endl
		<< "B = " << o2 << std::endl;

	Rational o3=o2;
	std::cout << "Copying object features C = B" << std::endl
		<< "C = " << o3 << std::endl;

	Rational o4;
	std::cout << "Zero arguments \nD = " << o4 << std::endl << std::endl;

	std::cout << o1 << " + " << o2 << " = " << o1 + o2 << std::endl;
	std::cout << o1 << " - " << o2 << " = " << o1 - o2 << std::endl;
	std::cout << o1 << " * " << o2 << " = " << o1 * o2 << std::endl;
	std::cout << o1 << " / " << o2 << " = " << o1 / o2 << std::endl;

	return 0;
}