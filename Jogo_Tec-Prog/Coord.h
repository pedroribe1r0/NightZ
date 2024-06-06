#pragma once
#include <iostream>
using namespace std;

namespace Math {
	template <typename TL>
	class Coord
	{
	public:
		TL x;
		TL y;
	public:
		Coord(TL x = 0, TL y = 0);
		~Coord() {}
		void operator=(Coord<TL> aux);
		void operator+=(Coord<TL> aux);
		void operator-=(Coord<TL> aux);
		void operator/=(Coord<TL> aux);
		void operator*=(Coord<TL> aux);
		void operator*=(float aux);
		void operator/=(float aux);

		Coord<TL> operator+(Coord<TL> aux);
		Coord<TL> operator-(Coord<TL> aux);
		Coord<TL> operator*(Coord<TL> aux);
		Coord<TL> operator*(float aux);
		Coord<TL> operator/(Coord<TL> aux);
		Coord<TL> operator/(float aux);

	};

	typedef Coord<int> CoordI;
	typedef Coord<float> CoordF;
	typedef Coord<double> CoordD;
	typedef Coord<unsigned int> CoordU;

	template <typename TL>
	Coord<TL>::Coord(TL x, TL y) {
		this->x = x;
		this->y = y;
	}

	//operadores
	template <typename TL>
	void Coord<TL>::operator=(Coord<TL> aux) {
		x = aux.x;
		y = aux.y;
	}

	template <typename TL>
	void Coord<TL>::operator*=(Coord<TL> aux) {
		x *= aux.x;
		y *= aux.y;
	}

	template <typename TL>
	void Coord<TL>::operator+=(Coord<TL> aux) {
		x += aux.x;
		y += aux.y;
	}

	template <typename TL>
	void Coord<TL>::operator-=(Coord<TL> aux) {
		x -= aux.x;
		y -= aux.y;
	}

	template <typename TL>
	void Coord<TL>::operator*=(float aux) {
		x *= aux;
		y *= aux;
	}

	template <typename TL>
	void Coord<TL>::operator/=(Coord<TL> aux) {
		x /= aux.x;
		y /= aux.y;
	}

	template <typename TL>
	void Coord<TL>::operator/=(float aux) {
		x /= aux;
		y /= aux;
	}

	template <typename TL>
	Coord<TL> Coord<TL>::operator+(Coord<TL> aux) {
		Coord<TL> t;
		t.x = x + aux.x;
		t.y = y + aux.y;

		return t;
	}

	template <typename TL>
	Coord<TL> Coord<TL>::operator-(Coord<TL> aux) {
		Coord<TL> t;
		t.x = x - aux.x;
		t.y = y - aux.y;

		return t;
	}

	template <typename TL>
	Coord<TL> Coord<TL>::operator*(Coord<TL> aux) {
		Coord<TL> t;
		t.x = x * aux.x;
		t.y = y * aux.y;

		return t;
	}

	template <typename TL>
	Coord<TL> Coord<TL>::operator*(float aux) {
		Coord<TL> t;
		t.x = x * aux;
		t.y = y * aux;

		return t;
	}

	template <typename TL>
	Coord<TL> Coord<TL>::operator/(Coord<TL> aux) {
		Coord<TL> t;
		t.x = x / aux.x;
		t.y = y / aux.y;

		return t;
	}

	template <typename TL>
	Coord<TL> Coord<TL>::operator/(float aux) {
		Coord<TL> t;
		t.x = x / aux;
		t.y = y / aux;

		return t;
	}
};

