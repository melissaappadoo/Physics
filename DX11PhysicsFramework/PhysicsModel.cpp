#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{
	_transform = transform;
}

void PhysicsModel::Update(float deltaTime)
{
	_acceleration.x += _netforce.x / _mass;
	_acceleration.y += _netforce.y / _mass;
	_acceleration.z += _netforce.z / _mass;

	XMFLOAT3 position = _transform->GetPosition();
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_velocity.z += _acceleration.z * deltaTime;
	position.x += _velocity.x * deltaTime;
	position.y += _velocity.y * deltaTime;
	position.z += _velocity.z * deltaTime;
	_transform->SetPosition(position);

	_netforce = XMFLOAT3(0, 0, 0);
	_acceleration = XMFLOAT3(0, 0, 0);
}

void PhysicsModel::AddForce(XMFLOAT3 force)
{
	_netforce.x += force.x;
	_netforce.y += force.y;
	_netforce.z += force.z;
}

XMFLOAT3 PhysicsModel::GravityForce()
{
	_weight = _mass * _gravity;
	_netforce.y -= _weight;
	return _netforce;
}

void PhysicsModel::ApplyImpulse(XMFLOAT3 impulse)
{
	_velocity.x += impulse.x;
	_velocity.y += impulse.y;
	_velocity.z += impulse.z;
}
