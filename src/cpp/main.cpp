#include "src/cpp/Dock/dock_wrap.h"
#include "src/cpp/AboutPanel/about_panel_wrap.h"
#include "src/cpp/Info/info_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
    DockWrap::init(env, exports);
    AboutPanelWrap::init(env, exports);
    InfoWrap::init(env, exports);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
