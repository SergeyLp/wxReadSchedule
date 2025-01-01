#pragma once

class Frame : public wxFrame {
public:
  Frame(const wxString& title);

  // event handlers (these functions should _not_ be virtual)
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnHello(wxCommandEvent& event);

private:
  DECLARE_EVENT_TABLE()
};

