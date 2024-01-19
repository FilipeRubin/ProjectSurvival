#pragma once
#include "Matrix4x4.h"

class Projection
{
public:
	Projection(float vfov, float aspectRatio, float zNear, float zFar);
	float GetAspectRatio() const;
	Matrix4x4 GetProjectionMatrix() const;
	float GetVerticalFOV() const;
	float GetZFar() const;
	float GetZNear() const;
	void SetAspectRatio(float aspectRatio);
	void SetVerticalFOV(float vfov);
	void SetZFar(float zFar);
	void SetZNear(float zNear);
private:
	Matrix4x4 m_projectionMatrix;
	float m_vfov;
	float m_aspectRatio;
	float m_zNear;
	float m_zFar;
	void CalculateMatrix();
};