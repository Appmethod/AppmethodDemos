//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("NotesAdapterModuleU.cpp", NotesAdapterModule); /* TDataModule: File Type */
USEFORM("NotesClientFormU.cpp", NotesClientForm);
USEFORM("NotesClientModuleU.cpp", NotesClientModule); /* TDataModule: File Type */
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TNotesClientForm), &NotesClientForm);
		Application->CreateForm(__classid(TNotesAdapterModule), &NotesAdapterModule);
		Application->CreateForm(__classid(TNotesClientModule), &NotesClientModule);
		Application->Run();
	}
	catch (System::Sysutils::Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw System::Sysutils::Exception("");
		}
		catch (System::Sysutils::Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
