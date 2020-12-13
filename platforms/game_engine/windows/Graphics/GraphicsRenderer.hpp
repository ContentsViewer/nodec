#pragma once

#include "Graphics.hpp"
#include "GraphicsResources.hpp"

#include <nodec_modules/rendering/interfaces/renderer.hpp>

#include <DirectXMath.h>
#include <unordered_map>

class GraphicsRenderer
{
public:
    struct ModelConstants
    {
        DirectX::XMFLOAT4X4 MVP;
    };

public:
    GraphicsRenderer() = default;
    void Render(Graphics* graphics, GraphicsResources* resources);

public:
    std::unordered_map<
        nodec::NodecObject::ID,
        nodec::NodecObject::Reference<nodec_modules::rendering::interfaces::Renderer>>
        renderers;

private:
    void BindMesh(nodec_modules::rendering::interfaces::Mesh* mesh, Graphics* graphics, GraphicsResources* resources);

private:
    NODEC_DISABLE_COPY(GraphicsRenderer);

};