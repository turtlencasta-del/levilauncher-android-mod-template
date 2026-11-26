#include <preload/Mod.h>
#include <preload/Logger.h>

class MyMod {
public:
    static MyMod &instance() {
        static MyMod instance;
        return instance;
    }

    MyMod() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod &getSelf() const { return mSelf; }

    bool load() {
        getSelf().getLogger().info("LumaLight mobile mod loaded successfully!");
        return true;
    }

    bool enable() {
        getSelf().getLogger().info("LumaLight graphics hook enabled!");
        // Shader and outline rendering hooks initialize here
        return true;
    }

    bool disable() {
        return true;
    }

private:
    ll::mod::NativeMod &mSelf;
};

PL_REGISTER_MOD(MyMod, MyMod::instance())
