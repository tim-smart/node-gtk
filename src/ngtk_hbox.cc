#include "ngtk_hbox.h"

namespace ngtk {

using namespace v8;

Persistent<FunctionTemplate> Hbox::constructor_template;

// Check whether is an instance.
bool Hbox::HasInstance (Handle<Value> val) {
  HandleScope scope;

  if (val->IsObject()) {
    Local<Object> obj = val->ToObject();

    if (constructor_template->HasInstance(obj)) {
      return true;
    }
  }

  return false;
}

// Public constructor
Hbox* Hbox::New (bool homogeneous, int spacing) {
  HandleScope scope;

  Local<Value> argv[2];
  argv[0] = Local<Value>::New(Boolean::New(homogeneous));
  argv[1] = Integer::New(spacing);

  Local<Object> hbox = constructor_template->GetFunction()->NewInstance(2, argv);

  return ObjectWrap::Unwrap<Hbox>(hbox);
}

// ECMAScript constructor.
Handle<Value> Hbox::New (const Arguments &args) {
  HandleScope scope;

  gboolean homogeneous;
  gint     spacing;

  // homogeneous
  if (args[0]->IsBoolean()) {
    homogeneous = args[0]->ToBoolean()->Value();
  } else {
    homogeneous = false;
  }

  // spacing
  if (args[1]->IsNumber()) {
    spacing = args[1]->Int32Value();
  } else {
    spacing = 0;
  }

  Hbox *hbox = new Hbox(homogeneous, spacing);
  hbox->Wrap(args.This());

  return args.This();
}

Hbox::Hbox (gboolean homogeneous, gint spacing) {
  widget_ = gtk_hbox_new(homogeneous, spacing);
}

// Export.
void Hbox::SetPrototypeMethods (Handle<FunctionTemplate> constructor_template) {
  HandleScope scope;

  Box::SetPrototypeMethods(constructor_template);
}

void Hbox::Initialize (Handle<Object> target) {
  HandleScope scope;

  Local<FunctionTemplate> t = FunctionTemplate::New(Hbox::New);
  constructor_template = Persistent<FunctionTemplate>::New(t);
  constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
  constructor_template->SetClassName(String::NewSymbol("Hbox"));

  Hbox::SetPrototypeMethods(constructor_template);

  target->Set(String::NewSymbol("Hbox"), constructor_template->GetFunction());
}

} // namespace ngtk

