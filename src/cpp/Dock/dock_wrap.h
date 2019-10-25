#pragma once
#include <napi.h>
#include <stdlib.h>
#include "dock.hpp"

class DockWrap : public  Napi::ObjectWrap<DockWrap>{
 private:
  std::unique_ptr<Dock> instance;
 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  DockWrap(const Napi::CallbackInfo& info);
  ~DockWrap();
  Dock* getInternalInstance();
  static Napi::FunctionReference constructor;
  //wrapped methods
  Napi::Value show(const Napi::CallbackInfo& info);
  Napi::Value hide(const Napi::CallbackInfo& info);
};

