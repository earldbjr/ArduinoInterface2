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
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
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
        //*)

        //(*Identifiers(AI2Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(AI2Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // AI2MAIN_H
