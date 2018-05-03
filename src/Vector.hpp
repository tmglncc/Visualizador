#pragma once

#include <string>

class Vector3 {
public:

	float x, y, z;

	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 operator+(const Vector3& v) {
		return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
	}

	Vector3 operator-(const Vector3& v) {
		return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
	}

	Vector3 operator+(const float c) {
		return Vector3(this->x + c, this->y + c, this->z + c);
	}

	Vector3 operator-(const float c) {
		return Vector3(this->x - c, this->y - c, this->z - c);
	}

	void operator+=(const Vector3& v) {
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	void operator-=(const Vector3& v) {
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
	}

	void operator+=(const float c) {
		this->x += c;
		this->y += c;
		this->z += c;
	}

	void operator-=(const float c) {
		this->x -= c;
		this->y -= c;
		this->z -= c;
	}

	Vector3 operator*(const Vector3& v) {
		return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
	}

	Vector3 operator/(const Vector3& v) {
		return Vector3(this->x / v.x, this->y / v.y, this->z / v.z);
	}

	Vector3 operator*(const float c) {
		return Vector3(this->x * c, this->y * c, this->z * c);
	}

	Vector3 operator/(const float c) {
		return Vector3(this->x / c, this->y / c, this->z / c);
	}

	void operator*=(const Vector3& v) {
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
	}

	void operator/=(const Vector3& v) {
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
	}

	void operator*=(const float c) {
		this->x *= c;
		this->y *= c;
		this->z *= c;
	}

	void operator/=(const float c) {
		this->x /= c;
		this->y /= c;
		this->z /= c;
	}

	bool operator==(const Vector3& vec)
	{
		return this->x == vec.x && this->y == vec.y && this->z == vec.z;
	}

	bool operator!=(const Vector3& vec)
	{
		return !(this->x == vec.x && this->y == vec.y && this->z == vec.z);
	}

	std::string to_string() {
		return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ")";
	}
};
