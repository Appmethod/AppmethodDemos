// EMS Resource Modules
//---------------------------------------------------------------------------

#ifndef NotesResourceUH
#define NotesResourceUH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.SysUtils.hpp>
#include <EMS.Services.hpp>
#include <EMS.ResourceAPI.hpp>
#include <EMS.ResourceTypes.hpp>
#include "NotesStorageU.h"
#include "NoteTypesU.h"
//---------------------------------------------------------------------------
#pragma explicit_rtti methods (public)
class TNotesResource1 : public TDataModule
{
__published:
private:
	TNotesStorage * FNotesStorage;
	void CheckNotesManager(const TEndpointContext * AContext);
	void HandleException(void);
public:
	__fastcall TNotesResource1(TComponent* Owner);
	__fastcall ~TNotesResource1(void);
	void Get(TEndpointContext* AContext, TEndpointRequest* ARequest, TEndpointResponse* AResponse);
	void GetItem(TEndpointContext* AContext, TEndpointRequest* ARequest, TEndpointResponse* AResponse);
	void Post(TEndpointContext* AContext, TEndpointRequest* ARequest, TEndpointResponse* AResponse);
	void PutItem(TEndpointContext* AContext, TEndpointRequest* ARequest, TEndpointResponse* AResponse);
	void DeleteItem(TEndpointContext* AContext, TEndpointRequest* ARequest, TEndpointResponse* AResponse);
};
#endif


