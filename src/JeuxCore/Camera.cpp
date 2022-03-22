#include "Camera.h"

Camera::Camera()
{
	this->position.x = 0;
	this->position.y = 0;
    this->horizon = 13.5;
	this->direction = 0;
}
Camera::Point Camera::transformPoint(Point& p) {
		Point ret;
		ret.x = this->position.x + p.x * cosf(this->direction * M_PI / 180.f) - p.y * sinf(this->direction * M_PI / 180.f);
		ret.y = this->position.y + p.y * cosf(this->direction * M_PI / 180.f) + p.x * sinf(this->direction * M_PI / 180.f);
		return ret;
}
void Camera::update() {
		this->znear = this->horizon;
		this->near.a.x = -this->znear;
		this->near.a.y = this->znear;
		this->near.a = this->transformPoint(this->near.a);

		this->near.b.x = this->znear;
		this->near.b.y = this->znear;
		this->near.b = this->transformPoint(this->near.b);

		this->zfar = this->horizon * 20;

		this->far.a.x = -this->zfar;
		this->far.a.y = this->zfar;
		this->far.a = this->transformPoint(this->far.a);

		this->far.b.x = this->zfar;
		this->far.b.y = this->zfar;
		this->far.b = this->transformPoint(this->far.b);
}

Camera::Line Camera::getProjected(float v) {
	Line ret;
	float in = 1.f / this->znear;
	float ifar = 1.f / this->zfar;
	float iz = in + v * (ifar - in);
	ret.a.x = this->near.a.x * in + v * (this->far.a.x * ifar - this->near.a.x * in);
	ret.a.y = this->near.a.y * in + v * (this->far.a.y * ifar - this->near.a.y * in);

	ret.b.x = this->near.b.x * in + v * (this->far.b.x * ifar - this->near.b.x * in);
	ret.b.y = this->near.b.y * in + v * (this->far.b.y * ifar - this->near.b.y * in);

	ret.a.x /= iz;
	ret.b.x /= iz;
	ret.a.y /= iz;
	ret.b.y /= iz;
	return ret;
}

Camera::IPoint Camera::getTexCoords(float u, Line& line, int larg, int haut) {
	Point inter;
	inter.x = line.a.x + u * (line.b.x - line.a.x);
	inter.y = line.a.y + u * (line.b.y - line.a.y);

	IPoint ret;
	ret.x = inter.x;
	ret.y = -inter.y;

	ret.x = (larg + (ret.x % larg)) % larg;
	ret.y = (haut + (ret.y % haut)) % haut;

	return ret;
}
void Camera::re_init(){
	this->position.x = 0;
	this->position.y = 0;
    this->horizon = 13.5;
	this->direction = 0;

}

float Camera::getPositionX() const { return position.x; }
void Camera::setPositionX(float px) { this->position.x = position.x + px; }

float Camera::getPositionY() const { return this->position.y; }
void Camera::setPositionY(float py) { this->position.y = this->position.y + py; }

float Camera::getHorizon() const { return horizon; }
void Camera::setHorizon(float hori) { horizon = horizon + hori; }

float Camera::getDirection() const { return direction; }
void Camera::setDirection(float direc) { direction = direction + direc; }

