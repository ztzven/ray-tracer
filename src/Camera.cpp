#include "Camera.hpp"

Camera::Camera() {}

Camera::Camera(int vW, int vH): viewportWidth(vW), viewportHeight(vH) {
    origin = { 0.0, 0.0, 0.0 };
    lowerLeftCorner = { -(viewportWidth/100), -(viewportHeight/100), -(viewportHeight/100) };
    horizontal = { ((viewportWidth * 2)/100), 0.0, 0.0 };
    vertical = { 0.0, ((viewportHeight * 2)/100), 0.0 };
}

Ray Camera::getRay(float u, float v) {
    return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
