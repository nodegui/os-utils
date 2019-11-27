#pragma once
#include <napi.h>
#include <stdlib.h>
#include "info.h"

class InfoWrap : public  Napi::ObjectWrap<InfoWrap>{
 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  InfoWrap(const Napi::CallbackInfo& info);
  ~InfoWrap();
  static Napi::FunctionReference constructor;
};


namespace InfoWrapStatic {
Napi::Value isDarkMode(const Napi::CallbackInfo& info);
}