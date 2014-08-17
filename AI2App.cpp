/***************************************************************
 * Name:      AI2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-08-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "AI2App.h"

//(*AppHeaders
#include "AI2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(AI2App);

bool AI2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	AI2Frame* Frame = new AI2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
