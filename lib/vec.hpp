#pragma once

#include "common.hpp"

template<typename T, uint D>
struct vec {

    T E[D];

    inline vec& operator*=(T f);
    inline vec& operator/=(T f);

    /* Vector operations */
    inline vec& operator+=(const vec& v);
    inline vec& operator-=(const vec& v);

};

template<typename T, uint D> inline vec<T, D> operator+(const vec<T, D>& v1, const vec<T, D>& v2);
template<typename T, uint D> inline vec<T, D> operator-(const vec<T, D>& v1, const vec<T, D>& v2);
template<typename T, uint D> inline T operator*(const vec<T, D>& v1, const vec<T, D>& v2);

template<typename T, uint D> inline vec<T, D> operator*(const vec<T, D>& v, T f);
template<typename T, uint D> inline vec<T, D> operator*(T f, const vec<T, D>& v);
template<typename T, uint D> inline vec<T, D> operator/(const vec<T, D>& v, T f);

template<typename T, uint D> inline T dot(const vec<T, D>& v1, const vec<T, D>& v2);

template<typename T, uint D> inline T sqnorm(const vec<T, D>& v);
template<typename T, uint D> inline T sqdist(const vec<T, D>& v1, const vec<T, D>& v2);

template<typename T, uint D> inline T norm(const vec<T, D>& v);
template<typename T, uint D> inline T dist(const vec<T, D>& v1, const vec<T, D>& v2);

template<typename T, uint D> inline vec<T, D> normalize(const vec<T, D> &v);
template<typename T, uint D> inline vec<T, D> reflect(const vec<T, D>& v);

/* vec<T, D> implementation */

template<typename T, uint D>
inline vec<T, D>& vec<T, D>::operator*=(T f) {
    for (uint i = 0; i < D; i++) {
        E[i] *= f;
    }
    return *this;
}

template<typename T, uint D>
inline vec<T, D>& vec<T, D>::operator/=(T f) {
    for (uint i = 0; i < D; i++) {
        E[i] /= f;
    }
    return *this;
}
template<typename T, uint D>
inline vec<T, D>& vec<T, D>::operator+=(const vec<T, D>& o) {
    for (uint i = 0; i < D; i++) {
        E[i] += o.E[i];
    }
    return *this;
}
template<typename T, uint D>
inline vec<T, D>& vec<T, D>::operator-=(const vec<T, D>& o) {
    for (uint i = 0; i < D; i++) {
        E[i] -= o.E[i];
    }
    return *this;
}

template<typename T, uint D>
inline vec<T, D> operator+(const vec<T, D>& v1, const vec<T, D>& v2) {
    vec<T, D> result = v1;
    result += v2;
    return result;
}

template<typename T, uint D>
inline vec<T, D> operator-(const vec<T, D>& v1, const vec<T, D>& v2) {
    vec<T, D> result = v1;
    result -= v2;
    return result;
}

template<typename T, uint D>
inline T dot(const vec<T, D>& v1, const vec<T, D>& v2) {

    T result = 0.0;
    for (uint i = 0; i < D; i++) {
        result += v1.E[i] * v2.E[i];
    }

    return result;
}

template<typename T, uint D>
inline T sqnorm(const vec<T, D>& v) {
    return dot(v, v);
}

template<typename T, uint D>
inline T sqdist(const vec<T, D>& v1, const vec<T, D>& v2) {
    vec<T, D> sub = v1 - v2;
    return dot(sub, sub);
}

template<typename T, uint D>
inline T norm(const vec<T, D>& v) {
    T sq = sqnorm(v);
    return sqrtf(sq);
}

template<typename T, uint D>
inline T dist(const vec<T, D>& v1, const vec<T, D>& v2) {
    T sq = sqdist(v1, v2);
    return sqrtf(sq);
}

template<typename T, uint D>
inline vec<T, D> normalize(const vec<T, D> &v) {
    T l = norm(v);
    return v / l;
}

template<typename T, uint D>
inline T operator*(const vec<T, D>& v1, const vec<T, D>& v2) {
    return dot(v1, v2);
}

template<typename T, uint D>
inline vec<T, D> operator*(const vec<T, D>& v, T f) {
    vec<T, D> result = v;
    result *= f;
    return result;
}

template<typename T, uint D>
inline vec<T, D> operator*(T f, const vec<T, D>& v) {
    return v * f;
}

template<typename T, uint D>
inline vec<T, D> operator/(const vec<T, D>& v, T f) {
    vec<T, D> result = v;
    result /= f;
    return result;
}

typedef vec<float, 2> vec2f;
typedef vec<float, 3> vec3f;
typedef vec<float, 4> vec4f;

typedef vec<double, 2> vec2d;
typedef vec<double, 3> vec3d;
typedef vec<double, 4> vec4d;
