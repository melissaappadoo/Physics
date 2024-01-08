#include "GameObject.h"

GameObject::GameObject(string type, Transform* transform, Appearance* appearance) : _type(type), _transform(transform), _appearance(appearance)
{
	_parent = nullptr;

	_textureRV = nullptr;

}

GameObject::~GameObject()
{
	_parent = nullptr;
	_textureRV = nullptr;
}

void GameObject::Update(float dt)
{

	//XMStoreFloat4x4(&_world, _transform->GetScale() * _transform->GetRotation() * _transform->GetPosition());

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
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
	// We are assuming that the constant buffers and all other draw setup has already taken place

	// Set vertex and index buffers
	pImmediateContext->IASetVertexBuffers(0, 1, &_appearance->GetGeometryData().vertexBuffer, &_appearance->GetGeometryData().vertexBufferStride, &_appearance->GetGeometryData().vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(_appearance->GetGeometryData().indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(_appearance->GetGeometryData().numberOfIndices, 0, 0);
}
