#include <nodec_modules/rendering/interfaces/material.hpp>
#include <nodec_modules/rendering/interfaces/rendering.hpp>

namespace nodec_modules
{
namespace rendering
{
namespace interfaces
{

Material::Material(Rendering* target_rendering,
                   nodec::NodecObject::Holder<Shader> shader) :
    BindableResource(target_rendering, "Material"),
    shader_(shader)
{
}

Material::~Material()
{
    target_rendering->unbind_material(this);
}

const Shader& 
Material::shader() const noexcept
{
    return *shader_;
}


const std::map<std::string, float>&
Material::float_properties() const
{
    return float_properties_;
}
bool Material::set_float(const std::string& name, const float& value)
{
    return set_value_generic(float_properties_, name, value);
}

bool Material::get_float(const std::string& name, float& out)
{
    return get_value_generic(float_properties_, name, out);
}


const std::map<std::string, nodec::Vector4f>& 
Material::vector4_properties() const
{
    return vector4_properties_;
}
bool Material::set_vector4(const std::string& name, const nodec::Vector4f& value)
{
    return set_value_generic(vector4_properties_, name, value);
}
bool Material::get_vector4(const std::string& name, nodec::Vector4f& out)
{
    return get_value_generic(vector4_properties_, name, out);
}

template<typename T>
bool Material::get_value_generic(std::map<std::string, T>& properties, const std::string& name, T& out)
{
    auto iter = properties.find(name);
    if (iter == properties.end())
    {
        return false;
    }

    out = iter->second;
    return true;
}


template<typename T>
bool Material::set_value_generic(std::map<std::string, T>& properties, const std::string& name, const T& value)
{
    auto iter = properties.find(name);
    if (iter == properties.end())
    {
        return false;
    }

    iter->second = value;
    return true;
}

} // namespace interfaces
} // namespace rendering
} // namespace nodec_modules