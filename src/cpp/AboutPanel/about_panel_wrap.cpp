#include "about_panel_wrap.h"

Napi::FunctionReference AboutPanelWrap::constructor;

Napi::Object AboutPanelWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "AboutPanel";
  Napi::Function func = DefineClass(env, CLASSNAME, {StaticMethod("open", &AboutPanelWrapStatic::open)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

AboutPanelWrap::AboutPanelWrap(const Napi::CallbackInfo &info) : Napi::ObjectWrap<AboutPanelWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}

Napi::Value AboutPanelWrapStatic::open(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  AboutPanel::options options;

  Napi::Object optionsObject = info[0].As<Napi::Object>();

  if (optionsObject.Has("name")) {
    Napi::Value nameValue = optionsObject.Get("name");
    if (nameValue.IsString()) {
      options.name = nameValue.As<Napi::String>().Utf8Value();
    }
  }

  if (optionsObject.Has("copyright"))
  {
    Napi::Value copyrightValue = optionsObject.Get("copyright");
    if (copyrightValue.IsString())
    {
      options.copyright = copyrightValue.As<Napi::String>().Utf8Value();
    }
  }

  if (optionsObject.Has("version")) {
    Napi::Value versionValue = optionsObject.Get("version");
    if (versionValue.IsString()) {
      options.version = versionValue.As<Napi::String>().Utf8Value();
    }
  }

  if (optionsObject.Has("applicationVersion")) {
    Napi::Value applicationVersionValue = optionsObject.Get("applicationVersion");
    if (applicationVersionValue.IsString()) {
      options.applicationVersion = applicationVersionValue.As<Napi::String>().Utf8Value();
    }
  }

  AboutPanel::open(options);
  return env.Null();
}
