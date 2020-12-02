#pragma once

#include <nodec/nodec_exception.hpp>
#include <nodec/macros.hpp>

#include <Windows.h>
#include <d3d11.h>
#include <wrl.h>

class Graphics
{
public:
    class Exception : public nodec::NodecException
    {
        using NodecException::NodecException;
    };

    class HrException : public Exception
    {
    public:
        HrException(HRESULT hr, const char* file, size_t line) noexcept;
        const char* type() const noexcept override { return "Graphics::HrException"; }

    };

public:
    Graphics(HWND hWnd, int width, int height);
    ~Graphics();

private:
    UINT width;
    UINT height;
    Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
    Microsoft::WRL::ComPtr<IDXGISwapChain> pSwap;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;

private:
    NODEC_DISABLE_COPY(Graphics);
};