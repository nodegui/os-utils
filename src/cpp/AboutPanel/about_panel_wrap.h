#pragma once
#include <napi.h>
#include <stdlib.h>
#include "about_panel.h"

class AboutPanelWrap : public Napi::ObjectWrap<AboutPanelWrap> {
public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  AboutPanelWrap(const Napi::CallbackInfo &info);
  ~AboutPanelWrap();
  static Napi::FunctionReference constructor;
};

namespace AboutPanelWrapStatic {
  Napi::Value open(const Napi::CallbackInfo &info);
}
