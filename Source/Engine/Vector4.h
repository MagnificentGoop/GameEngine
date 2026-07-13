#pragma once
#include "Vector3.h"
namespace bad {
	template<typename T>
	struct Vector4 {
		static_assert(std::is_arithmetic_v<T>,
			"Vector4<T> requires T to be a numeric type.");

		union {
			struct { T x; T y; T z; T w; }; //"position" in a loose sense
			struct { T r; T g; T b; T a; }; //color
		};

		Vector4<T>(T x = 0, T y = 0, T z = 0, T w = 0) : x{ x }, y{ y }, z{ z }, w{ w } {};
		Vector4<T>(const Vector2<T>* v, T z = 0, T w = 0) : Vector4(v->x, v->y, z, w) {};
		Vector4<T>(const Vector3<T>* v, T w = 0) : Vector4(v->x, v->y, v->z, w) {};
		Vector4<T>(const Vector4<T>* v) : x{ v->x }, y{ v->y }, z{ v->z }, w{ v->w } {};

		void SetValues(T x, T y, T z, T w = 0);

		Vector4 operator + (const Vector4<T>& v) const { return Vector4<T>(this->r + v.r, this->g + v.g, this->b + v.b, this->a + v.a); }
		Vector4 operator - (const Vector4<T>& v) const { return Vector4<T>(this->r - v.r, this->g - v.g, this->b - v.b, this->a - v.a); }
		Vector4 operator * (const Vector4<T>& v) const { return Vector4<T>(this->r * v.r, this->g * v.g, this->b * v.b, this->a * v.a); }
		Vector4 operator / (const Vector4<T>& v) const { return Vector4<T>(this->r / v.r, this->g / v.g, this->b / v.b, this->a / v.a); }

		Vector4 operator + (const T& i) const { return Vector4(this->r + i, this->g + i, this->b + i, this->a + i); }
		Vector4 operator - (const T& i) const { return Vector4(this->r - i, this->g - i, this->b - i, this->a - i); }
		Vector4 operator * (const T& i) const { return Vector4(this->r * i, this->g * i, this->b * i, this->a * i); }
		Vector4 operator / (const T& i) const { return Vector4(this->r / i, this->g / i, this->b / i, this->a / i); }

		Vector4& operator += (const Vector4<T>& v) { this->x += v.x; this->y += v.y; this->b += v.b; this->a += v.a; return *this; }
		Vector4& operator -= (const Vector4<T>& v) { this->x -= v.x; this->y -= v.y; this->b -= v.b; this->a -= v.a; return *this; }
		Vector4& operator *= (const Vector4<T>& v) { this->x *= v.x; this->y *= v.y; this->b *= v.b; this->a *= v.a; return *this; }
		Vector4& operator /= (const Vector4<T>& v) { this->x /= v.x; this->y /= v.y; this->b /= v.b; this->a /= v.a; return *this; }

		Vector4& operator += (const T& i) { this->x += i; this->y += i; this->b += i; this->a += i; return *this; }
		Vector4& operator -= (const T& i) { this->x -= i; this->y -= i; this->b -= i; this->a -= i; return *this; }
		Vector4& operator *= (const T& i) { this->x *= i; this->y *= i; this->b *= i; this->a *= i; return *this; }
		Vector4& operator /= (const T& i) { this->x /= i; this->y /= i; this->b /= i; this->a /= i; return *this; }

		bool operator==(const Vector4<T>& v) const { return (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w); }

		template<typename U>
		explicit operator Vector4<U>() const { return Vector4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w)); }
	};
}