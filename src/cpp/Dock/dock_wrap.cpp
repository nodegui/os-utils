#include "dock_wrap.h"

Napi::FunctionReference DockWrap::constructor;

Napi::Object DockWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "Dock";
  Napi::Function func = DefineClass(env, CLASSNAME, {
    StaticMethod("show", &DockWrapStatic::show),
    StaticMethod("hide", &DockWrapStatic::hide),
  });
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}


DockWrap::DockWrap(const Napi::CallbackInfo& info): Napi::ObjectWrap<DockWrap>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}


Napi::Value DockWrapStatic::show(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  Dock::show();
  return env.Null();
}

Napi::Value DockWrapStatic::hide(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  Dock::hide();
  return env.Null();
}


