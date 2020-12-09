#include <nodec_modules/game_engine/game_engine_module.hpp>

#include <nodec/logging.hpp>

namespace nodec_modules
{
    namespace game_engine
    {
        GameEngineModule::GameEngineModule() :
            GameEngine("nodec_modules::game_engine::GameEngineModule")
        {
            keyboard_module_ = nodec::NodecObject::instanciate<input::KeyboardModule>();
            mouse_module_ = nodec::NodecObject::instanciate<input::MouseModule>();
            rendering_module_ = nodec::NodecObject::instanciate<rendering::RenderingModule>();

            engine_time_stopwatch_.reset();
            engine_time_stopwatch_.start();

            nodec::logging::InfoStream(__FILE__, __LINE__) 
                << "[nodec_modules::game_engine::GameEngineModule] >>>\n"
                << "Successfully start up.\n"
                << "engine_time: " << std::chrono::duration<float>(engine_time_stopwatch_.lap()).count() << "[s]"
                << std::flush;
        }

        // === interface ===
        input::interfaces::Keyboard& GameEngineModule::keyboard() const noexcept
        {
            return (*keyboard_module_);
        }

        input::interfaces::Mouse& GameEngineModule::mouse() const noexcept
        {
            return (*mouse_module_);
        }

        rendering::interfaces::Rendering& GameEngineModule::rendering() const noexcept
        {
            return (*rendering_module_);
        }


        float GameEngineModule::engine_time() const noexcept 
        {
            return std::chrono::duration<float>(engine_time_stopwatch_.elapsed()).count();
        }

        // End interface ===


        input::KeyboardModule& GameEngineModule::keyboard_module() const noexcept
        {
            return (*keyboard_module_);
        }

        input::MouseModule& GameEngineModule::mouse_module() const noexcept
        {
            return (*mouse_module_);
        }

        rendering::RenderingModule& GameEngineModule::rendering_module() const noexcept
        {
            return (*rendering_module_);
        }


        nodec::Stopwatch<std::chrono::steady_clock>& GameEngineModule::engine_time_stopwatch()  noexcept
        {
            return (engine_time_stopwatch_);
        }

    }
}