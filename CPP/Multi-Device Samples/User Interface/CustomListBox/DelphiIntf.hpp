//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#ifndef DelphiintfHPP
#define DelphiintfHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w       // Display all warnings
#pragma option -w-inl   // Functions %s are not expanded inline
#pragma option -w-8111  // Accessing deprecated entity
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <FMX.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <FMX.Graphics.hpp>	// Pascal unit
#include <System.Rtti.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Delphiintf
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Fmx::Graphics::TBitmapCodecManager* __fastcall GetFmxCodecInstance(void);
extern DELPHI_PACKAGE System::Rtti::TValue __fastcall NotifyEventAsTValue(System::Classes::TNotifyEvent Ev);
}	/* namespace Delphiintf */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DELPHIINTF)
using namespace Delphiintf;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DelphiintfHPP
