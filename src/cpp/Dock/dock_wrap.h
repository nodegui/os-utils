#pragma once
#include <napi.h>
#include <stdlib.h>
#include "dock.h"

class DockWrap : public  Napi::ObjectWrap<DockWrap>{
 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  DockWrap(const Napi::CallbackInfo& info);
  ~DockWrap();
  static Napi::FunctionReference constructor;
};


namespace DockWrapStatic {
Napi::Value show(const Napi::CallbackInfo& info);
Napi::Value hide(const Napi::CallbackInfo& info);
}