#include "Projection.h"

Projection::Projection(float vfov, float aspectRatio, float zNear, float zFar) :
	m_projectionMatrix(Matrix4x4()),
	m_vfov(vfov),
	m_aspectRatio(aspectRatio),
	m_zNear(zNear),
	m_zFar(zFar)
{
	CalculateMatrix();
}

float Projection::GetAspectRatio() const
{
	return m_aspectRatio;
}

Matrix4x4 Projection::GetProjectionMatrix() const
{
	return m_projectionMatrix;
}

float Projection::GetVerticalFOV() const
{
	return m_vfov;
}

float Projection::GetZFar() const
{
	return m_zFar;
}

float Projection::GetZNear() const
{
	return m_zNear;
}

void Projection::SetAspectRatio(float aspectRatio)
{
	m_aspectRatio = aspectRatio;
	CalculateMatrix();
}

void Projection::SetVerticalFOV(float vfov)
{
	m_vfov = vfov;
	CalculateMatrix();
}

void Projection::SetZFar(float zFar)
{
	m_zFar = zFar;
	CalculateMatrix();
}

void Projection::SetZNear(float zNear)
{
	m_zNear = zNear;
	CalculateMatrix();
}

void Projection::CalculateMatrix()
{
	m_projectionMatrix = Matrix4x4::Perspective(m_vfov, m_aspectRatio, m_zNear, m_zFar);
}
