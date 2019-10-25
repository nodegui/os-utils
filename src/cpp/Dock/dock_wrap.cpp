#include "dock_wrap.h"

Napi::FunctionReference DockWrap::constructor;

Napi::Object DockWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "Dock";
  Napi::Function func = DefineClass(env, CLASSNAME, {
    InstanceMethod("show", &DockWrap::show),
    InstanceMethod("hide", &DockWrap::hide),
  });
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

Dock* DockWrap::getInternalInstance() {
  return this->instance.get();
}

DockWrap::DockWrap(const Napi::CallbackInfo& info): Napi::ObjectWrap<DockWrap>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->instance = std::make_unique<Dock>();
}

DockWrap::~DockWrap() {
  this->instance.reset();
}

Napi::Value DockWrap::show(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  return env.Null();
}

Napi::Value DockWrap::hide(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  return env.Null();
}
