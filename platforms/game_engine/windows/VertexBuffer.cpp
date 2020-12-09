#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(Graphics* pGfx, UINT sizeBytes, UINT strideBytes, void* pSysMem):
    sizeBytes(sizeBytes),
    strideBytes(strideBytes)
{
    D3D11_BUFFER_DESC bd = {};
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.Usage = D3D11_USAGE_DEFAULT;
    bd.CPUAccessFlags = 0u;
    bd.MiscFlags = 0u;
    bd.ByteWidth = sizeBytes;
    bd.StructureByteStride = strideBytes;
    D3D11_SUBRESOURCE_DATA sd = {};
    sd.pSysMem = pSysMem;
    pGfx->ThrowIfError(
        pGfx->GetDevice()->CreateBuffer(&bd, &sd, &pVertexBuffer),
        __FILE__, __LINE__);
}