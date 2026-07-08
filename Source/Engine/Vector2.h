#pragma once
#include <cmath>
#include <type_traits>

namespace bad {
	template<typename T>

	struct Vector2 {
		static_assert(std::is_arithmetic_v<T>,
			"Vector2<T> requires T to be a numeric type.");

		T x, y;

		Vector2<T>(T x = 0, T y = 0) : x{ x }, y{ y } {};
		Vector2<T>(const Vector2<T>* v) : x{ v->x }, y{ v->y } {};

		Vector2<T> operator + (const Vector2<T>& v) const {return Vector2<T>(this->x + v.x, this->y + v.y);}
		Vector2<T> operator - (const Vector2<T>& v) const {return Vector2<T>(this->x - v.x, this->y - v.y);}
		Vector2<T> operator * (const Vector2<T>& v) const {return Vector2<T>(this->x * v.x, this->y * v.y);}
		Vector2<T> operator / (const Vector2<T>& v) const {return Vector2<T>(this->x / v.x, this->y / v.y);}

		Vector2<T> operator + (const T& i) const { return Vector2<T>(this->x + i, this->y + i); }
		Vector2<T> operator - (const T& i) const { return Vector2<T>(this->x - i, this->y - i); }
		Vector2<T> operator * (const T& i) const { return Vector2<T>(this->x * i, this->y * i); }
		Vector2<T> operator / (const T& i) const { return Vector2<T>(this->x / i, this->y / i); }

		Vector2<T>& operator += (const Vector2<T>& v) {this->x += v.x; this->y += v.y; return *this;}
		Vector2<T>& operator -= (const Vector2<T>& v) {this->x -= v.x; this->y -= v.y; return *this;}
		Vector2<T>& operator *= (const Vector2<T>& v) {this->x *= v.x; this->y *= v.y; return *this;}
		Vector2<T>& operator /= (const Vector2<T>& v) {this->x /= v.x; this->y /= v.y; return *this;}
				  
		Vector2<T>& operator += (const T& i) { this->x += i; this->y += i; return *this; }
		Vector2<T>& operator -= (const T& i) { this->x -= i; this->y -= i; return *this; }
		Vector2<T>& operator *= (const T& i) { this->x *= i; this->y *= i; return *this; }
		Vector2<T>& operator /= (const T& i) { this->x /= i; this->y /= i; return *this; }

		float LengthSqr() const { return (x * x) + (y * y); }
		float Length() const { return std::sqrt(LengthSqr()); }
	};
}