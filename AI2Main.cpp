/***************************************************************
 * Name:      AI2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   2014-08-16
 * Copyright: Gizmo ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "AI2Main.h"
#include <wx/msgdlg.h>
#include <termios.h>
#include <fcntl.h>
int fd; //Port to operate on
int PORT; //To be set by scPortNumber
//(*InternalHeaders(AI2Frame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(AI2Frame)
const long AI2Frame::ID_STATICTEXT2 = wxNewId();
const long AI2Frame::ID_SPINCTRL1 = wxNewId();
const long AI2Frame::ID_TOGGLEBUTTON1 = wxNewId();
const long AI2Frame::ID_BUTTON1 = wxNewId();
const long AI2Frame::ID_BUTTON2 = wxNewId();
const long AI2Frame::ID_STATICTEXT1 = wxNewId();
const long AI2Frame::ID_PANEL1 = wxNewId();
const long AI2Frame::idMenuQuit = wxNewId();
const long AI2Frame::idMenuAbout = wxNewId();
const long AI2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AI2Frame,wxFrame)
    //(*EventTable(AI2Frame)
    //*)
END_EVENT_TABLE()

AI2Frame::AI2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(AI2Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    lblPortNumber = new wxStaticText(Panel1, ID_STATICTEXT2, _("Port Number:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(lblPortNumber, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    scPortNumber = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(50,27), 0, 0, 9, 0, _T("ID_SPINCTRL1"));
    scPortNumber->SetValue(_T("0"));
    FlexGridSizer1->Add(scPortNumber, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnTogglePort = new wxToggleButton(Panel1, ID_TOGGLEBUTTON1, _("Closed"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    FlexGridSizer1->Add(btnTogglePort, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnTest1 = new wxButton(Panel1, ID_BUTTON1, _("Test1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer1->Add(btnTest1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnTest2 = new wxButton(Panel1, ID_BUTTON2, _("Test2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer1->Add(btnTest2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lblResponse = new wxStaticText(Panel1, ID_STATICTEXT1, _("Not Yet Implemented"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(lblResponse, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_SPINCTRL1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&AI2Frame::OnscPortNumberChange);
    Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&AI2Frame::OnbtnTogglePortToggle);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AI2Frame::OnbtnTest1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AI2Frame::OnbtnTest2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AI2Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AI2Frame::OnAbout);
    //*)
}

AI2Frame::~AI2Frame()
{
    //(*Destroy(AI2Frame)
    //*)
}

void AI2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void AI2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void transmit(std::string buffer)
{

    char message[buffer.size()+1]; //+1 to contain buffer + a null terminating char
    strncpy(message, buffer.c_str(), sizeof(message));
    message[sizeof(message) - 1] = 0; // forces the last character to have a null termination
    write(fd, &message, sizeof(message));//-1 = fail
}
void AI2Frame::OnbtnTogglePortToggle(wxCommandEvent& event)
{
    if(btnTogglePort->GetValue() == 1)
    {
        btnTogglePort->SetLabel(wxT("Open"));
        char chPortName[13]="/dev/ttyACM0";
        sprintf(chPortName, "/dev/ttyACM%i", PORT);

        int fd = open(chPortName, O_RDWR | O_NOCTTY | O_NDELAY);

        struct termios config;

        if(tcgetattr(fd, &config) < 0)
        {
            //  cout << "tcgetattr: fd < 0";
        }

        config.c_iflag  &= ~(IGNBRK | BRKINT  | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);
        //~(Turn off processing | Convert break to null byte | No CR->NL | No NL->CR | Ignore Parity Errors | Dont strip high bit | no flow control);
        config.c_oflag = 0;
        config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
        config.c_cflag &= ~(CSIZE | PARENB);
        config.c_cflag  |= CS8;
        config.c_cc[VMIN] = 1;
        config.c_cc[VTIME] = 0;
        if(cfsetispeed(&config, B9600)  < 0 || cfsetospeed(&config, B9600) < 0)
        {
            //  cout << "Problem setting Baud to 9600";
        }
        if(tcsetattr(fd, TCSAFLUSH, &config) < 0)
        {
            //  cout << "Problem setting attributes to fd";
        }
    }
    if(btnTogglePort->GetValue() == 0)
    {
        btnTogglePort->SetLabel(wxT("Closed"));
        close(fd);
    }
}

void AI2Frame::OnscPortNumberChange(wxSpinEvent& event)
{
    btnTogglePort->SetValue(0);
    btnTogglePort->SetLabel(wxT("Closed"));
    close(fd);
PORT = scPortNumber->GetValue();
}

void AI2Frame::OnbtnTest1Click(wxCommandEvent& event)
{
    std::string data = "12345";
    transmit(data);
}

void AI2Frame::OnbtnTest2Click(wxCommandEvent& event)
{
    transmit("12346");
}
