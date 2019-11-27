#include "info_wrap.h"

Napi::FunctionReference InfoWrap::constructor;

Napi::Object InfoWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "Info";
  Napi::Function func = DefineClass(env, CLASSNAME, {
    StaticMethod("isDarkMode", &InfoWrapStatic::isDarkMode),
  });
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}


InfoWrap::InfoWrap(const Napi::CallbackInfo& info): Napi::ObjectWrap<InfoWrap>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}

Napi::Value InfoWrapStatic::isDarkMode(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  bool isDarkMode = Info::isDarkMode();
  return Napi::Value::From(env, isDarkMode);
}


