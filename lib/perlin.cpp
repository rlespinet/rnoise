#include "perlin.hpp"

#include <random>

#include "vec.hpp"
#include "ndarray.hpp"

inline float fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

template<typename T>
inline float lerp(T &x, T &y, float t) {
    return x * (1.0 - t) + y * t;
}

float* perlin_generate(uint width, uint height, uint nx, uint ny) {

    // Initialize random
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(-1.0, 1.0);

    // Generate the grid !
    ndarray<vec2f, 2> grid(nx + 1, ny + 1);
    for (uint i = 0; i < grid.size(); i++) {
        float x = dis(gen);
        float y = dis(gen);
        float n = std::sqrt(x * x + y * y);
        grid[i] = {x / n, y / n};
    }

    float *array = new float[width * height];
    if (array == NULL) {
        return NULL;
    }

    for (uint y = 0; y < height; y++) {
        for (uint x = 0; x < width; x++) {

            // float dx = s_cast<float>(x) / width  * nx;
            // float dy = s_cast<float>(y) / height * ny;

            // uint ix = dx - static_cast<uint>(dx);
            // uint iy = dy - static_cast<uint>(dy);

            // dx -= static_cast<float>(ix);
            // dy -= static_cast<float>(iy);

            float fx, fy;
            float dx = std::modf(static_cast<float>(x) / width  * nx, &fx);
            float dy = std::modf(static_cast<float>(y) / height * ny, &fy);

            uint ix = static_cast<uint>(fx);
            uint iy = static_cast<uint>(fy);

            float n00 = dot({dx - 0, dy - 0}, grid(ix + 0, iy + 0));
            float n10 = dot({dx - 1, dy - 0}, grid(ix + 1, iy + 0));
            float n01 = dot({dx - 0, dy - 1}, grid(ix + 0, iy + 1));
            float n11 = dot({dx - 1, dy - 1}, grid(ix + 1, iy + 1));

            float tx = fade(dx);
            float ty = fade(dy);

            float w0 = lerp(n00, n10, tx);
            float w1 = lerp(n01, n11, tx);

            float w = lerp(w0, w1, ty);

            array[width * y + x] = w;

        }
    }

    return array;

}
