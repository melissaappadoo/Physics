#pragma once

#include "Transform.h"

class PhysicsModel
{
protected:
	Transform* _transform;
	XMFLOAT3 _velocity;
	XMFLOAT3 _netforce;

public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);

	void AddForce(XMFLOAT3 force);
	void SetVelocity(XMFLOAT3 velocity) { _velocity = velocity; }
	XMFLOAT3 GetVelocity() const { return _velocity; }

private:
	XMFLOAT3 _acceleration;
	float _mass = 1.0f;
};

