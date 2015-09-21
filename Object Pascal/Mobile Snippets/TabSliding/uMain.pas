//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

unit uMain;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Dialogs, FMX.Objects, FMX.TabControl,
  FMX.Gestures, FMX.StdCtrls, System.Actions, FMX.ActnList,
  FMX.Controls.Presentation;

type
  TTabSlidingForm = class(TForm)
    TabControl1: TTabControl;
    TabItem1: TTabItem;
    TabItem2: TTabItem;
    Image1: TImage;
    Image2: TImage;
    GestureManager1: TGestureManager;
    ToolBar1: TToolBar;
    Label1: TLabel;
    TabActionList: TActionList;
    ChangeTabActionPrev: TChangeTabAction;
    ChangeTabActionNext: TChangeTabAction;
    procedure ChangeTabActionPrevUpdate(Sender: TObject);
    procedure FormKeyUp(Sender: TObject; var Key: Word; var KeyChar: Char;
      Shift: TShiftState);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  TabSlidingForm: TTabSlidingForm;

implementation

{$R *.fmx}
{$R *.LgXhdpiPh.fmx ANDROID}

procedure TTabSlidingForm.ChangeTabActionPrevUpdate(Sender: TObject);
begin
  if TabControl1.TabIndex < TabControl1.TabCount -1 then
    ChangeTabActionNext.Tab := TabControl1.Tabs[TabControl1.TabIndex + 1]
  else
    ChangeTabActionNext.Tab := nil;

  if TabControl1.TabIndex > 0 then
    ChangeTabActionPrev.Tab := TabControl1.Tabs[TabControl1.TabIndex - 1]
  else
    ChangeTabActionPrev.Tab := nil;
end;

{ Capture the back button; if there are tabs to the left of current,
  navigate back, otherwise "fall off." }

procedure TTabSlidingForm.FormKeyUp(Sender: TObject; var Key: Word;
  var KeyChar: Char; Shift: TShiftState);
begin
  if Key = vkHardwareBack then
  begin
    if TabControl1.TabIndex > 0 then
    begin
      TabControl1.TabIndex := TabControl1.TabIndex - 1 mod TabControl1.TabCount;
      Key := 0;
    end;
  end;
end;

end.
