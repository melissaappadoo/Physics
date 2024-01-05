#pragma once

#include <directxmath.h>
#include <d3d11_1.h>

using namespace DirectX;

struct Geometry
{
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* indexBuffer;
	int numberOfIndices;

	UINT vertexBufferStride;
	UINT vertexBufferOffset;
};

struct Material
{
	XMFLOAT4 diffuse;
	XMFLOAT4 ambient;
	XMFLOAT4 specular;
};

class Appearance
{
private:
	Geometry _geometry;
	Material _material;

	ID3D11ShaderResourceView* _textureRV = nullptr;
public:
	// Rendering information
	Appearance(Geometry geometry, Material material);
	~Appearance();
	Geometry GetGeometryData() const { return _geometry; }
	Material GetMaterial() const { return _material; }

	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* const* GetTextureRV() { return &_textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }
};

