#ifndef PRECOMP
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#endif // !PRECOMP

#include "App.h"
#include "Frame.h"

bool App::OnInit() {
  if (!wxApp::OnInit())
    return false;

  Frame* const frame = new Frame(_T("Minimal wxWidgets"));

  frame->Show(true);

  return true;
}

IMPLEMENT_APP(App)
