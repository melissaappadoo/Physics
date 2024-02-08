#pragma once

#include "Transform.h"
#include "Collider.h"

class PhysicsModel
{
protected:
	Transform* _transform;
	XMFLOAT3 _velocity;
	//XMFLOAT3 _acceleration;
	XMFLOAT3 _netforce;

public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);

	void AddForce(XMFLOAT3 force);
	XMFLOAT3 GravityForce();

	XMFLOAT3 GetVelocity() const { return _velocity; }
	void SetVelocity(XMFLOAT3 velocity) { _velocity = velocity; }
	void SetAcceleration(XMFLOAT3 acceleration) { _acceleration = acceleration; }

	void ApplyImpulse(XMFLOAT3 impulse);

private:
	XMFLOAT3 _acceleration;
	float _mass = 1.0f;
};

