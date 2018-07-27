#pragma once

#include "common.hpp"

struct vec2 {
	union {
		struct {
			float x;
			float y;
		};
		struct {
			float u;
			float v;
		};
		float E[2];
	};
	inline vec2& operator*=(float f);
	inline vec2& operator/=(float f);

	/* Vector operations */
	inline vec2& operator+=(const vec2& v);
	inline vec2& operator-=(const vec2& v);

};

inline vec2 operator+(const vec2& v1, const vec2& v2);
inline vec2 operator-(const vec2& v1, const vec2& v2);
inline float operator*(const vec2& v1, const vec2& v2);

inline vec2 operator*(const vec2& v, float f);
inline vec2 operator*(float f, const vec2& v);
inline vec2 operator/(const vec2& v, float f);

inline float dot(const vec2& v1, const vec2& v2);

inline float sqnorm(const vec2& v);
inline float sqdist(const vec2& v1, const vec2& v2);

inline float norm(const vec2& v);
inline float dist(const vec2& v1, const vec2& v2);

inline vec2 normalize(const vec2 &v);
inline vec2 reflect(const vec2& v);

/* vec2 implementation */

inline vec2& vec2::operator*=(float f) {
	this->x *= f;
	this->y *= f;
	return *this;
}

inline vec2& vec2::operator/=(float f) {
	this->x /= f;
	this->y /= f;
	return *this;
}
inline vec2& vec2::operator+=(const vec2& o) {
	this->x += o.x;
	this->y += o.y;
	return *this;
}
inline vec2& vec2::operator-=(const vec2& o) {
	this->x -= o.x;
	this->y -= o.y;
	return *this;
}

inline vec2 operator+(const vec2& v1, const vec2& v2) {
	vec2 result = v1;
	result += v2;
	return result;
}

inline vec2 operator-(const vec2& v1, const vec2& v2) {
	vec2 result = v1;
	result -= v2;
	return result;
}

inline float dot(const vec2& v1, const vec2& v2) {
	float result =
		v1.x * v2.x +
		v1.y * v2.y;
	return result;
}

inline float sqnorm(const vec2& v) {
	return dot(v, v);
}

inline float sqdist(const vec2& v1, const vec2& v2) {
	vec2 sub = v1 - v2;
	return dot(sub, sub);
}

inline float norm(const vec2& v) {
	float sq = sqnorm(v);
	return sqrtf(sq);
}

inline float dist(const vec2& v1, const vec2& v2) {
	float sq = sqdist(v1, v2);
	return sqrtf(sq);
}

inline vec2 normalize(const vec2 &v) {
	float l = norm(v);
	return v / l;
}

inline vec2 reflect(const vec2& v, const vec2& n) {
	return v - 2.0f * dot(v, n) * n;
}

inline float operator*(const vec2& v1, const vec2& v2) {
	return dot(v1, v2);
}

inline vec2 operator*(const vec2& v, float f) {
	vec2 result = v;
	result *= f;
	return result;
}

inline vec2 operator*(float f, const vec2& v) {
	return v * f;
}

inline vec2 operator/(const vec2& v, float f) {
	vec2 result = v;
	result /= f;
	return result;
}
