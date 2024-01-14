#pragma once

#include "Transform.h"

class PhysicsModel
{
protected:
	Transform* _transform;
	XMFLOAT3 _velocity;

public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);

	void SetVelocity(XMFLOAT3 velocity) { _velocity = velocity; }
	XMFLOAT3 GetVelocity() const { return _velocity; }

private:
	float acceleration;
};

