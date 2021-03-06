#include <nodec_modules/rendering/rendering_module.hpp>

#include <nodec/logging.hpp>

namespace nodec_modules
{
namespace rendering
{

RenderingModule::RenderingModule() :
    interfaces::Rendering("nodec_modules::rendering::RenderingModule"),
    frame_delta_time_(0)
{

}

float RenderingModule::frame_delta_time() const noexcept
{
    return frame_delta_time_;
}

void RenderingModule::bind_mesh(const interfaces::Mesh* mesh)
{
    on_bind_mesh.invoke(mesh);
}

void RenderingModule::unbind_mesh(const interfaces::Mesh* mesh)
{
    on_unbind_mesh.invoke(mesh);
}

void RenderingModule::bind_shader(const interfaces::Shader* shader)
{
    on_bind_shader.invoke(shader);
}
void RenderingModule::unbind_shader(const interfaces::Shader* shader)
{
    on_unbind_shader.invoke(shader);
}

void RenderingModule::bind_material(const interfaces::Material* material)
{
    on_bind_material.invoke(material);
}
void RenderingModule::unbind_material(const interfaces::Material* material)
{
    on_unbind_material.invoke(material);
}

void RenderingModule::bind_texture(const interfaces::Texture* texture)
{
    on_bind_texture.invoke(texture);
}
void RenderingModule::unbind_texture(const interfaces::Texture* texture)
{
    on_unbind_texture.invoke(texture);
}

void RenderingModule::register_renderer(nodec::NodecObject::Reference<interfaces::Renderer> renderer)
{
    on_register_renderer.invoke(renderer);
}

void RenderingModule::register_camera(nodec::NodecObject::Reference<interfaces::Camera> camera)
{
    on_register_camera.invoke(camera);
}

} // namespace rendering
} // namespace nodec_modules