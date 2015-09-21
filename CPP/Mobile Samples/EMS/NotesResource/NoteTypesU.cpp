//---------------------------------------------------------------------------

#pragma hdrstop

#include "NoteTypesU.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

String TNoteJSON::TNames::Title = "title";
String TNoteJSON::TNames::Content = "content";
String TNoteJSON::TNames::Id = "id";

// ---------------------------------------------------------------------------
__fastcall TNote::TNote(const String &ATitle, const String &AContent):
	FTitle(ATitle), FContent(AContent)
{

}
// ---------------------------------------------------------------------------
__fastcall TNote::TNote(const String &ATitle, const String &AContent,
	const String &AID) : FID(AID), FTitle(ATitle), FContent(AContent)
{

}
// ---------------------------------------------------------------------------
TNote* __fastcall TNoteJSON::JSONToNote(const TJSONValue * AJSON)
{
	TJSONObject * obj = static_cast<TJSONObject*>(const_cast<TJSONValue*>(AJSON));
	TNote * note = new TNote(
		obj->Get(TNames::Title)->JsonValue->Value(),
		obj->Get(TNames::Content)->JsonValue->Value(),
		obj->Get(TNames::Id)->JsonValue->Value());
	return note;
}
 // ---------------------------------------------------------------------------
std::vector<TNote*> __fastcall TNoteJSON::JSONToNotes(const TJSONArray * AJSON)
{
	std::vector<TNote*> notes;
	for (int i = 0; i < const_cast<TJSONArray*>(AJSON)->Count; i++) {
		notes.push_back(TNoteJSON::JSONToNote(const_cast<TJSONArray*>(AJSON)->Items[i]));
	}
	return notes;
}
// ---------------------------------------------------------------------------
TJSONObject* __fastcall TNoteJSON::NoteToJSON(const TNote *ANote)
{
	TJSONObject * jsonObj = new TJSONObject();
	jsonObj->AddPair(TNames::Title, ANote->Title);
	jsonObj->AddPair(TNames::Content, ANote->Content);
	jsonObj->AddPair(TNames::Id, ANote->ID);
	return jsonObj;
}
// ---------------------------------------------------------------------------
TJSONArray * __fastcall TNoteJSON::NotesToJSON(std::vector<TNote*> *ANotes)
{
	TJSONArray * jsonArray = new TJSONArray();
	for(std::vector<TNote*>::iterator it = ANotes->begin(); it != ANotes->end(); it++)
	{
		jsonArray->Add(TNoteJSON::NoteToJSON(*it));
	}
	return jsonArray;
}
// ---------------------------------------------------------------------------
