#include "src/cpp/Dock/dock_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
    DockWrap::init(env, exports);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
