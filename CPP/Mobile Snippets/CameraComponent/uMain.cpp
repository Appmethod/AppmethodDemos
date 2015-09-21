//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "uMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TCameraComponentForm *CameraComponentForm;
//---------------------------------------------------------------------------
__fastcall TCameraComponentForm::TCameraComponentForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCameraComponentForm::btnStartCameraClick(TObject *Sender)
{
	// Turn on the Camera
	CameraComponent->Active = True;
	tbControl->TabIndex = 1;
}
//---------------------------------------------------------------------------
void __fastcall TCameraComponentForm::GetImage()
{
	CameraComponent->SampleBufferToBitmap(imgCameraView->Bitmap, true);
}
void __fastcall TCameraComponentForm::btnStopCameraClick(TObject *Sender)
{
//  Turn off the Camera
	CameraComponent->Active = false;
	tbControl->TabIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnFrontCameraClick(TObject *Sender)
{
	bool LActive = CameraComponent->Active;
	CameraComponent->Active = false;
	// Select Front Camera
	CameraComponent->Kind = TCameraKind::FrontCamera;
	CameraComponent->Active = LActive;
	FillResolutions();
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnBackCameraClick(TObject *Sender)
{
	bool LActive = CameraComponent->Active;
	CameraComponent->Active = false;
	// Select Back Camera
	CameraComponent->Kind = TCameraKind::BackCamera;
	CameraComponent->Active = LActive;
	FillResolutions();
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::FormCreate(TObject *Sender)
{
	IFMXApplicationEventService *AppEventSvc;
	// Fill the resolutions.
	FillResolutions();
	// Add platform service to see camera state. This is nedded to enable or disable the camera when the application
	// goes to background.
	if (TPlatformServices::Current->SupportsPlatformService(__uuidof(IFMXApplicationEventService), &AppEventSvc))
		AppEventSvc->SetApplicationEventHandler(AppEvent);
}
//---------------------------------------------------------------------------

void TCameraComponentForm::FillResolutions()
{
	System::DynamicArray<TVideoCaptureSetting> LSettings = CameraComponent->AvailableCaptureSettings;
	cbResolutions->Clear();
	for (int i = LSettings.Low; i <= LSettings.High; i++)
		cbResolutions->Items->Add(UnicodeString(LSettings[i].Width) + " x " + LSettings[i].Height + " x " + LSettings[i].FrameRate);
	cbResolutions->ItemIndex = 0;
}
//---------------------------------------------------------------------------

bool __fastcall TCameraComponentForm::AppEvent(TApplicationEvent AAppEvent, System::TObject* AContext)
{
	switch (AAppEvent) {
		case TApplicationEvent::WillBecomeInactive:
		case TApplicationEvent::EnteredBackground:
		case TApplicationEvent::WillTerminate:
			CameraComponent->Active = false;
			return true;
			break;
	}
	return false;
}
//---------------------------------------------------------------------------

void TCameraComponentForm::ChangeQuality(const TVideoCaptureQuality ANewQuality)
{
	bool LActive = CameraComponent->Active;
	CameraComponent->Active = False;
	CameraComponent->Quality = ANewQuality;
	CameraComponent->Active = LActive;
	ShowCurrentResolution();
}
//---------------------------------------------------------------------------

void TCameraComponentForm::ShowCurrentResolution()
{
	TVideoCaptureSetting LSettings;
	UnicodeString LText;
	switch (CameraComponent->Quality) {
		case TVideoCaptureQuality::PhotoQuality:
			LText = "Photo";
		break;
		case TVideoCaptureQuality::HighQuality:
			LText = "High";
		break;
		case TVideoCaptureQuality::MediumQuality:
			LText = "Medium";
		break;
		case TVideoCaptureQuality::LowQuality:
			LText = "Low";
		break;
		case TVideoCaptureQuality::CaptureSettings:
			LText = "Custom";
		break;
	}
	LSettings = CameraComponent->CaptureSetting;
	lblCurrentResolution->Text = LText + " - " + LSettings.Width + "x" + LSettings.Height + " at " + LSettings.FrameRate + " FPS.";
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::cbResolutionsChange(TObject *Sender)
{
	int LIndex;
	DynamicArray<TVideoCaptureSetting> LSettings;
	bool LActive = CameraComponent->Active;
	CameraComponent->Active = False;
	LIndex = cbResolutions->ItemIndex;
	LSettings = CameraComponent->AvailableCaptureSettings;
	if (LSettings.Length > 0)
		CameraComponent->CaptureSetting = LSettings[LIndex];
	CameraComponent->Active = LActive;
	ShowCurrentResolution();
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::cbPriorityChange(TObject *Sender)
{
	if (lbiResolution->IsSelected)
		CameraComponent->CaptureSettingPriority = TVideoCaptureSettingPriority::Resolution;
	if (lbiFrameRate->IsSelected)
		CameraComponent->CaptureSettingPriority = TVideoCaptureSettingPriority::FrameRate;
	FillResolutions();
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnLowQualityClick(TObject *Sender)
{
	ChangeQuality(TVideoCaptureQuality::LowQuality);
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnMediumQualityClick(TObject *Sender)
{
	ChangeQuality(TVideoCaptureQuality::MediumQuality);
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnHighQualityClick(TObject *Sender)
{
	ChangeQuality(TVideoCaptureQuality::HighQuality);
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnPhotoQualityClick(TObject *Sender)
{
	ChangeQuality(TVideoCaptureQuality::PhotoQuality);
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnOnClick(TObject *Sender)
{
	 bool LActive;
	 // Turn on the Torch, if supported
	 if (CameraComponent->HasTorch) {
		LActive = CameraComponent->Active;
		CameraComponent->Active = false;
		CameraComponent->TorchMode = TTorchMode::ModeOn;
		CameraComponent->Active = LActive;		
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnOffClick(TObject *Sender)
{
	 bool LActive;
	 // Turn off the Torch, if supported
	 if (CameraComponent->HasTorch) {
		LActive = CameraComponent->Active;
		CameraComponent->Active = false;
		CameraComponent->TorchMode = TTorchMode::ModeOff;
		CameraComponent->Active = LActive;		
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::btnAutoClick(TObject *Sender)
{
	 bool LActive;
	 // Turn on automatic Torch, if supported
	 if (CameraComponent->HasTorch) {
		LActive = CameraComponent->Active;
		CameraComponent->Active = false;
		CameraComponent->TorchMode = TTorchMode::ModeAuto;
		CameraComponent->Active = LActive;		
	 }
}
//---------------------------------------------------------------------------

void __fastcall TCameraComponentForm::CameraComponentSampleBufferReady(TObject *Sender, const TMediaTime ATime)
{
	TThread::Synchronize(TThread::CurrentThread, GetImage);
}
//---------------------------------------------------------------------------

