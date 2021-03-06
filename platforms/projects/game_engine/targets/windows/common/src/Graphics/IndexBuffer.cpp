#include "Graphics/IndexBuffer.hpp"

IndexBuffer::IndexBuffer(Graphics* pGraphics, UINT size, const void* pSysMem)
{
    D3D11_BUFFER_DESC ibd ={};
    ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
    ibd.Usage = D3D11_USAGE_DEFAULT;
    ibd.CPUAccessFlags - 0u;
    ibd.MiscFlags = 0u;
    ibd.ByteWidth = size * sizeof(uint16_t);
    ibd.StructureByteStride = sizeof(uint16_t);
    D3D11_SUBRESOURCE_DATA isd ={};
    isd.pSysMem = pSysMem;
    
    pGraphics->ThrowIfError(
        pGraphics->GetDevice()->CreateBuffer(&ibd, &isd, &pIndexBuffer),
        __FILE__, __LINE__
    );
}

void IndexBuffer::Bind(Graphics* pGraphics)
{
    pGraphics->GetInfoLogger()->SetLatest();
    pGraphics->GetContext()->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0u);
    pGraphics->GetInfoLogger()->DumpIfAny(nodec::logging::Level::Warn);

}