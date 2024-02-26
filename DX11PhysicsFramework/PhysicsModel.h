#pragma once

#include "Transform.h"
#include "Collider.h"
//#include "Vector3.h"

//class Vector3;

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _netforce;

public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);

	void AddForce(Vector3 force);
	Vector3 GravityForce();
	Vector3 DragForce();
	Vector3 FrictionForce();
	bool _simulateGravity = false;

	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }
	void SetAcceleration(Vector3 acceleration) { _acceleration = acceleration; }

	void ApplyImpulse(Vector3 impulse);

private:
	Vector3 _acceleration;
	float _mass = 1.0f;
	float _gravity = 9.81;
};

