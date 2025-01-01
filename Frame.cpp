#ifndef PRECOMP
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#endif // !PRECOMP
#include "Frame.h"

// IDs for the controls and the menu commands
enum {
  idHello = 1,
};

BEGIN_EVENT_TABLE(Frame, wxFrame)
  EVT_MENU(wxID_EXIT, Frame::OnQuit)
  EVT_MENU(wxID_ABOUT, Frame::OnAbout)
  EVT_MENU(idHello, Frame::OnHello)
END_EVENT_TABLE()


Frame::Frame(const wxString& title)
  : wxFrame(nullptr, wxID_ANY, title) {
  SetIcon(wxICON(sample));

#if 0 //wxUSE_MENUS
  wxMenu* const fileMenu = new wxMenu;
  fileMenu->Append(wxID_EXIT, _T("E&xit\tAlt-X"), _T("Quit this program"));

  wxMenu* const helpMenu = new wxMenu;
  helpMenu->Append(idHello, "&Hello...\tCtrl+H",
    "Help string shown in status bar for this menu item");
  helpMenu->AppendSeparator();
  helpMenu->Append(wxID_ABOUT, _T("&About...\tF1"), _T("Show about dialog"));

  wxMenuBar* const menuBar = new wxMenuBar();
  menuBar->Append(fileMenu, _T("&File"));
  menuBar->Append(helpMenu, _T("&Help"));

  SetMenuBar(menuBar);

#endif // wxUSE_MENUS

#if 0 //wxUSE_STATUSBAR
  // create a status bar just for fun (by default with 1 pane only)
  CreateStatusBar(1);
  SetStatusText(_T("Welcome to wxWidgets!"));
#endif // wxUSE_STATUSBAR
}

void Frame::OnQuit(wxCommandEvent&) {
  Close(true);
}

void Frame::OnAbout(wxCommandEvent&) {
  wxMessageBox(wxString::Format(
    _T("Welcome to %s!\n")
    _T("\n")
    _T("This is the minimal wxWidgets sample\n")
    _T("running under %s."),
    wxVERSION_STRING,
    wxGetOsDescription().c_str()
  ),
    _T("About wxWidgets minimal sample"),
    wxOK | wxICON_INFORMATION,
    this);
}

void Frame::OnHello(wxCommandEvent& /*event*/) {
  wxLogMessage("Hello world from wxWidgets!");
}

