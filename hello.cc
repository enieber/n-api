#include <iostream>
#include <napi.h>
using namespace std;

Napi::Value Add(const Napi::CallbackInfo& info){
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
      .ThrowAsJavaScriptException();
    
    return env.Null();
  }

  if (!info[0].IsNumber() || !info[1].IsNumber()) {
     Napi::TypeError::New(env, "Wrong arguments")
      .ThrowAsJavaScriptException();
    
     return env.Null(); 
  }

  double arg0 = info[0].As<Napi::Number>().DoubleValue();
  double arg1 = info[1].As<Napi::Number>().DoubleValue();
  Napi::Number num = Napi::Number::New(env, arg0 + arg1);

  return num;
}

Napi::String Say(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  
  if (info.Length() < 1) {
    return Napi::String::New(env, "world");
  }

  /*if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Wrong arguments")
      .ThrowAsJavaScriptException();
    
    return env.Null();  
  }*/

  string arg0 = info[0].As<Napi::String>();
  return Napi::String::New(env, "Hello "+arg0);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "say"), Napi::Function::New(env, Say));
  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
  return exports;
}

NODE_API_MODULE(addon, Init);
