//---------------------------------------------------------------------------

#ifndef NotesAdapterModuleUH
#define NotesAdapterModuleUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <System.Generics.Collections.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include "NoteTypesU.h"
//---------------------------------------------------------------------------

class TNoteWrapper : public TObject {
private:
	TNote * FNote;
	inline String __fastcall GetContent(void){ return FNote->Content;}
	inline String __fastcall GetID(void) { return FNote->ID;}
	inline String __fastcall GetTitle(void) { return FNote->Title;}
	inline void __fastcall SetContent(const String & AValue) { FNote->Content = AValue;}
	inline void __fastcall SetTitle(const String & AValue) { FNote->Title = AValue;}
public:
	__fastcall TNoteWrapper(TNote * ANote) : FNote(ANote){}
	inline TNote * __fastcall GetNote(void) { return FNote;}
	inline void __fastcall SetID(const String & AID) { FNote->ID = AID;}
	__property String Title = {read=GetTitle, write=SetTitle};
	__property String Content = {read=GetContent, write=SetContent};
	__property String ID = {read=GetID};
};

class TNotesAdapterModule : public TDataModule
{
__published:	// IDE-managed Components
private:	// User declarations
	TListBindSourceAdapter * FBindSourceAdapter;
	void __fastcall AfterPost(TBindSourceAdapter * Sender);
	void __fastcall BeforeDelete(TBindSourceAdapter * Sender);
public:		// User declarations
	__fastcall TNotesAdapterModule(TComponent* Owner);
	TBindSourceAdapter* __fastcall GetBindSourceAdapter(void);
	void __fastcall UpdateAdapter(std::vector<TNote*> *ANotes);
	void __fastcall RefreshAdapter(void);
	__property TBindSourceAdapter *BindSourceAdapter = {read=GetBindSourceAdapter};
};
//---------------------------------------------------------------------------
extern PACKAGE TNotesAdapterModule *NotesAdapterModule;
//---------------------------------------------------------------------------
#endif
