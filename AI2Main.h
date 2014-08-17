/***************************************************************
 * Name:      AI2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-08-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/

#ifndef AI2MAIN_H
#define AI2MAIN_H

//(*Headers(AI2Frame)
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/tglbtn.h>
#include <wx/stattext.h>
//*)

class AI2Frame: public wxFrame
{
    public:

        AI2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~AI2Frame();

    private:

        //(*Handlers(AI2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnTogglePortToggle(wxCommandEvent& event);
        void OnscPortNumberChange(wxSpinEvent& event);
        void OnbtnTest1Click(wxCommandEvent& event);
        void OnbtnTest2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(AI2Frame)
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL1;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(AI2Frame)
        wxSpinCtrl* scPortNumber;
        wxPanel* Panel1;
        wxToggleButton* btnTogglePort;
        wxButton* btnTest2;
        wxStatusBar* StatusBar1;
        wxButton* btnTest1;
        wxStaticText* lblPortNumber;
        wxStaticText* lblResponse;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AI2MAIN_H
