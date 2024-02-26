#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{
	_transform = transform;
}

void PhysicsModel::Update(float deltaTime)
{
	_acceleration += _netforce / _mass;

	Vector3 position = _transform->GetPosition();
	_velocity += _acceleration * deltaTime;
	position += _velocity * deltaTime;
	_transform->SetPosition(position);

	if (_simulateGravity)
	{
		_netforce += GravityForce();
	}

	_netforce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);
}

void PhysicsModel::AddForce(Vector3 force)
{
	_netforce += force;
}

Vector3 PhysicsModel::GravityForce()
{
	float _weight = _mass * _gravity;
	_netforce.y -= _weight;
	return _netforce;
}

Vector3 PhysicsModel::DragForce()
{
	return Vector3();
}

Vector3 PhysicsModel::FrictionForce()
{
	return Vector3();
}

void PhysicsModel::ApplyImpulse(Vector3 impulse)
{
	_velocity += impulse;
}
