//---------------------------------------------------------------------------

#ifndef NoteTypesUH
#define NoteTypesUH

#include <System.JSON.hpp>
#include <vector>
//---------------------------------------------------------------------------

struct TNote : public TObject {
private:
	String FTitle;
	String FContent;
	String FID;
public:
	__fastcall TNote(void){}
	__fastcall TNote(const String& ATitle, const String &AContent);
	__fastcall TNote(const String &ATitle, const String &AContent, const String &AID);
	__property String Title = {read=FTitle, write=FTitle};
	__property String Content = {read=FContent, write=FContent};
	__property String ID = {read=FID, write=FID};

};

class TNoteJSON {
public:
	struct TNames {
		static String Title;
		static String Content;
		static String Id;
	};
public:
	static TNote* __fastcall JSONToNote(const TJSONValue * AJSON);
	static std::vector<TNote*> __fastcall JSONToNotes(const TJSONArray * AJSON);
	static TJSONArray * __fastcall NotesToJSON(std::vector<TNote*> *ANotes);
	static TJSONObject* __fastcall NoteToJSON(const TNote *ANote);
};

#endif
