#include "GameObject.h"

GameObject::GameObject(string type, Transform* transform, Appearance* appearance, PhysicsModel* physicsModel) : _type(type), _transform(transform), _appearance(appearance)
{
	_parent = nullptr;

	_textureRV = nullptr;

	_physicsModel = new PhysicsModel(_transform);
}

GameObject::~GameObject()
{
	_parent = nullptr;
	_textureRV = nullptr;
}

void GameObject::Update(float dt)
{
	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}

	_physicsModel->Update(dt);
	_transform->Update(dt);
}

void GameObject::Move(XMFLOAT3 direction)
{
	XMFLOAT3 _position = _transform->GetPosition();

	_position.x += direction.x;
	_position.y += direction.y;
	_position.z += direction.z;
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
