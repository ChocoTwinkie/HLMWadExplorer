/*
** HLMWadExplorer
**
** Copyright (C) 2015 Tobias Taschner <github@tc84.de>
**
** Licensed under GPL v3 or later
*/

#include <wx/wx.h>

#include "ExploreFrame.h"

class WADExplorerApp : public wxApp
{
public:
	virtual bool OnInit()
	{
		wxImage::AddHandler(new wxPNGHandler());
		wxImage::AddHandler(new wxJPEGHandler());
		wxImage::AddHandler(new wxGIFHandler());
		wxImage::AddHandler(new wxTGAHandler());

		SetAppName("HLMWADExplorer");
		SetAppDisplayName("HLM WAD Explorer");

		ExploreFrame* frame = new ExploreFrame(NULL);
		if (!frame->OpenBaseFile())
			return false;

		frame->Show();

		return true;
	}
};

wxIMPLEMENT_APP(WADExplorerApp);
