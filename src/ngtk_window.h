#ifndef NGTK_WINDOW_H_
#define NGTK_WINDOW_H_

#include "ngtk_container.h"

namespace ngtk {

#define NGTK_WINDOW_DEFAULT_WIDTH  640
#define NGTK_WINDOW_DEFAULT_HEIGHT 480

class Window : public Container {
public:
  static void    SetPrototypeMethods (v8::Handle<v8::FunctionTemplate> constructor_template);
  static void    Initialize          (v8::Handle<v8::Object> target);
  static Window* New                 (void); // public constructor
  static bool    HasInstance         (v8::Handle<v8::Value> val);

private:
  static v8::Persistent<v8::FunctionTemplate> constructor_template;

  static v8::Handle<v8::Value> New            (const v8::Arguments &args);
  static v8::Handle<v8::Value> Add            (const v8::Arguments &args);
  // gtk_window_*_title()
  static v8::Handle<v8::Value> SetTitle       (const v8::Arguments &args);
  static v8::Handle<v8::Value> GetTitle       (const v8::Arguments &args);
  // gtk_window_*_resizable()
  static v8::Handle<v8::Value> SetResizable   (const v8::Arguments &args);
  static v8::Handle<v8::Value> GetResizable   (const v8::Arguments &args);
  // gtk_window_set_default_size() gtk_window_get_size()
  static v8::Handle<v8::Value> SetDefaultSize (const v8::Arguments &args);
  static v8::Handle<v8::Value> GetSize        (const v8::Arguments &args);
  // gtk_window_*_position()
  static v8::Handle<v8::Value> SetPosition    (const v8::Arguments &args);
  static v8::Handle<v8::Value> GetPosition    (const v8::Arguments &args);
  // gtk_window_*_opacity()
  static v8::Handle<v8::Value> SetOpacity     (const v8::Arguments &args);
  static v8::Handle<v8::Value> GetOpacity     (const v8::Arguments &args);
  // So we can ref and unref from ev
  static v8::Handle<v8::Value> Show           (const v8::Arguments &args);
  static void                  onDestroy      (GtkWidget *widget);

  Window(void);
};

} // namespace ngtk

#endif
